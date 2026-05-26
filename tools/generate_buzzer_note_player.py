#!/usr/bin/env python3
"""Generate the note-table buzzer player and matching WAV previews."""

from __future__ import annotations

import math
import wave
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SV_PATH = ROOT / "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sources_1/new/buzzer_note_player.sv"
PREVIEW_DIR = ROOT / "music/note_player_preview"

SAMPLE_RATE_HZ = 4000
TEMPO_BPM = 96
NOTE_GAP_MS = 35
UNIT_S = 60.0 / (TEMPO_BPM * 4)
ENABLE_BACKGROUND_MUSIC = True

# The Verilog player mostly uses the See You Again key center, 1=Bb. A few
# chromatic notes are kept for the Mario-style fail cue so it does not collapse
# into a wrong major-scale approximation.
NOTE_HZ = {
    "REST": 0,
    "E4": 330,
    "G4": 392,
    "A4": 440,
    "AS4": 466,
    "B4": 494,
    "C5": 523,
    "D5": 587,
    "E5": 659,
    "F5": 698,
    "G5": 784,
    "A5": 880,
    "L5": 349,
    "L6": 392,
    "L7": 440,
    "1": 466,
    "2": 523,
    "3": 587,
    "4": 622,
    "5": 698,
    "6": 784,
    "7": 880,
    "H1": 932,
    "H2": 1047,
    "H3": 1175,
    "H4": 1245,
    "H5": 1397,
}

NOTE_CODES = {name: idx for idx, name in enumerate(NOTE_HZ)}


def n(note: str, beats: float) -> tuple[str, int]:
    return note, max(1, round(beats * 4))


INTRO = [
    n("5", 0.50), n("H2", 0.50), n("H1", 0.50), n("5", 0.50),
    n("5", 0.50), n("H1", 0.25), n("H2", 0.25), n("H3", 0.25),
    n("H2", 0.25), n("H1", 0.25), n("H2", 0.50),
]

CHORUS_A = [
    n("6", 1.00), n("5", 0.50), n("5", 0.50), n("REST", 0.50), n("1", 0.50),
    n("2", 0.50), n("2", 0.50), n("1", 0.50), n("2", 0.50), n("3", 1.00),
    n("REST", 0.50), n("3", 0.50), n("5", 0.50),
    n("6", 0.50), n("7", 0.50), n("6", 0.50), n("5", 0.50),
    n("3", 0.50), n("2", 0.50), n("2", 0.75), n("1", 0.75),
    n("2", 0.50), n("2", 0.50), n("2", 0.50), n("1", 0.75),
    n("REST", 1.00), n("REST", 0.50), n("1", 0.35), n("3", 0.35), n("5", 0.35),
]

CHORUS_B = [
    n("6", 1.00), n("5", 0.50), n("5", 0.50), n("REST", 0.50), n("1", 0.50),
    n("2", 0.50), n("2", 0.50), n("1", 0.50), n("3", 0.75),
    n("REST", 0.50), n("2", 0.35), n("3", 0.35), n("5", 0.35),
    n("6", 0.50), n("H1", 0.50), n("H2", 0.50), n("H3", 0.50),
    n("H2", 0.50), n("H1", 0.50), n("5", 0.45), n("6", 0.45), n("H1", 0.75),
    n("H3", 0.45), n("H3", 0.45), n("H3", 0.45), n("H2", 1.00), n("REST", 0.75),
]

BRIDGE = [
    n("3", 0.50), n("3", 0.25), n("2", 0.25), n("3", 0.50),
    n("3", 0.25), n("2", 0.25), n("3", 0.50), n("3", 0.25), n("2", 0.25),
    n("1", 0.75), n("REST", 0.50),
    n("3", 0.50), n("3", 0.25), n("2", 0.25), n("3", 0.50),
    n("3", 0.25), n("2", 0.25), n("1", 0.75), n("REST", 0.50),
    n("H1", 0.35), n("H1", 0.35), n("H1", 0.35), n("H3", 0.50),
    n("H3", 0.35), n("H1", 0.35), n("H1", 0.35), n("H1", 0.35),
    n("H1", 0.35), n("H1", 0.35), n("H1", 0.35), n("H1", 0.35),
    n("6", 0.90), n("H3", 0.60),
    n("H1", 0.45), n("H1", 0.45), n("H1", 0.45), n("H1", 0.45),
    n("H1", 0.45), n("H1", 0.45), n("H1", 0.45), n("H1", 0.45),
    n("6", 0.90), n("6", 0.80), n("H3", 0.45), n("H1", 0.45),
    n("H1", 0.45), n("H1", 0.45), n("H1", 0.45), n("H1", 0.45),
    n("1", 0.80), n("3", 0.50), n("5", 0.50),
]

