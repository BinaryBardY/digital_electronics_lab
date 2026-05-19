`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// sevenseg_scan
// -----------------------------------------------------------------------------
// 6 位共阳极数码管动态扫描模块。
//
// 游戏核心输出的是抽象的 obstacle_grid_i 和 car_col_i，本模块负责把它们转换成
// 真实数码管位选 dig_o 和段选 seg_o：
// - 每次 scan_tick_i 切换到下一位数码管。
// - 每一列只使用 A/G/D 三个横向段显示游戏三层。
// - 障碍常亮，车子在底层 D 段闪烁。
//
// 硬件极性：
// - dig_o 低有效：某一位写 0 表示选中该位。
// - seg_o 低有效：某一段写 0 表示点亮该段。
// - seg_o 位序为 {DP,G,F,E,D,C,B,A}，内部 seg_on 使用 7 位 {G..A} 的正逻辑。
// -----------------------------------------------------------------------------
module sevenseg_scan (
    input  logic        clk_i,
    // 高有效同步复位。
    input  logic        rst_i,
    // 扫描使能脉冲。每来一拍切换到下一位数码管。
    input  logic        scan_tick_i,
    // 6 列 x 3 层障碍矩阵，col*3+0/1/2 分别对应 A/G/D 层。
    input  logic [17:0] obstacle_grid_i,
    // 车子所在列，范围 0~5。
    input  logic [2:0]  car_col_i,
    // 车子是否可见。顶层用 blink_phase 产生闪烁效果。
    input  logic        car_visible_i,
    // 6 位位选输出，低有效。
    output logic [5:0]  dig_o,
    // 8 位段选输出，低有效，包含 DP。
    output logic [7:0]  seg_o
);
    // digit_index 是当前正在扫描的物理数码管位号，范围 0~5。
    logic [2:0] digit_index;
    // col_index 是游戏里的列号。由于板上 SM6~SM1 和物理位选方向相反，
    // 这里用 5 - digit_index 做一次映射，让 col=0 表示最左侧。
    logic [2:0] col_index;
    // 正逻辑段点亮标志，只包含 A~G，不包含 DP。
    // seg_on[0]=A, seg_on[3]=D, seg_on[6]=G。
    logic [6:0] seg_on;

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            digit_index <= 3'd0;
        end else if (scan_tick_i) begin
            if (digit_index == 3'd5) begin
                digit_index <= 3'd0;
            end else begin
                digit_index <= digit_index + 1'b1;
            end
        end
    end

    // 组合生成当前扫描位的段码。
    // 动态扫描的本质是“同一时刻只点亮一位”，快速轮询后人眼看到 6 位同时亮。
    always_comb begin
        // 将物理位号转换成游戏列号。
        col_index = 3'd5 - digit_index;
        seg_on    = 7'b0;

        // 障碍层映射：
        // 上层 -> A 段，中层 -> G 段，下层 -> D 段。
        seg_on[0] = obstacle_grid_i[col_index * 3 + 0]; // A
        seg_on[6] = obstacle_grid_i[col_index * 3 + 1]; // G
        seg_on[3] = obstacle_grid_i[col_index * 3 + 2]; // D

        // 车子也画在底层 D 段。如果当前扫描列等于 car_col_i，
        // 且顶层允许车子可见，就点亮 D 段形成闪烁车身。
        if (car_visible_i && (car_col_i == col_index)) begin
            seg_on[3] = 1'b1;
        end

        // 默认不选中任何位，再把当前位拉低选中。
        dig_o = 6'b111111;
        dig_o[digit_index] = 1'b0;

        // seg_on 是正逻辑，而硬件段选低有效，所以取反输出。
        // DP 在本游戏中不用，固定输出 1 表示熄灭。
        seg_o = {1'b1, ~seg_on};
    end
endmodule
