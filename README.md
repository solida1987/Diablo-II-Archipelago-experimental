# Diablo II Archipelago — Experimental

Experimental build line for the Diablo II Archipelago mod. This is the
**aggressive-testing sandbox** — expect breakage. It is never promoted to
stable; good findings get ported back into the stable build instead.

Stable build: https://github.com/solida1987/Diablo-II-Archipelago

Releases here use the **EX** version line (starting EX 1.0.0).

## The Multiworld Launcher is required

Like the stable line, this mod is built for the
[**Multiworld Launcher**](https://github.com/solida1987/Multiworld-Launcher) and
does not work without it. The launcher *is* the randomizer: it writes the seed,
patches the data tables, injects the mod, holds the Archipelago connection and
tracks your checks. Nothing installs or runs the mod on its own.

The launcher is a **separate download from its own project**
([releases](https://github.com/solida1987/Multiworld-Launcher/releases/latest),
version **3.4.0 or newer** — the current plugin refuses to load on anything older) and ships with no games in it. This build line
arrives as a plugin: download
**`diablo2_archipelago_experimental-*.londonplugin`** from
[this repository's latest release](https://github.com/solida1987/Diablo-II-Archipelago-experimental/releases/latest),
click **Add plugin…** in the launcher, read the dialog, and approve it. The
experimental channel installs next to the stable one and shares nothing with
it — separate install, separate saves.

The 1.10f requirement and everything else about running the mod are documented
in the stable repository's README. The plugin's source is in `plugin/`.

## Required: a DirectDraw wrapper (cnc-ddraw)

**The game will not start without this one.** Diablo II 1.10f is from 2003 and
its own DirectDraw no longer initialises on Windows 10 or 11 — without a wrapper
it stops with *"Error 22: A critical error has occurred while initializing
DirectDraw"* before the main menu.

The mod does not include one. Install it yourself:

1. Download **cnc-ddraw** from
   https://github.com/FunkyFr3sh/cnc-ddraw/releases/latest
2. Open the zip and copy **`ddraw.dll`** (and `ddraw.ini` if present) into your
   **game folder** — the folder holding `Diablo II.exe`. The launcher opens it
   for you from **Open game folder**.
3. Press Play.

cnc-ddraw is free and open source (MIT) by FunkyFr3sh. If your own Diablo II
installation already has a `ddraw.dll`, the launcher copies that one across
automatically and there is nothing to download. If it cannot find one anywhere,
it stops before launching and tells you this rather than letting the game fail
with an error box that explains nothing.

## Optional: HD graphics, free resolution and 3D sound

Three well-known Diablo II community projects make the game look and sound
considerably better. **They are not distributed with this mod** — you download
them yourself, from their authors, under their own licences. That is deliberate:
they are licensed GPL-3.0, AGPL-3.0 and LGPL-2.1, and those licences place
conditions on *distributing* the software that this project is not in a position
to meet. Using them alongside this mod is entirely your right as a user; handing
them out is what carries obligations.

All three are optional. Skip them and the game still runs, just at the original
resolution and without 3D sound.

Everything goes in the **same place**: your game folder, the one holding
`Diablo II.exe`. The launcher opens it for you from **Open game folder**. No
subfolders, no installers — the files sit next to the game.

### D2GL — HD rendering, widescreen, filtering, higher frame rates

Download: **https://github.com/bayaraa/d2gl/releases/latest**

The zip has everything at the top level. Copy these three into the game folder:

| File | |
|---|---|
| `ddraw.dll` | the renderer |
| `glide3x.dll` | what `-3dfx` loads — the launcher looks for this one |
| `d2gl.mpq` | its data, ~65 MB |

> **D2GL also satisfies the DirectDraw requirement.** Its `ddraw.dll` is a
> DirectDraw wrapper in its own right, so if you install D2GL you do not need
> cnc-ddraw as well — one or the other is enough.

### SGD2FreeRes — removes the fixed-resolution limit

Download: **https://github.com/mir-diablo-ii-tools/SlashGaming-Diablo-II-Free-Resolution/releases/latest**

> **Take the "Vanilla" download, not "Modders".** Installing an add-on into a
> mod makes "Modders" look like the obvious choice, and it is the wrong one: that
> build ships its graphics in a `data/` folder you are expected to repack into
> `patch_d2.mpq` yourself. The Vanilla build works by dropping the files in,
> which is what this mod's settings are written for.

From the Vanilla zip, copy `SGD2FreeRes.dll` and `SGD2FreeRes.mpq` into the game
folder.

Note that SGD2FreeRes does nothing on its own — **D2GL is what loads it**,
through `load_dlls_late` in `d2gl.ini`. Install it without D2GL and its files sit
there doing nothing. The launcher says so if that happens, rather than leaving
you to guess.

### DSOAL — restores the original 3D positional audio

Download: **https://github.com/kcat/dsoal/releases/latest**

This one takes the most steps, because the download is a zip inside a zip:

1. Extract `DSOAL.zip`. Inside is a single file, `DSOAL_r694.zip` (the number
   changes between releases).
2. Extract that one too. You now have two folders: `DSOAL` and `DSOAL+HRTF`.
   Either works — HRTF adds headphone positional audio. Pick one.
3. Open the **`Win32`** folder inside it.
4. Copy `dsound.dll`, `dsoal-aldrv.dll` and `alsoft.ini` into the game folder.

> **It must be `Win32`, not `Win64`.** Diablo II 1.10f is a 32-bit program, so
> the 64-bit build simply will not load — and on a modern machine `Win64` is the
> folder people reach for first. If your 3D sound does not work, this is almost
> always why.

### After installing

Start the launcher and look at **Settings → Diablo II Archipelago**. The
**Optional add-ons** section lists all three and says which ones it can see, so
you can check the install landed before you play. There is a **Check again**
button, so you can drop files in with the launcher still open.

A complete install of all three looks like this in your game folder:

```
ddraw.dll          d2gl.mpq           SGD2FreeRes.mpq
glide3x.dll        SGD2FreeRes.dll    dsound.dll
dsoal-aldrv.dll    alsoft.ini
```

This mod ships tuned settings for them — `d2gl.ini`, `d2gl.json` and
`SGD2FreeResolution.json` — so once the files are in, the configuration is
already the one this mod expects. Those are settings files, not the programs.

Read each project's own licence and documentation. They are separate works by
separate authors; this project is not affiliated with them and does not speak
for them.

## Archipelago Discord Notice

I have been permanently banned from the official Archipelago Discord server.
Because of this, please do not post or share links to this project on the
official Archipelago Discord, as this project is not permitted there.

For clarity, the ban was not related to malware, viruses, malicious code, or
any security issue with this project.

The moderation issues were related to:

* Copyright/distribution concerns involving game files in earlier versions of
  my projects. Those files were removed, the affected repositories and
  releases were cleaned up, and the distribution process was changed
  accordingly.
* Violations of the Discord server's own content rules, including
  links/content involving games that were restricted or considered 18+ under
  their server rules.

These issues relate to the official Archipelago Discord's moderation and
content policies.

Development and support for this project will continue independently outside
of the official Archipelago Discord.

---

## AI Usage Disclosure

Everything in this project was made by AI.

The code is AI.
The documentation is AI.
The artwork is AI.
I am AI.
My mother and father are also AI.

At this point, just assume everything is AI unless proven otherwise.