VERSE_TWO = [
    n("H3", 0.45), n("H3", 0.45), n("H3", 0.45), n("H2", 0.75), n("REST", 0.50),
    n("H1", 0.50), n("7", 0.50), n("6", 1.00), n("5", 0.50), n("REST", 0.50),
    n("H1", 0.50), n("7", 0.50), n("6", 0.50), n("7", 0.50), n("6", 0.50),
    n("5", 0.50), n("3", 0.50), n("5", 0.25), n("6", 0.25), n("H1", 0.25),
    n("H2", 0.50), n("H3", 0.60), n("H2", 0.50), n("H3", 0.50),
    n("H2", 0.50), n("H3", 0.50), n("H2", 0.50), n("3", 0.25), n("5", 0.25),
    n("3", 0.25), n("2", 0.50), n("1", 0.75),
]

ENDING = [
    n("6", 1.00), n("5", 0.50), n("5", 0.50), n("1", 0.50), n("2", 0.50),
    n("2", 0.50), n("3", 0.50), n("REST", 0.25), n("1", 0.25), n("REST", 0.50),
    n("REST", 0.50), n("6", 0.50), n("6", 0.50), n("6", 0.50), n("6", 0.50),
    n("6", 0.50), n("5", 1.00), n("5", 0.50), n("3", 0.50), n("5", 0.50),
    n("5", 0.70), n("6", 1.50), n("REST", 0.50), n("2", 0.35), n("3", 0.35),
    n("4", 0.50), n("H2", 0.50), n("H1", 1.00), n("REST", 0.70), n("REST", 0.50),
    n("H3", 0.50), n("H2", 0.50), n("H1", 0.50), n("7", 0.70), n("6", 1.20),
    n("REST", 0.25), n("6", 0.40), n("7", 0.40), n("H1", 0.90), n("H2", 0.90),
    n("H1", 1.50), n("REST", 0.50), n("1", 0.35), n("3", 0.35), n("5", 0.35),
]

FINAL = [
    n("H2", 0.50), n("H2", 0.50), n("H1", 0.50), n("H3", 0.80), n("H3", 0.60),
    n("H1", 0.50), n("7", 0.50), n("6", 1.00), n("5", 0.50), n("REST", 0.50),
    n("H1", 0.50), n("7", 0.50), n("6", 0.50), n("7", 0.50), n("6", 0.50),
    n("5", 0.50), n("3", 0.50), n("5", 0.25), n("6", 0.25), n("H1", 0.25),
    n("H2", 0.50), n("H3", 0.70), n("H2", 0.50), n("H3", 0.50),
    n("H2", 0.50), n("H3", 0.50), n("H2", 0.50), n("3", 0.25), n("5", 0.25),
    n("3", 0.25), n("2", 0.50), n("1", 1.50), n("REST", 1.00),
]

SEE_YOU_AGAIN_MELODY = sum([
    INTRO, INTRO, INTRO, INTRO,
    CHORUS_A, CHORUS_B,
    BRIDGE,
    CHORUS_A, CHORUS_B,
    VERSE_TWO,
    BRIDGE,
    ENDING,
    FINAL,
], [])

BG_MELODY = SEE_YOU_AGAIN_MELODY if ENABLE_BACKGROUND_MUSIC else [n("REST", 1.0)]

WIN_MELODY = [
    # Short, separated arcade-style victory fanfare: bright ascending beeps.
    n("C5", 0.50), n("REST", 0.25),
    n("E5", 0.50), n("REST", 0.25),
    n("G5", 0.50), n("REST", 0.25),
    n("A5", 0.50), n("REST", 0.25),
    n("G5", 0.50), n("REST", 0.25),
    n("A5", 0.50), n("REST", 0.25),
    n("H1", 1.00), n("REST", 0.50),
]

