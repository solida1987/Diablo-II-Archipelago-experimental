/* Ascension — virtual difficulty tiers stacked on top of Hell.
 *
 * WHY THIS SHAPE
 *
 * Diablo II cannot be given a fourth difficulty. The number three is not a
 * setting, it is the data model: levels.txt carries 36 per-difficulty COLUMNS
 * (MonLvl1/2/3, mon/nmon/umon, MonDen(N)/(H), SizeX(N)/(H) …), the .d2s format
 * has exactly three quest / waypoint / NPC-intro blocks, and D2Launch's
 * difficulty screen is three hardcoded controls. Even Median XL never added
 * one. Full reasoning: docs/RESEARCH_BEYOND_HELL.md §1.
 *
 * So the engine keeps running Hell and WE keep a tier number. A tier is a
 * complete replay of the game: the map has to be rediscovered, the waypoints
 * have to be found again, the zone-lock keys have to be earned again. The one
 * thing that is NOT repeated is the main quest — which is exactly why the acts
 * can be taken in any order the player likes.
 *
 * THE FREE PART
 *
 * Because Hell has been completed, all five acts already stand open on Hell
 * (act access follows the permanent per-difficulty quest progression). The
 * "any act order" that makes a tier feel different from a normal playthrough
 * costs no code at all — it falls out of stacking on a finished Hell.
 *
 * WHAT IS DELIBERATELY NEVER TOUCHED
 *
 * D2's own quest flags. They are what holds the acts open (above), and writing
 * them would make Akara and Cain offer their quests again. That is the same
 * area that broke the Cain quest for a tester on 2026-08-11 — not a door worth
 * reopening for the 27 story checks it would buy back.
 *
 * EXPERIMENTAL LINE ONLY until Marco has tested it here.
 */

/* Tier 0 == plain Hell. MAX is a sanity bound, not a design limit: the YAML
 * option decides how many a seed actually offers. */
#define ASC_MAX_TIER 10

static int  g_ascensionTier = 0;   /* which tier the character is playing NOW */
static int  g_ascensionMax  = 0;   /* highest tier unlocked so far */
static int  g_ascensionOffered = 0; /* how many tiers this seed offers (slot_data) */

/* Baal — "Eve of Destruction". Completing it on Hell opens Ascension I, and
 * completing it inside tier N opens tier N+1. Same quest id either way: the
 * engine is always in Hell, only our tier number moves. */
#define ASC_BAAL_QID 406

static const char* Ascension_RomanName(int tier) {
    static const char* names[ASC_MAX_TIER + 1] = {
        "", "Ascension I", "Ascension II", "Ascension III", "Ascension IV",
        "Ascension V", "Ascension VI", "Ascension VII", "Ascension VIII",
        "Ascension IX", "Ascension X"
    };
    if (tier < 0 || tier > ASC_MAX_TIER) return "";
    return names[tier];
}

/* "Hell" or "Hell - Ascension III", for the HUD and the book. */
static const char* Ascension_DifficultyLabel(int diff) {
    static char buf[48];
    /* g_diffNames is `static` in d2arch_quests.c; this file is included after
     * it in the unity build, so it is simply in scope — no extern. */
    if (diff != 2 || g_ascensionTier <= 0) return g_diffNames[(diff >= 0 && diff <= 2) ? diff : 0];
    _snprintf(buf, sizeof(buf), "%s - %s", g_diffNames[2], Ascension_RomanName(g_ascensionTier));
    buf[sizeof(buf) - 1] = 0;
    return buf;
}

/* Is `tier` playable for this character right now? Tier 0 (Hell) always is;
 * tier N needs tier N-1 finished AND the seed to actually offer it. */
static BOOL Ascension_IsUnlocked(int tier) {
    if (tier <= 0) return TRUE;
    if (tier > ASC_MAX_TIER || tier > g_ascensionOffered) return FALSE;
    return tier <= g_ascensionMax;
}

/* Called from the quest-completion path when a Baal kill is credited.
 *
 * Guarded on difficulty 2 because a tier IS Hell — a Baal kill on Normal or
 * Nightmare says nothing about ascension. */
static void Ascension_OnBaalCompleted(int diff) {
    if (diff != 2) return;
    int want = g_ascensionTier + 1;
    if (want > ASC_MAX_TIER) return;
    if (want <= g_ascensionMax) return;          /* already open — replaying a tier */
    g_ascensionMax = want;
    Log("ASCENSION: Baal completed at tier %d -> tier %d unlocked (max=%d, seed offers %d)\n",
        g_ascensionTier, want, g_ascensionMax, g_ascensionOffered);
    if (want <= g_ascensionOffered) {
        char msg[96];
        _snprintf(msg, sizeof(msg), "%s unlocked - choose it from the character screen",
                  Ascension_RomanName(want));
        msg[sizeof(msg) - 1] = 0;
        ShowNotify(msg);
    }
}

/* Reset to a clean slate. Called on character switch, exactly like the rest of
 * the per-character globals — a tier belongs to ONE character. */
static void Ascension_ResetForNewCharacter(void) {
    g_ascensionTier = 0;
    g_ascensionMax  = 0;
}
