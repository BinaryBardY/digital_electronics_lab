`timescale 1ns / 1ps

// -----------------------------------------------------------------------------
// hp_led_pwm
// -----------------------------------------------------------------------------
// 剩余机会 LED 特效模块。
//
// - hp_count_i 决定哪些 LED 代表仍然存在的机会。
// - 仍存在的机会使用同步 PWM 呼吸灯显示，最低亮度不降到 0。
// - 当 hp_count_i 减小时，被扣掉的 LED 先快速爆闪，再保持熄灭。
//
// 所有逻辑都在 clk_i 上升沿工作；低速呼吸和爆闪只使用 tick enable，
// 不产生新时钟，也不使用下降沿触发。
// -----------------------------------------------------------------------------
module hp_led_pwm #(
    parameter int CLK_HZ          = 50_000_000,
    parameter int PWM_BITS        = 8,
    parameter int BREATH_TICK_HZ  = 256,
    parameter int FLASH_TICK_HZ   = 24,
    parameter int FLASH_TOGGLES   = 12
) (
    input  logic       clk_i,
    input  logic       rst_i,
    input  logic [2:0] hp_count_i,
    output logic [3:0] led_o
);
    function automatic int calc_min_duty(input int pwm_bits);
        if (pwm_bits < 4) begin
            calc_min_duty = 1;
        end else begin
            calc_min_duty = 1 << (pwm_bits - 3);
        end
    endfunction

    function automatic logic [3:0] hp_to_mask(input logic [2:0] hp_count);
        begin
            case (hp_count)
                3'd4: hp_to_mask = 4'b1111;
                3'd3: hp_to_mask = 4'b0111;
                3'd2: hp_to_mask = 4'b0011;
                3'd1: hp_to_mask = 4'b0001;
                default: hp_to_mask = 4'b0000;
            endcase
        end
    endfunction

    localparam logic [PWM_BITS-1:0] DUTY_MIN = PWM_BITS'(calc_min_duty(PWM_BITS));
    localparam logic [PWM_BITS-1:0] DUTY_MAX = {PWM_BITS{1'b1}};
    localparam int FLASH_LIMIT = (FLASH_TOGGLES <= 0) ? 1 : FLASH_TOGGLES;
    localparam int FLASH_CNT_W = (FLASH_LIMIT <= 1) ? 1 : $clog2(FLASH_LIMIT);
    localparam logic [FLASH_CNT_W-1:0] FLASH_LAST = FLASH_CNT_W'(FLASH_LIMIT - 1);

    logic breath_tick;
    logic flash_tick;

    logic [PWM_BITS-1:0] pwm_counter;
    logic [PWM_BITS-1:0] breath_duty;
    logic                breath_dir_up;

    logic [2:0] hp_count_d;
    logic [3:0] current_hp_mask;
    logic [3:0] previous_hp_mask;
    logic [3:0] removed_hp_mask;

    logic [3:0] flash_mask;
    logic       flash_phase;
    logic [FLASH_CNT_W-1:0] flash_toggle_count;

    tick_gen #(
        .CLK_HZ(CLK_HZ),
        .TICK_HZ(BREATH_TICK_HZ)
    ) u_breath_tick (
        .clk_i(clk_i),
        .rst_i(rst_i),
        .tick_o(breath_tick)
    );

    tick_gen #(
        .CLK_HZ(CLK_HZ),
        .TICK_HZ(FLASH_TICK_HZ)
    ) u_flash_tick (
        .clk_i(clk_i),
        .rst_i(rst_i),
        .tick_o(flash_tick)
    );

    assign current_hp_mask  = hp_to_mask(hp_count_i);
    assign previous_hp_mask = hp_to_mask(hp_count_d);
    assign removed_hp_mask  = previous_hp_mask & ~current_hp_mask;

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            pwm_counter <= '0;
        end else begin
            pwm_counter <= pwm_counter + 1'b1;
        end
    end

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            breath_duty   <= DUTY_MIN;
            breath_dir_up <= 1'b1;
        end else if (breath_tick) begin
            if (breath_dir_up) begin
                if (breath_duty == DUTY_MAX) begin
                    breath_dir_up <= 1'b0;
                end else begin
                    breath_duty <= breath_duty + 1'b1;
                end
            end else begin
                if (breath_duty == DUTY_MIN) begin
                    breath_dir_up <= 1'b1;
                end else begin
                    breath_duty <= breath_duty - 1'b1;
                end
            end
        end
    end

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            hp_count_d         <= 3'd4;
            flash_mask         <= 4'b0000;
            flash_phase        <= 1'b0;
            flash_toggle_count <= '0;
        end else begin
            hp_count_d <= hp_count_i;

            if (hp_count_i < hp_count_d) begin
                flash_mask         <= removed_hp_mask;
                flash_phase        <= 1'b1;
                flash_toggle_count <= '0;
            end else if (hp_count_i > hp_count_d) begin
                flash_mask         <= 4'b0000;
                flash_phase        <= 1'b0;
                flash_toggle_count <= '0;
            end else if (flash_tick && (flash_mask != 4'b0000)) begin
                if (flash_toggle_count == FLASH_LAST) begin
                    flash_mask         <= 4'b0000;
                    flash_phase        <= 1'b0;
                    flash_toggle_count <= '0;
                end else begin
                    flash_phase        <= ~flash_phase;
                    flash_toggle_count <= flash_toggle_count + 1'b1;
                end
            end
        end
    end

    always_comb begin
        led_o = current_hp_mask & {4{pwm_counter < breath_duty}};
        led_o = (led_o & ~flash_mask) | (flash_mask & {4{flash_phase}});
    end
endmodule