FAIL_MELODY = [
    # Short, separated game-over cue: low descending beeps.
    n("G5", 0.50), n("REST", 0.25),
    n("E5", 0.50), n("REST", 0.25),
    n("C5", 0.50), n("REST", 0.25),
    n("A4", 0.75), n("REST", 0.25),
    n("G4", 0.75), n("REST", 0.25),
    n("E4", 1.25), n("REST", 0.50),
]


def sv_case(name: str, values: list[int], suffix: str, width: str) -> str:
    lines = [f"    function automatic logic [{width}] {name}(input int idx);", "        begin", "            unique case (idx)"]
    for idx, value in enumerate(values):
        lines.append(f"                {idx}: {name} = {value};")
    lines.extend([f"                default: {name} = {suffix};", "            endcase", "        end", "    endfunction", ""])
    return "\n".join(lines)


def write_sv() -> None:
    songs = {
        "bg": BG_MELODY,
        "win": WIN_MELODY,
        "fail": FAIL_MELODY,
    }
    max_count = max(len(v) for v in songs.values())
    index_w = max(1, math.ceil(math.log2(max_count)))
    note_code_w = max(4, math.ceil(math.log2(len(NOTE_CODES))))

    note_funcs = []
    unit_funcs = []
    for name, melody in songs.items():
        note_funcs.append(sv_case(f"{name}_note", [NOTE_CODES[note] for note, _ in melody], "NOTE_REST", "NOTE_CODE_W-1:0"))
        unit_funcs.append(sv_case(f"{name}_units", [units for _, units in melody], "1", "3:0"))

    note_defs = "\n".join(
        f"    localparam logic [NOTE_CODE_W-1:0] NOTE_{name} = {code};"
        for name, code in NOTE_CODES.items()
    )

    freq_cases = "\n".join(
        f"                NOTE_{name}: half_cycles_for_note = CLK_HZ / ({hz} * 2);"
        for name, hz in NOTE_HZ.items()
        if name != "REST"
    )

    sv = f"""`timescale 1ns / 1ps

// Passive-buzzer note player generated by tools/generate_buzzer_note_player.py.
// It follows the tutorial-style method: note table + beat table + square-wave
// divider. Background music is disabled in this build; win is a separated
// rising cue; fail is a separated descending cue.
module buzzer_note_player #(
    parameter int CLK_HZ       = 50_000_000,
    parameter int TEMPO_BPM    = {TEMPO_BPM},
    parameter int NOTE_GAP_MS  = {NOTE_GAP_MS},
    parameter bit BUZZER_ACTIVE_LOW = 1'b1,
    parameter int COLLISION_HZ = 1_000,
    parameter int COLLISION_MS = 150
) (
    input  logic       clk_i,
    input  logic       rst_i,
    input  logic       stop_i,
    input  logic       collision_start_i,
    input  logic       play_start_i,
    input  logic [1:0] play_song_i,
    input  logic       play_loop_i,
    output logic       busy_o,
    output logic       done_o,
    output logic       beep_o
);
    localparam logic [1:0] SONG_BACKGROUND = 2'd0;
    localparam logic [1:0] SONG_WIN        = 2'd1;
    localparam logic [1:0] SONG_FAIL       = 2'd2;

    // Divide before multiplying to avoid 32-bit int overflow at 50 MHz.
    localparam int UNIT_CYCLES = (CLK_HZ / (TEMPO_BPM * 4)) * 60;
    localparam int NOTE_GAP_CYCLES = (CLK_HZ / 1000) * NOTE_GAP_MS;
    localparam int COLLISION_CYCLES = (CLK_HZ / 1000) * COLLISION_MS;
    localparam int COLLISION_HALF_CYCLES = CLK_HZ / (COLLISION_HZ * 2);

    localparam logic [1:0] MODE_IDLE      = 2'd0;
    localparam logic [1:0] MODE_SONG      = 2'd1;
    localparam logic [1:0] MODE_COLLISION = 2'd2;

    localparam int NOTE_CODE_W = {note_code_w};
{note_defs}

    localparam int BG_NOTE_COUNT   = {len(BG_MELODY)};
    localparam int WIN_NOTE_COUNT  = {len(WIN_MELODY)};
    localparam int FAIL_NOTE_COUNT = {len(FAIL_MELODY)};
    localparam int NOTE_INDEX_W    = {index_w};

    logic [1:0] active_song;
    logic       active_loop;
    logic [1:0] play_mode;
    logic       resume_song_after_collision;

    logic [NOTE_INDEX_W-1:0] note_index;
    logic [NOTE_CODE_W-1:0] current_note;
    logic [3:0] current_units;

    logic [31:0] duration_cnt;
    logic [31:0] tone_cnt;
    logic [31:0] collision_cnt;
    logic [31:0] collision_tone_cnt;
    logic        beep_raw;

    assign beep_o = BUZZER_ACTIVE_LOW ? ~beep_raw : beep_raw;

    function automatic int half_cycles_for_note(input logic [NOTE_CODE_W-1:0] note);
        begin
            unique case (note)
{freq_cases}
                default: half_cycles_for_note = 1;
            endcase
        end
    endfunction

    function automatic int duration_cycles(input logic [3:0] units);
        begin
            duration_cycles = UNIT_CYCLES * int'(units);
        end
    endfunction

    function automatic int sound_cycles(input logic [3:0] units);
        int total_cycles;
        begin
            total_cycles = duration_cycles(units);
            if (total_cycles > NOTE_GAP_CYCLES) begin
                sound_cycles = total_cycles - NOTE_GAP_CYCLES;
            end else begin
                sound_cycles = total_cycles;
            end
        end
    endfunction

{chr(10).join(note_funcs)}
{chr(10).join(unit_funcs)}
    function automatic int song_len(input logic [1:0] song);
        begin
            unique case (song)
                SONG_WIN:  song_len = WIN_NOTE_COUNT;
                SONG_FAIL: song_len = FAIL_NOTE_COUNT;
                default:   song_len = BG_NOTE_COUNT;
            endcase
        end
    endfunction

    function automatic logic [NOTE_CODE_W-1:0] song_note(input logic [1:0] song, input int idx);
        begin
            unique case (song)
                SONG_WIN:  song_note = win_note(idx);
                SONG_FAIL: song_note = fail_note(idx);
                default:   song_note = bg_note(idx);
            endcase
        end
    endfunction

    function automatic logic [3:0] song_units(input logic [1:0] song, input int idx);
        begin
            unique case (song)
                SONG_WIN:  song_units = win_units(idx);
                SONG_FAIL: song_units = fail_units(idx);
                default:   song_units = bg_units(idx);
            endcase
        end
    endfunction

    task automatic load_note(input logic [1:0] song, input int idx);
        begin
            current_note  <= song_note(song, idx);
            current_units <= song_units(song, idx);
            duration_cnt  <= '0;
            tone_cnt      <= '0;
            beep_raw      <= 1'b0;
        end
    endtask

    always_ff @(posedge clk_i) begin
        if (rst_i) begin
            busy_o <= 1'b0;
            done_o <= 1'b0;
            beep_raw <= 1'b0;
            play_mode <= MODE_IDLE;
            active_song <= SONG_BACKGROUND;
            active_loop <= 1'b0;
            resume_song_after_collision <= 1'b0;
            note_index <= '0;
            current_note <= NOTE_REST;
            current_units <= 4'd1;
            duration_cnt <= '0;
            tone_cnt <= '0;
            collision_cnt <= '0;
            collision_tone_cnt <= '0;
        end else begin
            done_o <= 1'b0;

            if (stop_i) begin
                busy_o <= 1'b0;
                beep_raw <= 1'b0;
                play_mode <= MODE_IDLE;
                active_song <= SONG_BACKGROUND;
                active_loop <= 1'b0;
                resume_song_after_collision <= 1'b0;
                note_index <= '0;
                current_note <= NOTE_REST;
                current_units <= 4'd1;
                duration_cnt <= '0;
                tone_cnt <= '0;
                collision_cnt <= '0;
                collision_tone_cnt <= '0;
            end else if (play_start_i) begin
                busy_o <= 1'b1;
                active_song <= play_song_i;
                active_loop <= play_loop_i;
                play_mode <= MODE_SONG;
                resume_song_after_collision <= 1'b0;
                note_index <= '0;
                load_note(play_song_i, 0);
            end else begin
                unique case (play_mode)
                    MODE_IDLE: begin
                        busy_o <= 1'b0;
                        beep_raw <= 1'b0;
                        if (collision_start_i) begin
                            busy_o <= 1'b1;
                            play_mode <= MODE_COLLISION;
                            collision_cnt <= '0;
                            collision_tone_cnt <= '0;
                        end
                    end

                    MODE_COLLISION: begin
                        if (collision_tone_cnt >= (COLLISION_HALF_CYCLES - 1)) begin
                            collision_tone_cnt <= '0;
                            beep_raw <= ~beep_raw;
                        end else begin
                            collision_tone_cnt <= collision_tone_cnt + 1'b1;
                        end

                        if (collision_cnt >= (COLLISION_CYCLES - 1)) begin
                            collision_cnt <= '0;
                            collision_tone_cnt <= '0;
                            beep_raw <= 1'b0;
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

                    MODE_SONG: begin
                        if (collision_start_i && (active_song == SONG_BACKGROUND)) begin
                            busy_o <= 1'b1;
                            beep_raw <= 1'b0;
                            play_mode <= MODE_COLLISION;
                            resume_song_after_collision <= 1'b1;
                            collision_cnt <= '0;
                            collision_tone_cnt <= '0;
                        end else begin
                            if ((current_note == NOTE_REST) || (duration_cnt >= sound_cycles(current_units))) begin
                                beep_raw <= 1'b0;
                                tone_cnt <= '0;
                            end else if (tone_cnt >= (half_cycles_for_note(current_note) - 1)) begin
                                tone_cnt <= '0;
                                beep_raw <= ~beep_raw;
                            end else begin
                                tone_cnt <= tone_cnt + 1'b1;
                            end

                            if (duration_cnt >= (duration_cycles(current_units) - 1)) begin
                                if (int'(note_index) == (song_len(active_song) - 1)) begin
                                    if (active_loop) begin
                                        note_index <= '0;
                                        load_note(active_song, 0);
                                    end else begin
                                        busy_o <= 1'b0;
                                        done_o <= 1'b1;
                                        beep_raw <= 1'b0;
                                        play_mode <= MODE_IDLE;
                                        note_index <= '0;
                                        current_note <= NOTE_REST;
                                        current_units <= 4'd1;
                                        duration_cnt <= '0;
                                        tone_cnt <= '0;
                                    end
                                end else begin
                                    note_index <= note_index + 1'b1;
                                    load_note(active_song, int'(note_index) + 1);
                                end
                            end else begin
                                duration_cnt <= duration_cnt + 1'b1;
                            end
                        end
                    end

                    default: begin
                        busy_o <= 1'b0;
                        beep_raw <= 1'b0;
                        play_mode <= MODE_IDLE;
                    end
                endcase
            end
        end
    end
endmodule
"""
    SV_PATH.write_text(sv, encoding="ascii")


