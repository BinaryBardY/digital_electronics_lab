#!/usr/bin/env python3
"""Generate a happy victory melody for the passive buzzer PCM player."""

from __future__ import annotations

import math
import wave
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT_DIR = ROOT / "music" / "win_joy"
OUT_WAV = OUT_DIR / "win_joy_ode_to_joy_buzzer.wav"

SAMPLE_RATE_HZ = 4000
CENTER = 128
AMPLITUDE = 78

NOTE_HZ = {
    "C5": 523.25,
    "D5": 587.33,
    "E5": 659.25,
    "F5": 698.46,
    "G5": 783.99,
    "A5": 880.00,
    "C6": 1046.50,
    "D6": 1174.66,
    "E6": 1318.51,
    "R": 0.0,
}

# Public-domain "Ode to Joy" melody, trimmed and lifted into a buzzer-friendly
# register, followed by a short bright cadence for a victory feel.
# Format: note name, beat length. One beat is BEAT_S seconds.
BEAT_S = 0.22
MELODY = [
    ("E5", 1), ("E5", 1), ("F5", 1), ("G5", 1),
    ("G5", 1), ("F5", 1), ("E5", 1), ("D5", 1),
    ("C5", 1), ("C5", 1), ("D5", 1), ("E5", 1),
    ("E5", 1.5), ("D5", 0.5), ("D5", 2),
    ("R", 0.35),
    ("E5", 1), ("E5", 1), ("F5", 1), ("G5", 1),
    ("G5", 1), ("F5", 1), ("E5", 1), ("D5", 1),
    ("C5", 1), ("C5", 1), ("D5", 1), ("E5", 1),
    ("D5", 1.5), ("C5", 0.5), ("C5", 2),
    ("R", 0.35),
    ("D5", 1), ("D5", 1), ("E5", 1), ("C5", 1),
    ("D5", 1), ("E5", 0.5), ("F5", 0.5), ("E5", 1), ("C5", 1),
    ("D5", 1), ("E5", 0.5), ("F5", 0.5), ("E5", 1), ("D5", 1),
    ("C5", 1), ("D5", 1), ("G5", 1.5),
    ("R", 0.25),
    ("G5", 0.5), ("C6", 0.5), ("D6", 0.5), ("E6", 1.5),
    ("D6", 0.5), ("C6", 0.5), ("G5", 0.5), ("C6", 2.0),
]


def make_tone(freq_hz: float, duration_s: float) -> bytes:
    count = max(1, round(duration_s * SAMPLE_RATE_HZ))
    if freq_hz <= 0.0:
        return bytes([CENTER] * count)

    fade_count = min(count // 4, round(0.012 * SAMPLE_RATE_HZ))
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
        # Square carries well on passive buzzers; sine softens the edge a bit.
        value = CENTER + AMPLITUDE * env * (0.62 * square + 0.38 * sine)
        data.append(max(0, min(255, round(value))))
    return bytes(data)


def main() -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)

    frames = bytearray()
    for note, beats in MELODY:
        frames.extend(make_tone(NOTE_HZ[note], BEAT_S * beats))
        frames.extend(make_tone(0.0, 0.018))

    with wave.open(str(OUT_WAV), "wb") as wav:
        wav.setnchannels(1)
        wav.setsampwidth(1)
        wav.setframerate(SAMPLE_RATE_HZ)
        wav.writeframes(bytes(frames))

    print(OUT_WAV)
    print(f"duration_s={len(frames) / SAMPLE_RATE_HZ:.3f}")
    print(f"bytes={len(frames)}")


if __name__ == "__main__":
    main()
