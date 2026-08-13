# Diablo II Archipelago

A randomizer mod for **Diablo II: Lord of Destruction (1.10f)** with [Archipelago](https://archipelago.gg/) multiworld support.

Randomizes skill unlocks across a quest system spanning all 5 Acts and 3 difficulties. Complete quests, hunts, zone clears and more to earn skills from any of the 7 character classes. Play solo with your own settings, or connect to an Archipelago multiworld server for cross-game randomization.

The mod is installed and run through the **Multiworld Launcher** — the launcher controls all randomization (settings, seed, AP connection); there is no in-game login to deal with.

---

## Download & Install

1. Download **launcher_package.zip** from the [latest release](https://github.com/solida1987/Diablo-II-Archipelago/releases/latest).
2. Extract it to a folder of your choice.
3. Run **`Multiworld Launcher.exe`**.
4. In the launcher, select **Diablo II Archipelago** and click **Install** — the launcher downloads and installs the game automatically.
5. The launcher keeps itself and the game up to date (game updates are an optional button; the launcher updates itself).

> You can also get the launcher on its own from the [Multiworld Launcher releases](https://github.com/solida1987/Multiworld-Launcher/releases/latest) and install Diablo from there — both routes give you the same thing.

### Requirements
- Windows 10 / 11
- A valid, legally-owned copy of **Diablo II** + **Lord of Destruction** (the original Blizzard game data is required — it is **not** included).

### Antivirus & Windows SmartScreen

Some antivirus tools and Windows SmartScreen may flag **`Multiworld Launcher.exe`** the first time you run it. **This is a false positive.** The launcher is a brand-new application that Windows doesn't recognise yet, and unrecognised, unsigned programs are flagged by default until they build up reputation — regardless of what they actually contain. It is safe to run.

This is being addressed on two fronts: the application has been submitted to Microsoft for review, and Windows SmartScreen builds trust automatically as more people download and run it, so the warning clears on its own over time. *(A commercial code-signing certificate would remove the warning instantly, but it carries a significant recurring cost, so we're pursuing the free Microsoft review and reputation route first.)*

**To run it:** on the SmartScreen prompt click **"More info"** → **"Run anyway"**. If your antivirus quarantines the file, restore it or add an exception.

---

## How to Play

Everything is driven from the launcher — pick **Diablo II Archipelago**, then choose one of:

### Standalone (singleplayer)
1. Click **Standalone**.
2. Choose your options (goal, quest categories, skill pool, collection/custom goal, shuffles, etc.) or **load a previous seed** from the list on the right.
3. Click launch and create/select a character. Each seed keeps its own characters.

### Archipelago multiworld
1. Enter your Archipelago room's **server address**, **slot name** and **password** in the launcher.
2. Click **AP Play**.
3. The launcher connects and launches the game already hooked up to the multiworld — checks, items, goal and (optional) DeathLink all flow through the launcher.

> **Tip:** the launcher's **Locations** tracker works in both modes — in standalone it shows the full location universe (every category, all difficulties) just like an AP session.

---

## Features

- **210 skills** from all 7 classes randomized into a quest-reward pool.
- **Hundreds of checks** across 5 Acts × 3 difficulties: Story, Hunts, Clear Zones, Exploration, Waypoints, Level Milestones — plus optional Shrines, Urns, Barrels, Chests, Set Pickups, Gold Milestones, Cow Level, Mercenary, Hellforge & Runes, NPC Dialogue, Runewords and Cube Recipes.
- **Goals:** finish on Normal / Nightmare / Hell, a **Collection** goal, or build your own **Custom** win condition.
- **Skill Editor** (F1 page 1) and **Skill Tree** (S) — assign and spend points on your unlocked skills.
- **Quest Book** (F1 page 2) — scrollable log with filter tabs and act/difficulty selection.
- **Monster Shuffle**, **Boss Shuffle**, **Shop Shuffle**, **Entrance Shuffle** (all optional).
- **Zone-Locking mode** — zone keys gate area access for exploration-focused runs.
- **XP Multiplier** (1×–10×), expanded inventory/stash/cube, HD graphics (d2gl).
- **Delta updates** — only changed files are downloaded when the game updates.

---

## Controls

| Key | Action |
|-----|--------|
| F1 | Skill Editor (page 1) · Quest Book (page 2) |
| S | Open Skill Tree (spend skill points) |
| F3 | Toggle Quest Tracker HUD |
| F4 | Zone Map (Zone-Locking mode) |
| Ctrl+O | Graphics Settings (d2gl) |
| ESC | Close any open panel |

---

## Built With

- [D2MOO](https://github.com/nicodoctor/D2MOO) — open-source Diablo II reimplementation
- [D2.Detours](https://github.com/nicodoctor/D2.Detours) — DLL patching framework
- [d2gl](https://github.com/nicodoctor/d2gl) — HD graphics renderer
- [Archipelago](https://archipelago.gg/) — multiworld randomizer framework

## Credits

- **solida1987** — project lead, game systems, quest design, AP integration
- **ꓘicka** & **Zoë** — Archipelago logic (regions & rules)
- **D2MOO Team** — open-source Diablo II reimplementation
- **Archipelago Community** — multiworld framework and support
- **Diablo II Modding Community** — research, tools and documentation

## License

This project is a modification for Diablo II: Lord of Destruction. A legal copy of the original game is required to play.

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