def square_tone(freq_hz: int, duration_s: float, amplitude: int = 68) -> bytes:
    count = max(1, round(duration_s * SAMPLE_RATE_HZ))
    if freq_hz <= 0:
        return bytes([128] * count)
    data = bytearray()
    for index in range(count):
        phase = 2.0 * math.pi * freq_hz * index / SAMPLE_RATE_HZ
        value = 128 + (amplitude if math.sin(phase) >= 0.0 else -amplitude)
        data.append(max(0, min(255, round(value))))
    return bytes(data)


def render(path: Path, melody: list[tuple[str, int]]) -> None:
    PREVIEW_DIR.mkdir(parents=True, exist_ok=True)
    frames = bytearray()
    for note, units in melody:
        duration_s = UNIT_S * units
        gap_s = min(duration_s, NOTE_GAP_MS / 1000.0)
        if note == "REST":
            frames.extend(square_tone(0, duration_s))
        else:
            frames.extend(square_tone(NOTE_HZ[note], duration_s - gap_s))
            frames.extend(square_tone(0, gap_s))
    with wave.open(str(path), "wb") as wav:
        wav.setnchannels(1)
        wav.setsampwidth(1)
        wav.setframerate(SAMPLE_RATE_HZ)
        wav.writeframes(bytes(frames))
    print(f"{path} duration_s={len(frames) / SAMPLE_RATE_HZ:.3f}")


def main() -> None:
    write_sv()
    render(PREVIEW_DIR / "see_you_again_note_player_preview.wav", BG_MELODY)
    render(PREVIEW_DIR / "cancan_win_note_player_preview.wav", WIN_MELODY)
    render(PREVIEW_DIR / "fail_note_player_preview.wav", FAIL_MELODY)


if __name__ == "__main__":
    main()
