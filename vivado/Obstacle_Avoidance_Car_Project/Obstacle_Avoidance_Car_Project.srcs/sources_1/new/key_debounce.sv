`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// key_debounce
// -----------------------------------------------------------------------------
// 低有效按键的同步、防抖和按下事件生成模块。
//
// 为什么需要它：
// - 板上按键是机械器件，按下/松开瞬间会在数毫秒内反复跳变。
// - 按键输入来自 FPGA 外部，对 clk_i 来说是异步信号，需要先同步。
// - 游戏核心希望接收“按下一次只触发一次”的事件，而不是持续电平。
//
// 输出含义：
// - key_held_o[i]    ：防抖稳定后的按住状态，高有效，可持续多拍。
// - key_pressed_o[i] ：当 key_held_o 从 0 变为 1 时拉高一个 clk_i 周期。
//                    松开按键不会产生 key_pressed_o 脉冲。
// -----------------------------------------------------------------------------
module key_debounce #(
    // 系统时钟频率，用于把毫秒防抖时间换算成时钟周期数。
    parameter int CLK_HZ      = 50_000_000,
    // 需要输入保持新状态多久才认为按键真的改变。
    parameter int DEBOUNCE_MS = 20,
    // 按键数量，顶层默认 4 个。
    parameter int KEY_COUNT   = 4
) (
    input  logic                 clk_i,
    // 高有效同步复位。
    input  logic                 rst_i,
    // 原始按键输入，低电平表示按下。
    input  logic [KEY_COUNT-1:0] key_n_i,
    // 防抖后的单周期按下脉冲，高有效。
    output logic [KEY_COUNT-1:0] key_pressed_o,
    // 防抖后的稳定按住状态，高有效。
    output logic [KEY_COUNT-1:0] key_held_o
);
    // 将防抖时间从 ms 换算为 clk_i 周期。
    // 先算出一个毫秒多少个周期，再乘以 DEBOUNCE_MS计算出总周期数。
    // 至少返回 1，避免极端参数下产生 0 宽计数器。
    function automatic int calc_cycles(input int clk_hz, input int debounce_ms);
        int cycles;
        begin
            cycles = (clk_hz / 1000) * debounce_ms;
            calc_cycles = (cycles < 1) ? 1 : cycles;
        end
    endfunction

    localparam int DEBOUNCE_CYCLES = calc_cycles(CLK_HZ, DEBOUNCE_MS);
    localparam int CNT_W           = (DEBOUNCE_CYCLES <= 1) ? 1 : $clog2(DEBOUNCE_CYCLES);
    localparam logic [CNT_W-1:0] DEBOUNCE_LAST = CNT_W'(DEBOUNCE_CYCLES - 1);
    // CNT_W：计数器要几位
    // DEBOUNCE_LAST：计数器最后要数到的值

    // 两级同步寄存器：降低异步按键输入导致亚稳态传播的概率。
    // 复位时置 1，对应“未按下”的原始低有效电平。
    logic [KEY_COUNT-1:0] sync_0;
    logic [KEY_COUNT-1:0] sync_1;

    // 每个按键独立一个计数器。
    // 当采样值与当前稳定状态不一致时开始计数；
    // 若一直不一致并计满 DEBOUNCE_CYCLES，则确认状态改变。
    logic [CNT_W-1:0]     cnt [KEY_COUNT];

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            sync_0      <= '1;
            sync_1      <= '1;
            key_held_o    <= '0;
            key_pressed_o <= '0;
            for (int i = 0; i < KEY_COUNT; i++) begin
                cnt[i] <= '0;
            end
        end else begin
            // 先同步原始低有效输入，再在后面转换成高有效 pressed 语义。
            sync_0      <= key_n_i;
            sync_1      <= sync_0;

            // key_pressed_o 默认每拍清零，只在“确认按下”的那一拍置 1。
            key_pressed_o <= '0;

            for (int i = 0; i < KEY_COUNT; i++) begin
                logic sampled_pressed;
                // 原始输入为低有效，所以取反后得到高有效“当前采样为按下”。
                sampled_pressed = ~sync_1[i];

                if (sampled_pressed == key_held_o[i]) begin
                    // 采样值和稳定状态一致，说明没有新的变化或抖动已回到原状态。
                    cnt[i] <= '0;
                end else if (cnt[i] == DEBOUNCE_LAST) begin
                    // 采样值连续保持新状态达到防抖时间，正式更新稳定状态。
                    cnt[i] <= '0;
                    key_held_o[i] <= sampled_pressed;
                    // 只在“确认变为按下”时产生事件；
                    // sampled_pressed 为 0 表示确认松开，此时不触发游戏动作。
                    key_pressed_o[i] <= sampled_pressed;
                end else begin
                    // 采样值仍与稳定状态不同，但持续时间还不够，继续等待。
                    cnt[i] <= cnt[i] + 1'b1;
                end
            end
        end
    end
endmodule
