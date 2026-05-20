`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// obstacle_game_core
// -----------------------------------------------------------------------------
// 避障车游戏的核心逻辑模块。
//
// 这个模块不直接驱动 LED、数码管段码或蜂鸣器方波，而是输出更抽象的
// “游戏状态”：
// - obstacle_grid_o：6 列 x 3 层的障碍矩阵。
// - car_col_o      ：车子当前所在列。
// - hp_count_o     ：剩余生命值。
// - music_start_o/music_win_o：结束时通知蜂鸣器播放胜利或失败旋律。
//
// 这样做的好处是：游戏规则和硬件显示细节解耦。阅读时先理解本模块的
// 状态机，再看 sevenseg_scan 如何把 obstacle_grid_o 映射成 A/G/D 段。
// -----------------------------------------------------------------------------
module obstacle_game_core #(
    // 关卡一共生成多少批障碍。默认 20 批，生成完并全部离开画面后胜利。
    parameter int OBSTACLE_COUNT = 20,
    // LFSR 初始种子必须非 0；空闲态持续滚动，开局时机不同会得到不同障碍序列。
    parameter logic [15:0] LFSR_SEED = 16'hACE1
) (
    input  logic        clk_i,
    // 高有效同步复位。
    input  logic        rst_i,
    // 障碍下落使能脉冲。每来一拍，障碍整体向下移动一层。
    input  logic        step_tick_i,
    // 防抖后的按键按下事件，高有效单周期脉冲。
    // key_pressed_i[0] = KEY1 右移，key_pressed_i[1] = KEY2 左移。
    // key_pressed_i[2]/[3] 在 IDLE 状态下也可用于开始游戏。
    input  logic [3:0]  key_pressed_i,
    // 蜂鸣器播完整首音乐后拉高一拍，核心据此回到 IDLE。
    input  logic        melody_done_i,
    // 18 位障碍矩阵，按 col*3 + layer 打包：
    // layer 0=上层 A 段，layer 1=中层 G 段，layer 2=下层 D 段。
    output logic [17:0] obstacle_grid_o,
    // 车子所在列，范围 0~5。列号 0 表示最左侧，5 表示最右侧。
    output logic [2:0]  car_col_o,
    // 剩余生命值，初始为 4，碰撞一次减 1。
    output logic [2:0]  hp_count_o,
    // 胜利或失败刚发生时拉高一拍，启动 buzzer_player。
    output logic        music_start_o,
    // 1 表示播放胜利音乐，0 表示播放失败音乐。
    output logic        music_win_o,
    // 当前状态编码，供顶层控制车子是否显示，也便于仿真观察。
    output logic [1:0]  state_code_o,
    // 已经生成过的障碍批次数，供调试和胜利判定使用。
    output logic [4:0]  spawn_count_o
);
    // 四态 FSM：
    // IDLE 等待开始；RUN 正常游戏；WIN/LOSE 等待音乐播放完成后回到 IDLE。
    localparam logic [1:0] ST_IDLE = 2'd0;
    localparam logic [1:0] ST_RUN  = 2'd1;
    localparam logic [1:0] ST_WIN  = 2'd2;
    localparam logic [1:0] ST_LOSE = 2'd3;

    // 将参数常量截成 5 位，便于和 spawn_count_o 比较。
    // 本项目默认 20，小于 32；若未来要超过 31，需要同步放宽 spawn_count_o 位宽。
    localparam logic [4:0] OBSTACLE_COUNT_VALUE = 5'(OBSTACLE_COUNT);

    logic [1:0] state;

    // 游戏画面内部用三行 6 位表示，比直接操作 18 位矩阵更直观：
    // row_top[col]    -> 顶层障碍，对应数码管 A 段。
    // row_mid[col]    -> 中层障碍，对应数码管 G 段。
    // row_bottom[col] -> 底层障碍，对应数码管 D 段，也是碰撞检测层。
    logic [5:0] row_top;
    logic [5:0] row_mid;
    logic [5:0] row_bottom;

    // LFSR 状态用于动态刷新障碍；safe_col 记录下一批障碍强制留空的安全列。
    logic [15:0] lfsr_state;
    logic [2:0]  safe_col;

    function automatic logic [15:0] lfsr_step(input logic [15:0] value);
        logic feedback;
        begin
            feedback = value[15] ^ value[13] ^ value[12] ^ value[10];
            lfsr_step = {value[14:0], feedback};
        end
    endfunction

    function automatic logic [2:0] next_safe_col(
        input logic [2:0] current_col,
        input logic [1:0] random_choice
    );
        begin
            unique case (random_choice)
                2'b00: begin
                    if (current_col == 3'd0) begin
                        next_safe_col = 3'd1;
                    end else begin
                        next_safe_col = current_col - 1'b1;
                    end
                end

                2'b10: begin
                    if (current_col == 3'd5) begin
                        next_safe_col = 3'd4;
                    end else begin
                        next_safe_col = current_col + 1'b1;
                    end
                end

                default: next_safe_col = current_col;
            endcase
        end
    endfunction

    function automatic logic [5:0] make_obstacle_row(
        input logic [15:0] random_value,
        input logic [4:0]  row_index,
        input logic [2:0]  open_col
    );
        logic [5:0] row_value;
        int obstacle_count;
        int col;
        begin
            row_value = random_value[5:0]
                      ^ random_value[11:6]
                      ^ {1'b0, row_index};
            row_value[open_col] = 1'b0;

            obstacle_count = 0;
            for (col = 0; col < 6; col++) begin
                if (row_value[col]) begin
                    obstacle_count++;
                end
            end

            // 每行至少放 3 个障碍，但永远不填安全列，避免生成全堵死局。
            for (col = 0; col < 6; col++) begin
                if ((obstacle_count < 3) && (col != int'(open_col)) && !row_value[col]) begin
                    row_value[col] = 1'b1;
                    obstacle_count++;
                end
            end

            make_obstacle_row = row_value;
        end
    endfunction

    // 将三行 6 位矩阵打包成显示模块使用的 18 位格式。
    // 对每一列连续放 3 位，便于 sevenseg_scan 用 col_index * 3 访问。
    function automatic logic [17:0] pack_grid(
        input logic [5:0] top,
        input logic [5:0] mid,
        input logic [5:0] bottom
    );
        logic [17:0] grid_value;
        int col;
        begin
            grid_value = '0;
            for (col = 0; col < 6; col++) begin
                grid_value[col * 3 + 0] = top[col];
                grid_value[col * 3 + 1] = mid[col];
                grid_value[col * 3 + 2] = bottom[col];
            end
            pack_grid = grid_value;
        end
    endfunction

    // 组合输出：内部三行矩阵是状态寄存器，外部看到的是打包后的 obstacle_grid_o。
    assign obstacle_grid_o = pack_grid(row_top, row_mid, row_bottom);
    assign state_code_o    = state;

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            state       <= ST_IDLE;
            row_top     <= '0;
            row_mid     <= '0;
            row_bottom  <= '0;
            car_col_o     <= 3'd3;
            hp_count_o    <= 3'd4;
            spawn_count_o <= '0;
            music_start_o <= 1'b0;
            music_win_o   <= 1'b0;
            lfsr_state    <= (LFSR_SEED == 16'h0000) ? 16'hACE1 : LFSR_SEED;
            safe_col      <= 3'd3;
        end else begin
            // music_start_o 是事件脉冲，默认每拍清零；
            // 只有进入 WIN/LOSE 的那一拍置 1。
            music_start_o <= 1'b0;

            case (state)
                ST_IDLE: begin
                    // 初始状态：清空画面、重置车子和生命值。
                    // 在这里持续赋初值，使从 WIN/LOSE 返回后也能恢复干净界面。
                    row_top     <= '0;
                    row_mid     <= '0;
                    row_bottom  <= '0;
                    car_col_o     <= 3'd3;
                    hp_count_o    <= 3'd4;
                    spawn_count_o <= '0;
                    music_win_o   <= 1'b0;
                    safe_col      <= 3'd3;
                    lfsr_state    <= lfsr_step(lfsr_state);

                    // 任意按键都可以开始游戏。key_pressed_i 已经过防抖，
                    // 所以这里不会因为机械抖动重复触发。
                    if (|key_pressed_i) begin
                        state <= ST_RUN;
                    end
                end

                ST_RUN: begin
                    // RUN 状态使用一组 next_* 临时变量，把“本拍将要发生的”
                    // 移动、下落、碰撞、胜败判定串成清晰的组合计算。
                    // 最后再统一写回寄存器，避免同一 always_ff 中读写顺序混乱。
                    logic [2:0] next_car_col;
                    logic [2:0] next_hp_count;
                    logic [4:0] next_spawn_count;
                    logic [5:0] next_top;
                    logic [5:0] next_mid;
                    logic [5:0] next_bottom;
                    logic [15:0] next_lfsr_state;
                    logic [2:0] next_safe_col_value;
                    logic       hit;
                    logic       finished;

                    next_car_col     = car_col_o;
                    next_hp_count    = hp_count_o;
                    next_spawn_count = spawn_count_o;
                    next_top         = row_top;
                    next_mid         = row_mid;
                    next_bottom      = row_bottom;
                    next_lfsr_state  = lfsr_state;
                    next_safe_col_value = safe_col;

                    // 车辆移动规则：
                    // - KEY2 左移，KEY1 右移。
                    // - 两个方向同时按下时不移动，避免冲突。
                    // - 已到边界时继续按同方向不会越界。
                    if (key_pressed_i[1] && !key_pressed_i[0] && (car_col_o != 3'd0)) begin
                        next_car_col = car_col_o - 1'b1;
                    end else if (key_pressed_i[0] && !key_pressed_i[1] && (car_col_o != 3'd5)) begin
                        next_car_col = car_col_o + 1'b1;
                    end

                    // 障碍下落规则，只在 step_tick_i 到来时执行：
                    // top -> mid，mid -> bottom，bottom 离开/参与碰撞；
                    // 如果还有未生成的关卡图案，就把下一批障碍放入 top。
                    if (step_tick_i) begin
                        next_bottom = row_mid;
                        next_mid    = row_top;
                        if (spawn_count_o < OBSTACLE_COUNT_VALUE) begin
                            next_safe_col_value = next_safe_col(safe_col, lfsr_state[1:0]);
                            next_top = make_obstacle_row(lfsr_state, spawn_count_o, next_safe_col_value);
                            next_spawn_count = spawn_count_o + 1'b1;
                            next_lfsr_state = lfsr_step(lfsr_state);
                        end else begin
                            next_top = '0;
                        end
                    end

                    // 碰撞检测用“本拍移动后的车子列”和“本拍下落后的底层障碍”。
                    // 这意味着玩家在 step_tick_i 同一拍按键时，按键移动会先体现在
                    // next_car_col 中，再参与该拍碰撞判断。
                    hit = next_bottom[next_car_col];
                    if (hit) begin
                        // 撞到的障碍立即清掉，避免同一障碍之后重复扣血。
                        next_bottom[next_car_col] = 1'b0;
                        if (next_hp_count != 3'd0) begin
                            next_hp_count = next_hp_count - 1'b1;
                        end
                    end

                    // 胜利条件：
                    // 1. 预设的 OBSTACLE_COUNT 批障碍已经全部生成；
                    // 2. top/mid/bottom 三层都为空，说明最后一批也离开了画面；
                    // 3. 且前面的失败条件没有先发生。
                    finished = (next_spawn_count >= OBSTACLE_COUNT_VALUE)
                            && (next_top == 6'b0)
                            && (next_mid == 6'b0)
                            && (next_bottom == 6'b0);

                    // 统一写回本拍计算出的下一状态数据。
                    row_top     <= next_top;
                    row_mid     <= next_mid;
                    row_bottom  <= next_bottom;
                    car_col_o     <= next_car_col;
                    hp_count_o    <= next_hp_count;
                    spawn_count_o <= next_spawn_count;
                    lfsr_state    <= next_lfsr_state;
                    safe_col      <= next_safe_col_value;

                    // 失败优先级高于胜利：如果最后一撞刚好扣到 0，进入 LOSE。
                    // 进入结束态时启动蜂鸣器，并用 music_win_o 选择曲目。
                    if (hit && (next_hp_count == 3'd0)) begin
                        state       <= ST_LOSE;
                        music_start_o <= 1'b1;
                        music_win_o   <= 1'b0;
                    end else if (finished) begin
                        state       <= ST_WIN;
                        music_start_o <= 1'b1;
                        music_win_o   <= 1'b1;
                    end
                end

                ST_WIN: begin
                    // 胜利态保持画面清空，等待胜利音乐播放完成。
                    row_top    <= '0;
                    row_mid    <= '0;
                    row_bottom <= '0;
                    if (melody_done_i) begin
                        state <= ST_IDLE;
                    end
                end

                ST_LOSE: begin
                    // 失败态保持画面清空和生命值为 0，等待失败音乐播放完成。
                    row_top    <= '0;
                    row_mid    <= '0;
                    row_bottom <= '0;
                    hp_count_o   <= 3'd0;
                    if (melody_done_i) begin
                        state <= ST_IDLE;
                    end
                end

                default: begin
                    // 防御性分支：若状态寄存器异常，回到初始状态。
                    state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule
