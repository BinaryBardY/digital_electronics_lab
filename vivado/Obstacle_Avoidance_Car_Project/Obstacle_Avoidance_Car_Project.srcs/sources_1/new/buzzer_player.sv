`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// buzzer_player
// -----------------------------------------------------------------------------
// 无源蜂鸣器音效播放器。
//
// 本模块播放离线转换后的整首 4kHz/4bit 单声道 PCM 音频。PCM 每两个采样
// 打包为 1 byte，并由一阶 Sigma-Delta 调制成单引脚 beep_o 输出：
// - 背景音乐：RUN 状态循环播放。
// - 胜利/失败音乐：结算态完整播放一次，播完后静音。
// - 普通碰撞：短促提示音；如果碰撞发生在背景音乐期间，短音结束后从
//   原背景音乐采样位置继续播放，而不是从头开始。
// -----------------------------------------------------------------------------
module buzzer_player #(
    // 系统时钟频率，用于计算采样节拍和碰撞提示音分频。
    parameter int CLK_HZ           = 50_000_000,
    // PCM 采样播放频率。ROM 由工具按 4kHz 生成，默认保持原速播放。
    parameter int PCM_SAMPLE_HZ    = 4_000,
    // Sigma-Delta 调制更新分频。默认 50MHz/8=6.25MHz，远高于音频带宽。
    parameter int SIGMA_DELTA_DIV  = 8,
    // 数字音量右移。0=满音量，1=约 50%，2=约 25%。
    parameter int VOLUME_SHIFT     = 1,
    // 普通碰撞提示音频率和时长。
    parameter int COLLISION_HZ     = 1_000,
    parameter int COLLISION_MS     = 150,
    // Vivado 工程中加入同名 mem 文件后可用默认值；仿真可覆盖为相对路径。
    parameter string PCM_MEM_FILE  = "buzzer_pcm_rom.mem"
) (
    input  logic       clk_i,
    // 高有效同步复位。
    input  logic       rst_i,
    // 立即停止当前蜂鸣器输出，高有效一个 clk_i 周期即可。
    input  logic       stop_i,
    // 普通碰撞短音启动脉冲，高有效一个 clk_i 周期即可。
    input  logic       collision_start_i,
    // 播放启动脉冲，高有效一个 clk_i 周期即可。
    input  logic       play_start_i,
    // 选择要播放的曲目：0=背景，1=胜利，2=失败。
    input  logic [1:0] play_song_i,
    // 启动时采样该信号，1=播完后循环，0=播完后停止并给 done_o。
    input  logic       play_loop_i,
    // 正在播放音乐或碰撞短音时为 1。
    output logic       busy_o,
    // 非循环曲目播放完成时拉高一拍；碰撞短音和循环背景不触发 done_o。
    output logic       done_o,
    // 输出给无源蜂鸣器的 1bit Sigma-Delta/PWM 类音频。
    output logic       beep_o
);
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

    function automatic int calc_tone_half_cycles(input int clk_hz, input int tone_hz);
        int half_period_cycles;
        begin
            if (tone_hz <= 0) begin
                half_period_cycles = 1;
            end else begin
                half_period_cycles = clk_hz / (tone_hz * 2);
                if (half_period_cycles < 1) begin
                    half_period_cycles = 1;
                end
            end
            calc_tone_half_cycles = half_period_cycles;
        end
    endfunction

`include "buzzer_pcm_rom.svh"

    localparam int PCM_SAMPLE_DIV = calc_divider(CLK_HZ, PCM_SAMPLE_HZ);
    localparam int PCM_SAMPLE_W   = (PCM_SAMPLE_DIV <= 1) ? 1 : $clog2(PCM_SAMPLE_DIV);
    localparam logic [PCM_SAMPLE_W-1:0] PCM_SAMPLE_LAST = PCM_SAMPLE_W'(PCM_SAMPLE_DIV - 1);

    localparam int SIGMA_DIVIDER = (SIGMA_DELTA_DIV <= 1) ? 1 : SIGMA_DELTA_DIV;
    localparam int SIGMA_W       = (SIGMA_DIVIDER <= 1) ? 1 : $clog2(SIGMA_DIVIDER);
    localparam logic [SIGMA_W-1:0] SIGMA_LAST = SIGMA_W'(SIGMA_DIVIDER - 1);

    localparam int COLLISION_CYCLES = calc_ms_cycles(CLK_HZ, COLLISION_MS);
    localparam int COLLISION_W      = (COLLISION_CYCLES <= 1) ? 1 : $clog2(COLLISION_CYCLES);
    localparam logic [COLLISION_W-1:0] COLLISION_LAST = COLLISION_W'(COLLISION_CYCLES - 1);

    localparam int COLLISION_HALF_CYCLES = calc_tone_half_cycles(CLK_HZ, COLLISION_HZ);
    localparam int COLLISION_HALF_W      = (COLLISION_HALF_CYCLES <= 1) ? 1 : $clog2(COLLISION_HALF_CYCLES);
    localparam logic [COLLISION_HALF_W-1:0] COLLISION_HALF_LAST =
        COLLISION_HALF_W'(COLLISION_HALF_CYCLES - 1);

    localparam int PCM_INDEX_W = (PCM_SAMPLE_COUNT <= 2) ? 1 : $clog2(PCM_SAMPLE_COUNT);
    localparam int PCM_BYTE_ADDR_W = (PCM_BYTE_COUNT <= 2) ? 1 : $clog2(PCM_BYTE_COUNT);

    localparam logic [1:0] MODE_IDLE      = 2'd0;
    localparam logic [1:0] MODE_SONG      = 2'd1;
    localparam logic [1:0] MODE_COLLISION = 2'd2;

    (* rom_style = "block" *) logic [7:0] pcm_rom [0:PCM_BYTE_COUNT-1];
    logic [PCM_BYTE_ADDR_W-1:0] pcm_addr;
    logic [7:0] pcm_data;

    initial begin
        $readmemh(PCM_MEM_FILE, pcm_rom);
    end

    always_ff @(posedge clk_i) begin
        pcm_data <= pcm_rom[pcm_addr];
    end

    function automatic logic [3:0] unpack_sample4(
        input logic [7:0] packed_byte,
        input logic       odd_sample
    );
        begin
            unpack_sample4 = odd_sample ? packed_byte[7:4] : packed_byte[3:0];
        end
    endfunction

    function automatic logic [3:0] scale_sample4(input logic [3:0] raw_sample);
        int centered;
        int scaled;
        int biased;
        begin
            centered = int'(raw_sample) - 8;
            if (centered < 0) begin
                scaled = -((-centered) >>> VOLUME_SHIFT);
            end else begin
                scaled = centered >>> VOLUME_SHIFT;
            end

            biased = scaled + 8;
            if (biased < 0) begin
                scale_sample4 = 4'd0;
            end else if (biased > 15) begin
                scale_sample4 = 4'd15;
            end else begin
                scale_sample4 = 4'(biased);
            end
        end
    endfunction

    logic [PCM_INDEX_W-1:0]   sample_index;
    logic [PCM_SAMPLE_W-1:0]  sample_tick_cnt;
    logic [SIGMA_W-1:0]       sigma_tick_cnt;
    logic [4:0]               sigma_accum;
    logic [3:0]               current_sample;
    logic [COLLISION_W-1:0]   collision_cnt;
    logic [COLLISION_HALF_W-1:0] collision_tone_cnt;
    logic [1:0]               play_mode;
    logic [1:0]               active_song;
    logic                     active_loop;
    logic                     resume_song_after_collision;
    logic [1:0]               pcm_read_wait;

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            busy_o       <= 1'b0;
            done_o       <= 1'b0;
            beep_o       <= 1'b0;
            sample_index <= '0;
            sample_tick_cnt <= '0;
            sigma_tick_cnt <= '0;
            sigma_accum <= '0;
            current_sample <= 4'd8;
            pcm_addr <= '0;
            pcm_read_wait <= '0;
            collision_cnt <= '0;
            collision_tone_cnt <= '0;
            play_mode    <= MODE_IDLE;
            active_song  <= SONG_BACKGROUND;
            active_loop  <= 1'b0;
            resume_song_after_collision <= 1'b0;
        end else begin
            done_o <= 1'b0;

            if (stop_i) begin
                busy_o       <= 1'b0;
                beep_o       <= 1'b0;
                sample_index <= '0;
                sample_tick_cnt <= '0;
                sigma_tick_cnt <= '0;
                sigma_accum <= '0;
                current_sample <= 4'd8;
                pcm_addr <= '0;
                pcm_read_wait <= '0;
                collision_cnt <= '0;
                collision_tone_cnt <= '0;
                play_mode    <= MODE_IDLE;
                active_song  <= SONG_BACKGROUND;
                active_loop  <= 1'b0;
                resume_song_after_collision <= 1'b0;
            end else if (play_start_i) begin
                int start_index;

                start_index = pcm_song_start(play_song_i);

                busy_o       <= 1'b1;
                beep_o       <= 1'b0;
                sample_index <= PCM_INDEX_W'(start_index);
                sample_tick_cnt <= '0;
                sigma_tick_cnt <= '0;
                sigma_accum <= '0;
                current_sample <= 4'd8;
                pcm_addr <= PCM_BYTE_ADDR_W'(start_index >> 1);
                pcm_read_wait <= 2'd2;
                collision_cnt <= '0;
                collision_tone_cnt <= '0;
                play_mode    <= MODE_SONG;
                active_song  <= play_song_i;
                active_loop  <= play_loop_i;
                resume_song_after_collision <= 1'b0;
            end else begin
                unique case (play_mode)
                    MODE_IDLE: begin
                        busy_o <= 1'b0;
                        beep_o <= 1'b0;
                        sigma_tick_cnt <= '0;
                        sigma_accum <= '0;
                        current_sample <= 4'd8;
                        pcm_read_wait <= '0;
                        resume_song_after_collision <= 1'b0;

                        if (collision_start_i) begin
                            busy_o        <= 1'b1;
                            collision_tone_cnt <= '0;
                            collision_cnt <= '0;
                            beep_o        <= 1'b0;
                            play_mode     <= MODE_COLLISION;
                        end
                    end

                    MODE_COLLISION: begin
                        if (collision_start_i) begin
                            collision_tone_cnt <= '0;
                            collision_cnt <= '0;
                            beep_o        <= 1'b0;
                        end else begin
                            if (collision_tone_cnt >= COLLISION_HALF_LAST) begin
                                collision_tone_cnt <= '0;
                                beep_o <= ~beep_o;
                            end else begin
                                collision_tone_cnt <= collision_tone_cnt + 1'b1;
                            end

                            if (collision_cnt == COLLISION_LAST) begin
                                collision_cnt <= '0;
                                collision_tone_cnt <= '0;
                                beep_o <= 1'b0;
                                sigma_tick_cnt <= '0;
                                sigma_accum <= '0;
                                if (resume_song_after_collision) begin
                                    busy_o <= 1'b1;
                                    play_mode <= MODE_SONG;
                                end else begin
                                    busy_o <= 1'b0;
                                    play_mode <= MODE_IDLE;
                                end
                                resume_song_after_collision <= 1'b0;
                            end else begin
                                collision_cnt <= collision_cnt + 1'b1;
                            end
                        end
                    end

                    MODE_SONG: begin
                        logic [4:0] sigma_sum;
                        int next_index;

                        if (collision_start_i && (active_song == SONG_BACKGROUND)) begin
                            busy_o       <= 1'b1;
                            beep_o       <= 1'b0;
                            collision_tone_cnt <= '0;
                            collision_cnt <= '0;
                            sigma_tick_cnt <= '0;
                            sigma_accum <= '0;
                            resume_song_after_collision <= 1'b1;
                            play_mode    <= MODE_COLLISION;
                        end else if (pcm_read_wait != 0) begin
                            sample_tick_cnt <= '0;
                            if (pcm_read_wait == 2'd1) begin
                                pcm_read_wait <= '0;
                                current_sample <= scale_sample4(
                                    unpack_sample4(pcm_data, sample_index[0])
                                );
                            end else begin
                                pcm_read_wait <= pcm_read_wait - 1'b1;
                            end
                        end else begin
                            if (sigma_tick_cnt == SIGMA_LAST) begin
                                sigma_tick_cnt <= '0;
                                sigma_sum = {1'b0, sigma_accum[3:0]} + {1'b0, current_sample};
                                sigma_accum <= sigma_sum;
                                beep_o <= sigma_sum[4];
                            end else begin
                                sigma_tick_cnt <= sigma_tick_cnt + 1'b1;
                            end

                            if (sample_tick_cnt == PCM_SAMPLE_LAST) begin
                                sample_tick_cnt <= '0;

                                if (sample_index == PCM_INDEX_W'(pcm_song_last(active_song))) begin
                                    if (active_loop) begin
                                        next_index = pcm_song_start(active_song);
                                        sample_index <= PCM_INDEX_W'(next_index);
                                        pcm_addr <= PCM_BYTE_ADDR_W'(next_index >> 1);
                                        pcm_read_wait <= 2'd2;
                                    end else begin
                                        busy_o       <= 1'b0;
                                        done_o       <= 1'b1;
                                        beep_o       <= 1'b0;
                                        sample_index <= '0;
                                        sigma_tick_cnt <= '0;
                                        sigma_accum <= '0;
                                        current_sample <= 4'd8;
                                        pcm_read_wait <= '0;
                                        play_mode    <= MODE_IDLE;
                                    end
                                end else begin
                                    next_index = int'(sample_index) + 1;
                                    sample_index <= PCM_INDEX_W'(next_index);
                                    if ((next_index % 2) == 0) begin
                                        pcm_addr <= PCM_BYTE_ADDR_W'(next_index >> 1);
                                        pcm_read_wait <= 2'd2;
                                    end else begin
                                        current_sample <= scale_sample4(unpack_sample4(pcm_data, 1'b1));
                                    end
                                end
                            end else begin
                                sample_tick_cnt <= sample_tick_cnt + 1'b1;
                            end
                        end
                    end

                    default: begin
                        busy_o       <= 1'b0;
                        beep_o       <= 1'b0;
                        play_mode    <= MODE_IDLE;
                        resume_song_after_collision <= 1'b0;
                    end
                endcase
            end
        end
    end
endmodule
