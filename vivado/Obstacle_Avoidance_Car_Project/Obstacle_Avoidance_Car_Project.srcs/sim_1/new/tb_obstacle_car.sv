`timescale 1ns / 1ps

module tb_obstacle_car;
    localparam logic [1:0] ST_IDLE = 2'd0;
    localparam logic [1:0] ST_RUN  = 2'd1;
    localparam logic [1:0] ST_WIN  = 2'd2;

    logic clk = 1'b0;
    logic rst = 1'b1;

    logic        dyn_run;
    logic        dyn_tick;
    logic [1:0]  dyn_speed_level;

    logic        core_step_tick;
    logic [3:0]  core_key_pressed;
    logic        core_melody_done;
    logic [17:0] core_obstacle_grid;
    logic [2:0]  core_car_col;
    logic [2:0]  core_hp_count;
    logic        core_collision_start;
    logic        core_music_start;
    logic [1:0]  core_music_song;
    logic        core_music_loop;
    logic        core_music_stop;
    logic        core_crash_effect;
    logic [1:0]  core_state_code;
    logic [5:0]  core_spawn_count;

    always #5 clk = ~clk;

    dynamic_step_tick #(
        .CLK_HZ(12),
        .START_HZ(2),
        .MID_HZ(3),
        .MAX_HZ(4),
        .ACCEL_SECONDS(1)
    ) u_dynamic_step_tick (
        .clk_i(clk),
        .rst_i(rst),
        .run_i(dyn_run),
        .tick_o(dyn_tick),
        .speed_level_o(dyn_speed_level)
    );

    obstacle_game_core u_game_core (
        .clk_i(clk),
        .rst_i(rst),
        .step_tick_i(core_step_tick),
        .key_pressed_i(core_key_pressed),
        .melody_done_i(core_melody_done),
        .obstacle_grid_o(core_obstacle_grid),
        .car_col_o(core_car_col),
        .hp_count_o(core_hp_count),
        .collision_start_o(core_collision_start),
        .music_start_o(core_music_start),
        .music_song_o(core_music_song),
        .music_loop_o(core_music_loop),
        .music_stop_o(core_music_stop),
        .crash_effect_o(core_crash_effect),
        .state_code_o(core_state_code),
        .spawn_count_o(core_spawn_count)
    );

    task automatic wait_clock(input int cycles);
        repeat (cycles) begin
            @(posedge clk);
            #1;
        end
    endtask

    task automatic check(input logic condition, input string message);
        if (!condition) begin
            $error("%s", message);
            $fatal;
        end
    endtask

    task automatic reset_all();
        rst = 1'b1;
        dyn_run = 1'b0;
        core_step_tick = 1'b0;
        core_key_pressed = 4'b0000;
        core_melody_done = 1'b0;
        wait_clock(3);
        rst = 1'b0;
        wait_clock(2);
    endtask

    task automatic pulse_key(input logic [3:0] key_value);
        core_key_pressed = key_value;
        wait_clock(1);
        core_key_pressed = 4'b0000;
        wait_clock(1);
    endtask

    task automatic pulse_step_with_key(input logic [3:0] key_value);
        core_key_pressed = key_value;
        core_step_tick = 1'b1;
        wait_clock(1);
        core_key_pressed = 4'b0000;
        core_step_tick = 1'b0;
        wait_clock(1);
    endtask

    function automatic logic [5:0] grid_layer(
        input logic [17:0] grid_value,
        input int          layer
    );
        logic [5:0] row_value;
        int col;
        begin
            row_value = 6'b000000;
            for (col = 0; col < 6; col++) begin
                row_value[col] = grid_value[col * 3 + layer];
            end
            grid_layer = row_value;
        end
    endfunction

    function automatic logic has_open_near(
        input logic [5:0] row_value,
        input logic [2:0] from_col
    );
        begin
            has_open_near = !row_value[from_col]
                         || ((from_col != 3'd0) && !row_value[from_col - 1'b1])
                         || ((from_col != 3'd5) && !row_value[from_col + 1'b1]);
        end
    endfunction

    function automatic logic [2:0] choose_safe_target(
        input logic [5:0] immediate_row,
        input logic [5:0] lookahead_row,
        input logic [2:0] from_col
    );
        begin
            choose_safe_target = 3'd7;
            if (!immediate_row[from_col] && has_open_near(lookahead_row, from_col)) begin
                choose_safe_target = from_col;
            end else if ((from_col != 3'd0)
                      && !immediate_row[from_col - 1'b1]
                      && has_open_near(lookahead_row, from_col - 1'b1)) begin
                choose_safe_target = from_col - 1'b1;
            end else if ((from_col != 3'd5)
                      && !immediate_row[from_col + 1'b1]
                      && has_open_near(lookahead_row, from_col + 1'b1)) begin
                choose_safe_target = from_col + 1'b1;
            end
        end
    endfunction

    function automatic logic [3:0] key_for_target(
        input logic [2:0] from_col,
        input logic [2:0] target_col
    );
        begin
            if (target_col < from_col) begin
                key_for_target = 4'b0010;
            end else if (target_col > from_col) begin
                key_for_target = 4'b0001;
            end else begin
                key_for_target = 4'b0000;
            end
        end
    endfunction

    task automatic run_safe_path_to_win(
        input logic [3:0] start_key,
        input logic [5:0] expected_obstacles
    );
        logic [5:0] immediate_row;
        logic [5:0] lookahead_row;
        logic [2:0] target_col;
        int step_count;
        begin
            reset_all();
            pulse_key(start_key);
            check(core_state_code == ST_RUN, "start key should enter RUN");
            check(core_music_start && (core_music_song == 2'd0) && core_music_loop,
                  "start key should start looping background music");

            step_count = 0;
            while ((core_state_code == ST_RUN) && (step_count < 80)) begin
                immediate_row = grid_layer(core_obstacle_grid, 1);
                lookahead_row = grid_layer(core_obstacle_grid, 0);
                target_col = choose_safe_target(immediate_row, lookahead_row, core_car_col);
                check(target_col != 3'd7, "safe route should remain reachable");
                pulse_step_with_key(key_for_target(core_car_col, target_col));
                check(core_hp_count == 3'd4, "safe path should not lose hp");
                step_count++;
            end

            check(core_state_code == ST_WIN, "safe path should enter WIN");
            check(core_spawn_count == expected_obstacles, "spawn_count should match selected obstacle count");
            check(core_music_start && (core_music_song == 2'd1) && !core_music_loop,
                  "WIN should start one-shot win music");

            pulse_key(4'b0001);
            check(core_state_code == ST_IDLE, "any key should return WIN to IDLE");
            check(core_music_stop, "returning from WIN should stop music");
        end
    endtask

    task automatic test_dynamic_step_tick();
        logic saw_tick;
        reset_all();

        wait_clock(20);
        check(!dyn_tick && (dyn_speed_level == 2'd0), "dynamic tick should stay idle when run_i=0");

        dyn_run = 1'b1;
        wait_clock(1);
        check(dyn_speed_level == 2'd0, "RUN should start at speed level 0");

        saw_tick = 1'b0;
        repeat (8) begin
            wait_clock(1);
            saw_tick |= dyn_tick;
        end
        check(saw_tick, "level 0 should generate 2Hz-equivalent ticks");

        wait_clock(8);
        check(dyn_speed_level == 2'd1, "after first acceleration window speed should be level 1");
        wait_clock(12);
        check(dyn_speed_level == 2'd2, "after second acceleration window speed should be level 2");
        wait_clock(24);
        check(dyn_speed_level == 2'd2, "speed should clamp at level 2");

        dyn_run = 1'b0;
        wait_clock(2);
        check(!dyn_tick && (dyn_speed_level == 2'd0), "leaving RUN should reset dynamic tick");
    endtask

    task automatic test_game_core_obstacle_selection();
        run_safe_path_to_win(4'b0001, 6'd20);
        run_safe_path_to_win(4'b0010, 6'd30);
        run_safe_path_to_win(4'b0100, 6'd40);
        run_safe_path_to_win(4'b1000, 6'd50);
        run_safe_path_to_win(4'b1111, 6'd20);
    endtask

    initial begin
        test_dynamic_step_tick();
        test_game_core_obstacle_selection();
        $display("tb_obstacle_car: all tests passed");
        $finish;
    end
endmodule
