`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// dynamic_step_tick
// -----------------------------------------------------------------------------
// 可综合的动态障碍下落 tick 发生器。
//
// 本模块仍然只使用 clk_i 一个时钟，不产生派生时钟。tick_o 是单个 clk_i
// 周期宽度的 enable：
// - run_i=0 时复位到初始速度，不产生 tick。
// - run_i=1 后从 START_HZ 开始。
// - 每 ACCEL_SECONDS 秒升一级，依次到 MID_HZ、MAX_HZ。
// - 达到 MAX_HZ 后保持最高速度。
// -----------------------------------------------------------------------------
module dynamic_step_tick #(
    parameter int CLK_HZ        = 50_000_000,
    parameter int START_HZ      = 2,
    parameter int MID_HZ        = 3,
    parameter int MAX_HZ        = 4,
    parameter int ACCEL_SECONDS = 15
) (
    input  logic       clk_i,
    input  logic       rst_i,
    input  logic       run_i,
    output logic       tick_o,
    output logic [1:0] speed_level_o
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

    function automatic int calc_seconds_cycles(input int clk_hz, input int seconds);
        int cycles;
        begin
            if (seconds <= 0) begin
                cycles = 1;
            end else begin
                cycles = clk_hz * seconds;
                if (cycles < 1) begin
                    cycles = 1;
                end
            end
            calc_seconds_cycles = cycles;
        end
    endfunction

    localparam int START_DIV = calc_divider(CLK_HZ, START_HZ);
    localparam int MID_DIV   = calc_divider(CLK_HZ, MID_HZ);
    localparam int MAX_DIV   = calc_divider(CLK_HZ, MAX_HZ);
    localparam int SLOWEST_DIV = (START_DIV >= MID_DIV)
                               ? ((START_DIV >= MAX_DIV) ? START_DIV : MAX_DIV)
                               : ((MID_DIV >= MAX_DIV) ? MID_DIV : MAX_DIV);

    localparam int TICK_CNT_W = (SLOWEST_DIV <= 1) ? 1 : $clog2(SLOWEST_DIV);
    localparam logic [TICK_CNT_W-1:0] START_LAST = TICK_CNT_W'(START_DIV - 1);
    localparam logic [TICK_CNT_W-1:0] MID_LAST   = TICK_CNT_W'(MID_DIV - 1);
    localparam logic [TICK_CNT_W-1:0] MAX_LAST   = TICK_CNT_W'(MAX_DIV - 1);

    localparam int ACCEL_CYCLES = calc_seconds_cycles(CLK_HZ, ACCEL_SECONDS);
    localparam int ACCEL_CNT_W  = (ACCEL_CYCLES <= 1) ? 1 : $clog2(ACCEL_CYCLES);
    localparam logic [ACCEL_CNT_W-1:0] ACCEL_LAST = ACCEL_CNT_W'(ACCEL_CYCLES - 1);

    logic [TICK_CNT_W-1:0]  tick_cnt;
    logic [ACCEL_CNT_W-1:0] accel_cnt;
    logic [TICK_CNT_W-1:0]  active_tick_last;

    always_comb begin
        unique case (speed_level_o)
            2'd0: active_tick_last = START_LAST;
            2'd1: active_tick_last = MID_LAST;
            default: active_tick_last = MAX_LAST;
        endcase
    end

    always_ff @(posedge clk_i) begin
        if (rst_i || !run_i) begin
            tick_o        <= 1'b0;
            tick_cnt      <= '0;
            accel_cnt     <= '0;
            speed_level_o <= 2'd0;
        end else begin
            if (tick_cnt >= active_tick_last) begin
                tick_cnt <= '0;
                tick_o   <= 1'b1;
            end else begin
                tick_cnt <= tick_cnt + 1'b1;
                tick_o   <= 1'b0;
            end

            if (accel_cnt == ACCEL_LAST) begin
                accel_cnt <= '0;
                if (speed_level_o != 2'd2) begin
                    speed_level_o <= speed_level_o + 1'b1;
                    tick_cnt <= '0;
                    tick_o   <= 1'b0;
                end
            end else begin
                accel_cnt <= accel_cnt + 1'b1;
            end
        end
    end
endmodule
