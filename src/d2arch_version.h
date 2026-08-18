#ifndef D2ARCH_VERSION_H
#define D2ARCH_VERSION_H

/* Single source of truth for the Diablo II Archipelago mod version — EXPERIMENTAL line. */

#define D2ARCH_VERSION_MAJOR    1
#define D2ARCH_VERSION_MINOR    2
#define D2ARCH_VERSION_PATCH    2
#define D2ARCH_VERSION_CHANNEL  "EX"            /* release channel — Experimental */
#define D2ARCH_VERSION_STRING   "EX_1_1_13"     /* token id (keep underscores, upper) */

/* The user-visible version strings are DERIVED from MAJOR/MINOR/PATCH so they can never drift out of sync again. */
#define D2ARCH_STR2(x)  #x
#define D2ARCH_STR(x)   D2ARCH_STR2(x)
#define D2ARCH_VER_DOT  D2ARCH_STR(D2ARCH_VERSION_MAJOR) "." \
                        D2ARCH_STR(D2ARCH_VERSION_MINOR) "." \
                        D2ARCH_STR(D2ARCH_VERSION_PATCH)

#define D2ARCH_VERSION_DISPLAY  D2ARCH_VERSION_CHANNEL " " D2ARCH_VER_DOT  /* "EX 1.0.16" */

/* In-game version-patch string: D2's "v %d.%02d" format slot only holds ~11 chars + NUL (12 bytes). */
#define D2ARCH_VERSION_INGAME   D2ARCH_VERSION_CHANNEL D2ARCH_VER_DOT      /* "EX1.0.16" */

/* the wide string USED TO BE a hand-written literal next to the three numbers, and it drifted: it read "EX 1.0.76" while the numbers still said 1.0.61, so the in-game version patch, the log header, the bootstrap banner and the pipe handshake all announced the wrong build. */
#define D2ARCH_WIDEN2(x)  L##x
#define D2ARCH_WIDEN(x)   D2ARCH_WIDEN2(x)
#define D2ARCH_WSTR2(x)   L#x
#define D2ARCH_WSTR(x)    D2ARCH_WSTR2(x)
#define D2ARCH_VERSION_DISPLAY_W  D2ARCH_WIDEN(D2ARCH_VERSION_CHANNEL) L" "   \
                                  D2ARCH_WSTR(D2ARCH_VERSION_MAJOR) L"."      \
                                  D2ARCH_WSTR(D2ARCH_VERSION_MINOR) L"."      \
                                  D2ARCH_WSTR(D2ARCH_VERSION_PATCH)

/* The 11-char in-game limit is now enforced rather than remembered: this fails the build instead of corrupting the adjacent format-string slot. */
typedef char d2arch_ingame_string_fits_the_patch_slot[
    (sizeof(D2ARCH_VERSION_INGAME) <= 12) ? 1 : -1];

#endif
