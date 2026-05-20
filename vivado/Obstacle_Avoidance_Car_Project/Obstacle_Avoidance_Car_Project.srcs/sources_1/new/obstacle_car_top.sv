`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// obstacle_car_top
// -----------------------------------------------------------------------------
// 避障车小游戏的顶层模块，负责把开发板上的真实引脚和内部功能模块连接起来。
//
// 推荐阅读入口：
// 1. 先看本文件的端口和参数，了解整机有哪些外设和全局频率。
// 2. 再顺着实例化关系看 key_debounce / tick_gen / obstacle_game_core /
//    sevenseg_scan / buzzer_player，各子模块只通过清晰的信号互连。
//
// 设计约定：
// - 全系统只使用 fpga_clk_i 一个 50MHz 时钟。
// - reset_n_i 和 key_n_i 均来自板上按键，硬件上是低电平有效。
// - 低速动作不产生新时钟，而是由 tick_gen 产生单周期 tick enable。
// - 数码管和蜂鸣器都是由同步逻辑驱动，便于综合和时序约束。
// -----------------------------------------------------------------------------
module obstacle_car_top #(
    // 开发板系统时钟频率。默认 50MHz，所有分频参数都以它为基准。
    parameter int CLK_HZ        = 50_000_000,
    // 障碍下落频率：2Hz 表示每 0.5s 下落一层。
    parameter int STEP_TICK_HZ  = 2,
    // 车子闪烁频率：用于让底层 D 段闪烁，和障碍常亮区分开。
    parameter int BLINK_TICK_HZ = 8,
    // 数码管扫描频率：6 位轮询，默认 6000Hz，总刷新足够高，不易闪烁。
    parameter int SCAN_TICK_HZ  = 6_000,
    // 按键防抖时间。机械按键按下/释放时会抖动，这里等待稳定 20ms。
    parameter int DEBOUNCE_MS   = 20,
    // 蜂鸣器换音符的节拍。8Hz 表示每个音符持续约 125ms。
    parameter int MUSIC_TICK_HZ = 8
) (
    // 50MHz 系统时钟输入。
    input  logic       fpga_clk_i,
    // 低有效复位键，进入芯片后会先同步成高有效 rst。
    input  logic       reset_n_i,
    // 4 个低有效独立按键：KEY1/KEY2 控制左右，KEY3/KEY4 可开始游戏。
    input  logic [3:0] key_n_i,
    // 生命值 LED，高电平点亮。
    output logic [3:0] led_o,
    // 6 位数码管位选，低电平有效。
    output logic [5:0] dig_o,
    // 8 路数码管段选，低电平有效，顺序为 {DP,G,F,E,D,C,B,A}。
    output logic [7:0] seg_o,
    // 无源蜂鸣器 PWM 方波输出。
    output logic       beep_o
);
    // reset_pipe 将异步输入 reset_n_i 同步到 fpga_clk_i 域。
    // reset_n_i 为 0 时表示按下复位，取反后为高有效复位请求。
    logic [1:0] reset_pipe = 2'b11;
    logic       rst;

    // key_pressed 是防抖后的“按下沿”单周期脉冲，游戏核心用它触发动作。
    // key_held 是防抖后的按住状态，本项目当前只保留为调试观测信号。
    logic [3:0] key_pressed;
    logic [3:0] key_held;

    // 三个 tick 都是单个 fpga_clk_i 周期宽度的使能脉冲，不是新时钟。
    logic       step_tick;
    logic       blink_tick;
    logic       scan_tick;

    // blink_phase 被 blink_tick 翻转，作为车子闪烁显示的相位。
    logic       blink_phase;

    // 游戏核心输出的画面和状态。
    // obstacle_grid：6 列 * 3 层 = 18 位障碍矩阵。
    // car_col：车子所在列，范围 0~5。
    // hp_count：剩余生命值，范围 0~4。
    logic [17:0] obstacle_grid;
    logic [2:0]  car_col;
    logic [2:0]  hp_count;

    // 游戏结束时，核心用 music_start 拉高一拍启动蜂鸣器；
    // music_win 选择胜利旋律或失败旋律。
    logic        music_start;
    logic        music_win;
    logic        melody_done;
    logic        melody_busy;

    // state_code / spawn_count 主要用于显示控制和调试观测。
    logic [1:0]  state_code;
    logic [4:0]  spawn_count;

    always_ff @(posedge fpga_clk_i) begin
        reset_pipe <= {reset_pipe[0], ~reset_n_i};
    end

    // rst 是高有效同步复位。reset_pipe[1] 让复位释放也同步到时钟边沿。
    assign rst = reset_pipe[1];

    // 输入侧：把低有效机械按键转换成稳定的高有效事件。
    key_debounce #(
        .CLK_HZ(CLK_HZ),
        .DEBOUNCE_MS(DEBOUNCE_MS),
        .KEY_COUNT(4)
    ) u_key_debounce (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .key_n_i(key_n_i),
        .key_pressed_o(key_pressed),
        .key_held_o(key_held)
    );

    // 时基 1：控制障碍下落速度。
    tick_gen #(
        .CLK_HZ(CLK_HZ),
        .TICK_HZ(STEP_TICK_HZ)
    ) u_step_tick (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .tick_o(step_tick)
    );

    // 时基 2：控制车子显示闪烁。
    tick_gen #(
        .CLK_HZ(CLK_HZ),
        .TICK_HZ(BLINK_TICK_HZ)
    ) u_blink_tick (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .tick_o(blink_tick)
    );

    // 时基 3：控制 6 位数码管动态扫描。
    tick_gen #(
        .CLK_HZ(CLK_HZ),
        .TICK_HZ(SCAN_TICK_HZ)
    ) u_scan_tick (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .tick_o(scan_tick)
    );

    // 闪烁相位寄存器：每来一次 blink_tick 翻转一次。
    // 初值给 1，使游戏刚开始时车子先可见。
    always_ff @(posedge fpga_clk_i) begin
        if (rst) begin
            blink_phase <= 1'b1;
        end else if (blink_tick) begin
            blink_phase <= ~blink_phase;
        end
    end

    // 游戏核心：负责状态机、车辆移动、障碍下落、碰撞检测、胜败判定。
    // 它不直接关心具体硬件段码，只输出抽象的障碍矩阵和车子列号。
    obstacle_game_core u_game_core (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .step_tick_i(step_tick),
        .key_pressed_i(key_pressed),
        .melody_done_i(melody_done),
        .obstacle_grid_o(obstacle_grid),
        .car_col_o(car_col),
        .hp_count_o(hp_count),
        .music_start_o(music_start),
        .music_win_o(music_win),
        .state_code_o(state_code),
        .spawn_count_o(spawn_count)
    );

    // 显示输出：把抽象的 6x3 游戏画面映射到 6 位数码管的 A/G/D 段。
    // 只有 RUN 状态下车子才参与闪烁显示。
    sevenseg_scan u_sevenseg_scan (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .scan_tick_i(scan_tick),
        .obstacle_grid_i(obstacle_grid),
        .car_col_i(car_col),
        .car_visible_i((state_code == 2'd1) && blink_phase),
        .dig_o(dig_o),
        .seg_o(seg_o)
    );

    // 声音输出：游戏核心只给出“开始播放”和“胜/负类型”，
    // 具体音符频率、节拍计数和 beep_o 方波都封装在 buzzer_player 内。
    buzzer_player #(
        .CLK_HZ(CLK_HZ),
        .NOTE_TICK_HZ(MUSIC_TICK_HZ)
    ) u_buzzer_player (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .play_start_i(music_start),
        .play_win_i(music_win),
        .busy_o(melody_busy),
        .done_o(melody_done),
        .beep_o(beep_o)
    );

    // 生命值 LED 特效：剩余机会同步呼吸，扣除机会时爆闪后熄灭。
    hp_led_pwm #(
        .CLK_HZ(CLK_HZ)
    ) u_hp_led_pwm (
        .clk_i(fpga_clk_i),
        .rst_i(rst),
        .hp_count_i(hp_count),
        .led_o(led_o)
    );

    // 保留调试信号的连接，避免综合工具报告未使用信号警告；
    // 该归约异或结果没有外接端口，不影响设计功能。
    logic unused_status;
    assign unused_status = ^{key_held, melody_busy, spawn_count};
endmodule
