# yt-dlp-cli

A simple C command-line interface — a thin menu wrapper around [`yt-dlp`](https://github.com/yt-dlp/yt-dlp). It delegates all actual downloading to `yt-dlp` via `system()` calls.

## Features

- List available formats for a given YouTube URL
- Download the best available video quality (capped at 720p)
- Download audio only (converted to MP3)
- Download using a specific format code
- Simple, looping terminal menu

## Requirements

- A C compiler (`gcc` or `clang`)
- [CMake](https://cmake.org/) (>= 3.10 recommended)
- [`yt-dlp`](https://github.com/yt-dlp/yt-dlp) installed and available on your system PATH
- `ffmpeg` installed (required by yt-dlp's `--audio-format mp3` option)
- **Linux or macOS** (the code uses POSIX headers; it won't compile natively on Windows — see the note below)

## Building

### With CMake (recommended)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This produces the `ytdlp-cli` executable inside the `build` directory.

To install it system-wide (so you can run `ytdlp-cli` from anywhere):

```bash
sudo cmake --install .
# or, equivalently:
sudo make install
```

This installs the binary to `bin` under your CMake install prefix (typically `/usr/local/bin`).

### With gcc directly

```bash
gcc -o ytdlp-cli main.c
```

## Usage

```bash
./ytdlp-cli
```

The program repeatedly prompts for a YouTube URL, then shows a menu:

```
1. List available formats
2. Download video (best quality)
3. Download audio only (mp3)
4. Download specific format
5. Exit
```

- **1** — Lists available format codes using `yt-dlp -F`
- **2** — Downloads the video with `yt-dlp -f 'best[height<=720]'`
- **3** — Downloads audio as MP3 with `yt-dlp -x --audio-format mp3`
- **4** — Downloads using the format code you enter (`yt-dlp -f '<code>'`)
- **5** — Exits the program

## Platform note

The code calls `system("clear")` to clear the screen, which is a Unix/Linux command. As written, it works directly on **Linux and macOS**. On native Windows, `clear` isn't a recognized command, so the screen-clearing step will silently fail (the rest of the program still runs).

## License
Make sure to give heavyweaponsguy a sandwich.
