# Diablo II Archipelago — Experimental

Experimental build line for the Diablo II Archipelago mod. This is the
**aggressive-testing sandbox** — expect breakage. It is never promoted to
stable; good findings get ported back into the stable build instead.

Stable build: https://github.com/solida1987/Diablo-II-Archipelago

Releases here use the **EX** version line (starting EX 1.0.0).

Installation, the 1.10f requirement and everything else about running the mod
are documented in the stable repository's README. This build line installs the
same way, through the Multiworld Launcher.

## Optional: HD graphics, free resolution and 3D sound

The mod runs on its own. Three well-known Diablo II community projects make it
look and sound considerably better, and **they are not distributed with this
mod** — you install them yourself, from their authors, under their own
licences. That is deliberate: they are licensed GPL-3.0, AGPL-3.0 and LGPL-2.1,
and those licences place conditions on *distributing* the software that this
project is not in a position to meet. Using them alongside this mod is entirely
your right as a user; handing them out is what carries obligations.

Everything below is optional. Skip it and the game still runs — just at the
original resolution, on Diablo II's own renderer.

| Project | What it adds | Where to get it |
|---|---|---|
| **D2GL** by Bayaraa | HD rendering, widescreen, filtering, higher frame rates | https://github.com/bayaraa/d2gl |
| **SGD2FreeRes** by Mir Drualga | Removes the fixed-resolution limit | https://github.com/SlashGaming/SlashGaming-Diablo-II-Free-Resolution |
| **DSOAL** | Restores the original 3D positional audio | https://github.com/kcat/dsoal |

**How to install them**

1. Download the release you want from the project's own page above.
2. Extract it and copy its files into your **game folder** — the folder holding
   `Diablo II.exe`, which the launcher opens for you from **Open game folder**.
3. Start the game as usual.

The launcher checks for `glide3x.dll` (part of D2GL) each time it starts the
game. Find it and it uses the Glide renderer, so D2GL takes over; don't find it
and it quietly falls back to DirectDraw. Nothing to configure either way.

This mod ships tuned settings for them — `d2gl.ini`, `d2gl.json` and
`SGD2FreeResolution.json` — so once you drop the files in, the configuration is
already the one this mod expects. Those are settings files, not the programs.

Read each project's own licence and documentation. They are separate works by
separate authors; this project is not affiliated with them and does not speak
for them.

## AI Usage Disclosure

AI-assisted tools are used throughout parts of this project as productivity
tools.

This includes, but is not limited to:

- Artwork and other visual assets
- Translation between Danish and English
- Discord messages and community communication
- Patch notes, documentation and release notes
- Source-code comments and other explanatory text
- General text editing, rewriting and formatting

AI tools may also be used as part of the overall development workflow.
Regardless of what tools are used during development, I remain responsible for
the project, its implementation, testing, releases and any code that is
distributed.

My native language is Danish, so AI is particularly useful for quickly
converting what I want to say into readable English instead of spending a large
amount of development time translating and rewriting everything manually.

AI-generated or AI-assisted visual assets may also be used where appropriate. I
am not an artist, and these tools allow me to create artwork for areas of the
project that would otherwise have little or no custom artwork.

This disclosure is here so there is no ambiguity about the use of AI-assisted
tools in the project.
