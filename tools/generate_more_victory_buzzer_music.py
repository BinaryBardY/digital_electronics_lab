#!/usr/bin/env python3
"""Generate several public-domain victory music options for the buzzer player."""

from __future__ import annotations

import math
import wave
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "music" / "win_choices"

SAMPLE_RATE_HZ = 4000
CENTER = 128
AMPLITUDE = 76

NOTE_INDEX = {"C": 0, "D": 2, "E": 4, "F": 5, "G": 7, "A": 9, "B": 11}


def note_hz(note: str) -> float:
    if note == "R":
        return 0.0

    name = note[0]
    pos = 1
    accidental = 0
    if pos < len(note) and note[pos] in "#b":
        accidental = 1 if note[pos] == "#" else -1
        pos += 1

    octave = int(note[pos:])
    midi = 12 * (octave + 1) + NOTE_INDEX[name] + accidental
    return 440.0 * (2.0 ** ((midi - 69) / 12.0))


def make_tone(freq_hz: float, duration_s: float, amp: int = AMPLITUDE) -> bytes:
    count = max(1, round(duration_s * SAMPLE_RATE_HZ))
    if freq_hz <= 0.0:
        return bytes([CENTER] * count)

    fade_count = min(count // 4, round(0.010 * SAMPLE_RATE_HZ))
    data = bytearray()
    for index in range(count):
        env = 1.0
        if fade_count > 0:
            env = min(env, index / fade_count)
            env = min(env, (count - 1 - index) / fade_count)
        env = max(0.0, min(1.0, env))

        phase = 2.0 * math.pi * freq_hz * index / SAMPLE_RATE_HZ
        sine = math.sin(phase)
        square = 1.0 if sine >= 0.0 else -1.0
        value = CENTER + amp * env * (0.60 * square + 0.40 * sine)
        data.append(max(0, min(255, round(value))))
    return bytes(data)


def render(filename: str, beat_s: float, melody: list[tuple[str, float]], gap_s: float = 0.014) -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    frames = bytearray()
    for note, beats in melody:
        frames.extend(make_tone(note_hz(note), beat_s * beats))
        if gap_s > 0.0:
            frames.extend(make_tone(0.0, gap_s))

    out_path = OUT_DIR / filename
    with wave.open(str(out_path), "wb") as wav:
        wav.setnchannels(1)
        wav.setsampwidth(1)
        wav.setframerate(SAMPLE_RATE_HZ)
        wav.writeframes(bytes(frames))

    print(f"{out_path} duration_s={len(frames) / SAMPLE_RATE_HZ:.3f}")


def main() -> None:
    # Based on the public-domain traditional congratulatory tune.
    jolly_good_fellow = [
        ("D5", 1), ("B4", 2), ("B4", 1), ("B4", 1), ("A4", 1), ("B4", 1),
        ("C5", 3), ("B4", 2), ("B4", 1),
        ("A4", 2), ("A4", 1), ("A4", 1), ("G4", 1), ("A4", 1),
        ("B4", 3), ("G4", 2), ("A4", 1),
        ("B4", 2), ("B4", 1), ("B4", 1), ("A4", 1), ("B4", 1),
        ("C5", 3), ("E5", 2), ("E5", 1),
        ("D5", 1), ("E5", 1), ("D5", 1), ("C5", 1), ("B4", 1), ("A4", 1),
        ("G4", 3), ("G4", 2), ("B4", 1),
        ("D5", 1), ("D5", 1), ("D5", 1), ("E5", 2), ("E5", 1),
        ("D5", 3), ("D5", 2), ("D5", 1),
        ("B4", 1), ("B4", 1), ("B4", 1), ("C5", 2), ("C5", 1),
        ("B4", 3), ("B4", 1), ("G4", 1), ("A4", 1),
        ("B4", 2), ("B4", 1), ("B4", 1), ("A4", 1), ("B4", 1),
        ("C5", 3), ("B4", 2), ("B4", 1),
        ("A4", 2), ("A4", 1), ("A4", 1), ("G4", 1), ("A4", 1),
        ("B4", 3), ("G4", 2), ("A4", 1),
        ("B4", 2), ("B4", 1), ("B4", 1), ("A4", 1), ("B4", 1),
        ("C5", 2), ("D5", 1), ("E5", 2), ("E5", 1),
        ("D5", 1), ("E5", 1), ("D5", 1), ("C5", 2), ("A4", 1),
        ("G4", 6),
    ]
    render("win_jolly_good_fellow_buzzer.wav", 0.095, jolly_good_fellow)

    # Offenbach "Can-Can" / Infernal Galop, simplified from public ABC sources.
    can_can = [
        ("A5", 2), ("A5", 2), ("A5", 2), ("A5", 2),
        ("A5", 1), ("E5", 1), ("E5", 1), ("F#5", 1), ("E5", 1), ("D5", 1), ("D5", 1), ("F#5", 1),
        ("G5", 1), ("G5", 1), ("B5", 1), ("D6", 1), ("B5", 1), ("A5", 1), ("A5", 2),
        ("B5", 1), ("C#6", 1), ("C#6", 1), ("B5", 1), ("A5", 1), ("D5", 1), ("D5", 1), ("F#5", 1),
        ("F#5", 1), ("E5", 1), ("F#5", 1), ("E5", 1), ("F#5", 1), ("E5", 1), ("F#5", 1), ("E5", 1),
        ("F#5", 2), ("D5", 2), ("B4", 2), ("A4", 2),
        ("A4", 1), ("E5", 1), ("F#5", 1), ("G5", 1), ("F#5", 1), ("E5", 1), ("D5", 2),
        ("F#5", 2), ("D5", 2), ("B4", 2), ("A4", 2),
        ("G#5", 1), ("A5", 1), ("B5", 1), ("C#6", 1), ("D6", 2), ("D6", 2),
        ("D6", 1), ("A5", 1), ("C#6", 1), ("A5", 1), ("D6", 1), ("A5", 1), ("C#6", 1), ("A5", 1),
        ("D6", 1), ("D6", 1), ("D6", 1), ("D6", 1), ("D6", 1), ("D6", 1), ("D6", 1), ("D6", 1),
    ]
    render("win_cancan_buzzer.wav", 0.082, can_can)

    # Traditional gospel/spiritual melody, commonly used as a celebratory march.
    saints = [
        ("G4", 1), ("B4", 1), ("C5", 1.5), ("D5", 0.5), ("E5", 2),
        ("G4", 1), ("B4", 1), ("C5", 1.5), ("D5", 0.5), ("E5", 2),
        ("G4", 1), ("B4", 1), ("C5", 1.5), ("D5", 0.5), ("E5", 1),
        ("B4", 1), ("G4", 1), ("B4", 1), ("A4", 3),
        ("B4", 1), ("B4", 1), ("A4", 1), ("G4", 1), ("G4", 1), ("B4", 1), ("E5", 1), ("E5", 1),
        ("D5", 1), ("C5", 1), ("C5", 1), ("B4", 1), ("C5", 1.5), ("D5", 0.5), ("E5", 2),
        ("G4", 1), ("B4", 1), ("C5", 1.5), ("D5", 0.5), ("E5", 1),
        ("B4", 1), ("G4", 1), ("A4", 1), ("G4", 4),
        ("R", 0.4),
        ("G5", 0.5), ("E5", 0.5), ("D5", 0.5), ("C5", 0.5), ("B4", 1), ("C5", 1), ("D5", 1), ("E5", 2),
    ]
    render("win_saints_marching_buzzer.wav", 0.155, saints)

    # A compact William Tell Finale style victory gallop, arranged as a monophonic
    # buzzer cue rather than a recording.
    william_tell = [
        ("E5", 0.5), ("E5", 0.5), ("E5", 0.5), ("E5", 0.5), ("G5", 1), ("C6", 1),
        ("E6", 0.5), ("D6", 0.5), ("C6", 0.5), ("G5", 0.5), ("E5", 2),
        ("G5", 0.5), ("G5", 0.5), ("G5", 0.5), ("G5", 0.5), ("C6", 1), ("E6", 1),
        ("G6", 0.5), ("E6", 0.5), ("C6", 0.5), ("G5", 0.5), ("C6", 2),
        ("E6", 0.5), ("E6", 0.5), ("D6", 0.5), ("C6", 0.5), ("D6", 0.5), ("C6", 0.5), ("B5", 0.5), ("A5", 0.5),
        ("G5", 0.5), ("A5", 0.5), ("B5", 0.5), ("C6", 0.5), ("D6", 1), ("G5", 1),
        ("C6", 0.5), ("C6", 0.5), ("D6", 0.5), ("E6", 0.5), ("G6", 1), ("E6", 1),
        ("C6", 0.5), ("G5", 0.5), ("E5", 0.5), ("G5", 0.5), ("C6", 3),
    ]
    render("win_william_tell_gallop_buzzer.wav", 0.145, william_tell)


if __name__ == "__main__":
    main()
