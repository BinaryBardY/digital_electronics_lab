`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// tick_gen
// -----------------------------------------------------------------------------
// 通用 tick_o enable 发生器。
//
// 本项目坚持单时钟域设计：所有模块都使用同一个 clk_i，不从逻辑中再分出
// 慢时钟。tick_gen 的输出 tick_o 只是一个 clk_i 周期宽度的“使能脉冲”，下游
// 模块在 if (tick_o) 条件内执行低速动作。
//
// 例子：
// - CLK_HZ=50_000_000, TICK_HZ=2    -> 每 25_000_000 拍拉高一次 tick_o。
// - CLK_HZ=50_000_000, TICK_HZ=6000 -> 用于数码管快速扫描。
// -----------------------------------------------------------------------------
module tick_gen #(
    // 输入时钟频率。
    parameter int CLK_HZ  = 50_000_000,
    // 目标 tick_o 频率。tick_o 每次只持续 1 个 clk_i 周期。
    parameter int TICK_HZ = 1
) (
    input  logic clk_i,
    // 高有效同步复位。
    input  logic rst_i,
    // 周期性单拍脉冲输出。
    output logic tick_o
);
    // 计算分频系数。这里对非法或过高的 TICK_HZ 做保护：
    // 若 tick_hz <= 0 或分频结果小于 1，则退化为每拍都出 tick_o。
    function automatic int calc_divider(input int clk_hz, input int tick_hz);
        if (tick_hz <= 0) begin
            calc_divider = 1;
        end else if ((clk_hz / tick_hz) < 1) begin
            calc_divider = 1;
        end else begin
            calc_divider = clk_hz / tick_hz;
        end
    endfunction

    localparam int DIVIDER = calc_divider(CLK_HZ, TICK_HZ);
    // 计数器位宽至少为 1，保证 DIVIDER=1 时仍然有合法向量宽度。
    localparam int CNT_W   = (DIVIDER <= 1) ? 1 : $clog2(DIVIDER);
    // 计到 DIVIDER-1 时输出 tick_o，因此完整周期正好是 DIVIDER 个 clk_i。
    localparam logic [CNT_W-1:0] DIVIDER_LAST = CNT_W'(DIVIDER - 1);

    logic [CNT_W-1:0] cnt;

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            cnt  <= '0;
            tick_o <= 1'b0;
        end else if (cnt == DIVIDER_LAST) begin
            // 分频周期结束：计数器回零，同时 tick_o 拉高一拍。
            cnt  <= '0;
            tick_o <= 1'b1;
        end else begin
            // 分频周期进行中：继续计数，tick_o 保持低电平。
            cnt  <= cnt + 1'b1;
            tick_o <= 1'b0;
        end
    end
endmodule
