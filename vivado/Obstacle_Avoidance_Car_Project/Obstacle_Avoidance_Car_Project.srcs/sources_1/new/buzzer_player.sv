`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// buzzer_player
// -----------------------------------------------------------------------------
// 无源蜂鸣器音效播放器。
//
// 无源蜂鸣器需要输入一定频率的方波才会发声。本模块支持两类音效：
// - 普通碰撞：短促单音提示。
// - 游戏结算：胜利/失败 8 音符旋律。
//
// 控制接口很简单：
// - collision_start_i 拉高一拍：播放普通碰撞短音。
// - play_start_i 拉高一拍：从第 0 个音符开始播放结算旋律。
// - play_win_i=1：选择胜利升调旋律；play_win_i=0：选择失败降调旋律。
// - done_o 拉高一拍：8 个结算音符播放完毕；碰撞短音结束不触发 done_o。
// -----------------------------------------------------------------------------
module buzzer_player #(
    // 系统时钟频率，用于计算音符方波分频。
    parameter int CLK_HZ       = 50_000_000,
    // 音符切换频率。默认 8Hz，即每个音符约 125ms。
    parameter int NOTE_TICK_HZ = 8,
    // 普通碰撞提示音频率和时长。
    parameter int COLLISION_HZ = 1_000,
    parameter int COLLISION_MS = 150
) (
    input  logic clk_i,
    // 高有效同步复位。
    input  logic rst_i,
    // 普通碰撞短音启动脉冲，高有效一个 clk_i 周期即可。
    input  logic collision_start_i,
    // 播放启动脉冲，高有效一个 clk_i 周期即可。
    input  logic play_start_i,
    // 启动时采样该信号，1=胜利旋律，0=失败旋律。
    input  logic play_win_i,
    // 正在播放时为 1。
    output logic busy_o,
    // 播放完成时拉高一拍。
    output logic done_o,
    // 输出给无源蜂鸣器的方波。
    output logic beep_o
);
    // 每首曲子固定 8 个音符，note_index 范围为 0~7。
    localparam int NOTE_COUNT = 8;

    // 计算音符持续时间对应的分频系数。
    // 与 tick_gen 类似，非法参数退化为每拍推进一次音符。
    function automatic int calc_divider(input int clk_hz, input int tick_hz);
        if (tick_hz <= 0) begin
            calc_divider = 1;
        end else if ((clk_hz / tick_hz) < 1) begin
            calc_divider = 1;
        end else begin
            calc_divider = clk_hz / tick_hz;
        end
    endfunction

    function automatic int calc_ms_cycles(input int clk_hz, input int duration_ms);
        int cycles;
        begin
            if (duration_ms <= 0) begin
                cycles = 1;
            end else begin
                cycles = (clk_hz / 1000) * duration_ms;
                if (cycles < 1) begin
                    cycles = 1;
                end
            end
            calc_ms_cycles = cycles;
        end
    endfunction

    // NOTE_DIV 控制“多久切换到下一个音符”。
    localparam int NOTE_DIV = calc_divider(CLK_HZ, NOTE_TICK_HZ);
    localparam int NOTE_W   = (NOTE_DIV <= 1) ? 1 : $clog2(NOTE_DIV);
    localparam int COLLISION_CYCLES = calc_ms_cycles(CLK_HZ, COLLISION_MS);
    localparam int COLLISION_W      = (COLLISION_CYCLES <= 1) ? 1 : $clog2(COLLISION_CYCLES);
    // TONE_W 要足够容纳最慢音符的半周期计数。用 CLK_HZ 作为保守上限。
    localparam int TONE_W   = (CLK_HZ <= 2) ? 1 : $clog2(CLK_HZ);
    localparam logic [NOTE_W-1:0] NOTE_LAST = NOTE_W'(NOTE_DIV - 1);
    localparam logic [2:0]        NOTE_INDEX_LAST = 3'(NOTE_COUNT - 1);
    localparam logic [COLLISION_W-1:0] COLLISION_LAST = COLLISION_W'(COLLISION_CYCLES - 1);

    localparam logic [1:0] MODE_IDLE      = 2'd0;
    localparam logic [1:0] MODE_COLLISION = 2'd1;
    localparam logic [1:0] MODE_MELODY    = 2'd2;

    function automatic logic [TONE_W-1:0] calc_tone_half_last(input int tone_hz);
        int half_period_cycles;
        begin
            if (tone_hz <= 0) begin
                half_period_cycles = 1;
            end else begin
                half_period_cycles = CLK_HZ / (tone_hz * 2);
                if (half_period_cycles < 1) begin
                    half_period_cycles = 1;
                end
            end
            calc_tone_half_last = TONE_W'(half_period_cycles - 1);
        end
    endfunction

    // 音符半周期计数表。
    // 不在时序逻辑里用运行期变量做除法，避免 Vivado 综合出很大的组合除法器。
    function automatic logic [TONE_W-1:0] tone_half_last(
        input logic       win_song,
        input logic [2:0] index
    );
        begin
            if (win_song) begin
                case (index)
                    3'd0: tone_half_last = calc_tone_half_last(523);
                    3'd1: tone_half_last = calc_tone_half_last(659);
                    3'd2: tone_half_last = calc_tone_half_last(784);
                    3'd3: tone_half_last = calc_tone_half_last(1046);
                    3'd4: tone_half_last = calc_tone_half_last(784);
                    3'd5: tone_half_last = calc_tone_half_last(1046);
                    3'd6: tone_half_last = calc_tone_half_last(1318);
                    default: tone_half_last = calc_tone_half_last(1568);
                endcase
            end else begin
                case (index)
                    3'd0: tone_half_last = calc_tone_half_last(392);
                    3'd1: tone_half_last = calc_tone_half_last(330);
                    3'd2: tone_half_last = calc_tone_half_last(262);
                    3'd3: tone_half_last = calc_tone_half_last(196);
                    3'd4: tone_half_last = calc_tone_half_last(196);
                    3'd5: tone_half_last = calc_tone_half_last(165);
                    3'd6: tone_half_last = calc_tone_half_last(147);
                    default: tone_half_last = calc_tone_half_last(131);
                endcase
            end
        end
    endfunction

    // note_cnt 控制音符时长；tone_cnt 控制当前音符的 beep_o 翻转频率。
    logic [NOTE_W-1:0] note_cnt;
    logic [TONE_W-1:0] tone_cnt;
    logic [COLLISION_W-1:0] collision_cnt;
    // 当前播放到第几个音符。
    logic [2:0]        note_index;
    // 播放启动时锁存 play_win_i，避免播放中外部变化影响当前旋律。
    logic              song_win;
    logic [1:0]        play_mode;

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            busy_o       <= 1'b0;
            done_o       <= 1'b0;
            beep_o       <= 1'b0;
            note_cnt   <= '0;
            tone_cnt   <= '0;
            collision_cnt <= '0;
            note_index <= '0;
            song_win   <= 1'b0;
            play_mode  <= MODE_IDLE;
        end else begin
            // done_o 是完成事件脉冲，默认每拍清零。
            done_o <= 1'b0;

            if (play_start_i) begin
                // 结算旋律优先级最高。即使碰撞短音正在播放，也会被立即打断。
                busy_o       <= 1'b1;
                note_cnt   <= '0;
                tone_cnt   <= '0;
                collision_cnt <= '0;
                note_index <= '0;
                song_win   <= play_win_i;
                beep_o       <= 1'b0;
                play_mode  <= MODE_MELODY;
            end else begin
                case (play_mode)
                    MODE_IDLE: begin
                        busy_o <= 1'b0;
                        beep_o <= 1'b0;
                        if (collision_start_i) begin
                            busy_o        <= 1'b1;
                            tone_cnt      <= '0;
                            collision_cnt <= '0;
                            beep_o        <= 1'b0;
                            play_mode     <= MODE_COLLISION;
                        end
                    end

                    MODE_COLLISION: begin
                        logic [TONE_W-1:0] collision_half_last;

                        if (collision_start_i) begin
                            tone_cnt      <= '0;
                            collision_cnt <= '0;
                            beep_o        <= 1'b0;
                        end else begin
                            collision_half_last = calc_tone_half_last(COLLISION_HZ);

                            if (tone_cnt >= collision_half_last) begin
                                tone_cnt <= '0;
                                beep_o   <= ~beep_o;
                            end else begin
                                tone_cnt <= tone_cnt + 1'b1;
                            end

                            if (collision_cnt == COLLISION_LAST) begin
                                busy_o        <= 1'b0;
                                beep_o        <= 1'b0;
                                collision_cnt <= '0;
                                play_mode     <= MODE_IDLE;
                            end else begin
                                collision_cnt <= collision_cnt + 1'b1;
                            end
                        end
                    end

                    MODE_MELODY: begin
                        logic [TONE_W-1:0] current_half_last;

                        // 查表得到 beep_o 翻转的半周期计数上限。
                        current_half_last = tone_half_last(song_win, note_index);

                        // 方波发生器：tone_cnt 到达半周期末尾时翻转 beep_o。
                        if (tone_cnt >= current_half_last) begin
                            tone_cnt <= '0;
                            beep_o   <= ~beep_o;
                        end else begin
                            tone_cnt <= tone_cnt + 1'b1;
                        end

                        // 音符节拍计数：NOTE_LAST 到达后推进到下一个音符。
                        if (note_cnt == NOTE_LAST) begin
                            note_cnt <= '0;
                            if (note_index == NOTE_INDEX_LAST) begin
                                // 最后一个音符播放完成：结束 busy_o，发出 done_o 脉冲并关蜂鸣器。
                                busy_o     <= 1'b0;
                                done_o     <= 1'b1;
                                beep_o     <= 1'b0;
                                note_index <= '0;
                                play_mode  <= MODE_IDLE;
                            end else begin
                                // 进入下一个音符。tone_cnt 不强制清零也能工作；
                                // 下一拍会按新频率继续计数，声音切换足够自然。
                                note_index <= note_index + 1'b1;
                            end
                        end else begin
                            note_cnt <= note_cnt + 1'b1;
                        end
                    end

                    default: begin
                        busy_o    <= 1'b0;
                        beep_o    <= 1'b0;
                        play_mode <= MODE_IDLE;
                    end
                endcase
            end
        end
    end
endmodule
