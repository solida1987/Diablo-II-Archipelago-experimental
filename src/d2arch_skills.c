/* SKILL DATABASE - All 210 class skills */
typedef struct {
    int id;
    const char* name;
    const char* classCode; /* ama,sor,nec,pal,bar,dru,ass */
    int tier; /* 1=T1(basic), 2=T2(mid), 3=T3(advanced) */
} SkillEntry;

/* Extra info loaded from Skills.txt at runtime */
typedef struct {
    int reqlevel;
    int manaCost;
    char elemType[8];  /* fire, ltng, cold, pois, mag, "" */
    int eMin, eMax;
} SkillExtraInfo;

static SkillExtraInfo g_skillExtra[D2ARCH_MAX_SKILLS] = {0}; /* indexed by skill ID */
static BOOL g_skillExtraLoaded = FALSE;

static const char* FullClassName(const char* code) {
    if (!code) return "Unknown";
    if (strcmp(code, "ama") == 0) return "Amazon";
    if (strcmp(code, "sor") == 0) return "Sorceress";
    if (strcmp(code, "nec") == 0) return "Necromancer";
    if (strcmp(code, "pal") == 0) return "Paladin";
    if (strcmp(code, "bar") == 0) return "Barbarian";
    if (strcmp(code, "dru") == 0) return "Druid";
    if (strcmp(code, "ass") == 0) return "Assassin";
    return code;
}

static void LoadSkillExtraInfo(void) {
    if (g_skillExtraLoaded) return;
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    char* sl = strrchr(path, '\\');
    if (sl) {
        int remaining = MAX_PATH - (int)(sl - path) - 1;
        if (remaining > 28) strcpy(sl + 1, "data\\global\\excel\\Skills.txt");
        else return;
    }

    FILE* f = fopen(path, "r");
    if (!f) { Log("LoadSkillExtra: cannot open %s\n", path); return; }

    char line[4096];
    /* Read header to find column indices */
    if (!fgets(line, sizeof(line), f)) { fclose(f); return; }

    int colId = -1, colReqLevel = -1, colMana = -1, colEType = -1, colEMin = -1, colEMax = -1;
    {
        char* tok = strtok(line, "\t\r\n");
        int col = 0;
        while (tok) {
            if (strcmp(tok, "Id") == 0) colId = col;
            else if (strcmp(tok, "reqlevel") == 0) colReqLevel = col;
            else if (strcmp(tok, "mana") == 0) colMana = col;
            else if (strcmp(tok, "EType") == 0) colEType = col;
            else if (strcmp(tok, "EMin") == 0) colEMin = col;
            else if (strcmp(tok, "EMax") == 0) colEMax = col;
            tok = strtok(NULL, "\t\r\n");
            col++;
        }
    }

    if (colId < 0) { fclose(f); return; }

    /* Read data rows */
    int loaded = 0;
    while (fgets(line, sizeof(line), f)) {
        char* fields[300] = {0};
        int nf = 0;
        char* p = line;
        while (nf < 300) {
            fields[nf] = p;
            char* tab = strchr(p, '\t');
            if (tab) { *tab = 0; p = tab + 1; }
            else { char* nl = strchr(p, '\r'); if (nl) *nl = 0; nl = strchr(p, '\n'); if (nl) *nl = 0; nf++; break; }
            nf++;
        }

        int id = (colId < nf && fields[colId][0]) ? atoi(fields[colId]) : -1;
        if (id < 0 || id >= D2ARCH_MAX_SKILLS) continue;

        g_skillExtra[id].reqlevel = (colReqLevel >= 0 && colReqLevel < nf) ? atoi(fields[colReqLevel]) : 0;
        g_skillExtra[id].manaCost = (colMana >= 0 && colMana < nf) ? atoi(fields[colMana]) : 0;
        g_skillExtra[id].eMin = (colEMin >= 0 && colEMin < nf) ? atoi(fields[colEMin]) : 0;
        g_skillExtra[id].eMax = (colEMax >= 0 && colEMax < nf) ? atoi(fields[colEMax]) : 0;
        if (colEType >= 0 && colEType < nf && fields[colEType][0]) {
            strncpy(g_skillExtra[id].elemType, fields[colEType], 7);
        }
        loaded++;
    }
    fclose(f);
    g_skillExtraLoaded = TRUE;
    Log("LoadSkillExtra: loaded %d skills from Skills.txt\n", loaded);
}

/* Tier assignment: based on row position in original skill tree Row 1-2 = T1 (skills 1-6 per class roughly) Row 3-4 = T2 (skills 7-16 per class roughly) Row 5-6 = T3 (skills 17-30 per class roughly) Each class has 30 skills, ~10 per tier */

/* Opt-in gate for the id>=357 experimental wave. */
BOOL g_experimentalSpells      = FALSE;
BOOL g_experimentalSpellsKnown = FALSE;   /* TRUE once explicitly set */

void SetExperimentalSpells(BOOL on) {
    g_experimentalSpells      = on;
    g_experimentalSpellsKnown = TRUE;
}

/* Resolve from d2arch.ini when nobody has set it yet (order-independent). */
static void EnsureExperimentalSpellsResolved(void) {
    char iniPath[MAX_PATH];
    if (g_experimentalSpellsKnown) return;
    GetArchDir(iniPath, MAX_PATH);
    strcat(iniPath, "d2arch.ini");
    g_experimentalSpells      = GetPrivateProfileIntA("settings", "ExperimentalSpells",
                                                      0, iniPath) != 0;
    g_experimentalSpellsKnown = TRUE;
    Log("ExperimentalSpells resolved from ini: %d\n", g_experimentalSpells ? 1 : 0);
}

static const SkillEntry g_skillDB[] = {
    /* === AMAZON (ama) === */
    {6,"Magic Arrow","ama",1}, {7,"Fire Arrow","ama",1}, {8,"Inner Sight","ama",1},
    {9,"Critical Strike","ama",1}, {10,"Jab","ama",1}, {11,"Cold Arrow","ama",1},
    {12,"Multiple Shot","ama",1}, {13,"Dodge","ama",1}, {14,"Power Strike","ama",1},
    {15,"Poison Javelin","ama",1},
    {16,"Exploding Arrow","ama",2}, {17,"Slow Missiles","ama",2}, {18,"Avoid","ama",2},
    {19,"Impale","ama",2}, {20,"Lightning Bolt","ama",2}, {21,"Ice Arrow","ama",2},
    {22,"Guided Arrow","ama",2}, {23,"Penetrate","ama",2}, {24,"Charged Strike","ama",2},
    {25,"Plague Javelin","ama",2},
    {26,"Strafe","ama",3}, {27,"Immolation Arrow","ama",3}, {28,"Decoy","ama",3},
    {29,"Evade","ama",3}, {30,"Fend","ama",3}, {31,"Freezing Arrow","ama",3},
    {32,"Valkyrie","ama",3}, {33,"Pierce","ama",3}, {34,"Lightning Strike","ama",3},
    {35,"Lightning Fury","ama",3},

    /* === SORCERESS (sor) === */
    {36,"Fire Bolt","sor",1}, {37,"Warmth","sor",1}, {38,"Charged Bolt","sor",1},
    {39,"Ice Bolt","sor",1}, {40,"Frozen Armor","sor",1}, {41,"Inferno","sor",1},
    {42,"Static Field","sor",1}, {43,"Telekinesis","sor",1}, {44,"Frost Nova","sor",1},
    {45,"Ice Blast","sor",1},
    {46,"Blaze","sor",2}, {47,"Fire Ball","sor",2}, {48,"Nova","sor",2},
    {49,"Lightning","sor",2}, {50,"Shiver Armor","sor",2}, {51,"Fire Wall","sor",2},
    {52,"Enchant","sor",2}, {53,"Chain Lightning","sor",2}, {54,"Teleport","sor",2},
    {55,"Glacial Spike","sor",2},
    {56,"Meteor","sor",3}, {57,"Thunder Storm","sor",3}, {58,"Energy Shield","sor",3},
    {59,"Blizzard","sor",3}, {60,"Chilling Armor","sor",3}, {61,"Fire Mastery","sor",3},
    {62,"Hydra","sor",3}, {63,"Lightning Mastery","sor",3}, {64,"Frozen Orb","sor",3},
    {65,"Cold Mastery","sor",3},

    /* === NECROMANCER (nec) === */
    {66,"Amplify Damage","nec",1}, {67,"Teeth","nec",1}, {68,"Bone Armor","nec",1},
    {69,"Skeleton Mastery","nec",1}, {70,"Raise Skeleton","nec",1}, {71,"Dim Vision","nec",1},
    {72,"Weaken","nec",1}, {73,"Poison Dagger","nec",1}, {74,"Corpse Explosion","nec",1},
    {75,"Clay Golem","nec",1},
    {76,"Iron Maiden","nec",2}, {77,"Terror","nec",2}, {78,"Bone Wall","nec",2},
    {79,"Golem Mastery","nec",2}, {80,"Raise Skeletal Mage","nec",2}, {81,"Confuse","nec",2},
    {82,"Life Tap","nec",2}, {83,"Poison Explosion","nec",2}, {84,"Bone Spear","nec",2},
    {85,"Blood Golem","nec",2},
    {86,"Attract","nec",3}, {87,"Decrepify","nec",3}, {88,"Bone Prison","nec",3},
    {89,"Summon Resist","nec",3}, {90,"Iron Golem","nec",3}, {91,"Lower Resist","nec",3},
    {92,"Poison Nova","nec",3}, {93,"Bone Spirit","nec",3}, {94,"Fire Golem","nec",3},
    {95,"Revive","nec",3},

    /* === PALADIN (pal) === */
    {96,"Sacrifice","pal",1}, {97,"Smite","pal",1}, {98,"Might","pal",1},
    {99,"Prayer","pal",1}, {100,"Resist Fire","pal",1}, {101,"Holy Bolt","pal",1},
    {102,"Holy Fire","pal",1}, {103,"Thorns","pal",1}, {104,"Defiance","pal",1},
    {105,"Resist Cold","pal",1},
    {106,"Zeal","pal",2}, {107,"Charge","pal",2}, {108,"Blessed Aim","pal",2},
    {109,"Cleansing","pal",2}, {110,"Resist Lightning","pal",2}, {111,"Vengeance","pal",2},
    {112,"Blessed Hammer","pal",2}, {113,"Concentration","pal",2}, {114,"Holy Freeze","pal",2},
    {115,"Vigor","pal",2},
    {116,"Conversion","pal",3}, {117,"Holy Shield","pal",3}, {118,"Holy Shock","pal",3},
    {119,"Sanctuary","pal",3}, {120,"Meditation","pal",3}, {121,"Fist of the Heavens","pal",3},
    {122,"Fanaticism","pal",3}, {123,"Conviction","pal",3}, {124,"Redemption","pal",3},
    {125,"Salvation","pal",3},

    /* === BARBARIAN (bar) === */
    /* Spear Mastery moved from T1 to T2 to rebalance the barb's 11+9+10 tier distribution to 10+10+10. */
    {126,"Bash","bar",1}, {127,"Sword Mastery","bar",1}, {128,"Axe Mastery","bar",1},
    {129,"Mace Mastery","bar",1}, {130,"Howl","bar",1}, {131,"Find Potion","bar",1},
    {132,"Leap","bar",1}, {133,"Double Swing","bar",1}, {134,"Pole Arm Mastery","bar",1},
    {135,"Throwing Mastery","bar",1},
    {136,"Spear Mastery","bar",2}, {137,"Taunt","bar",2}, {138,"Shout","bar",2},
    {139,"Stun","bar",2}, {140,"Double Throw","bar",2}, {141,"Increased Stamina","bar",2},
    {142,"Find Item","bar",2}, {143,"Leap Attack","bar",2}, {144,"Concentrate","bar",2},
    {145,"Iron Skin","bar",2},
    {146,"Battle Cry","bar",3}, {147,"Frenzy","bar",3}, {148,"Increased Speed","bar",3},
    {149,"Battle Orders","bar",3}, {150,"Grim Ward","bar",3}, {151,"Whirlwind","bar",3},
    {152,"Berserk","bar",3}, {153,"Natural Resistance","bar",3}, {154,"War Cry","bar",3},
    {155,"Battle Command","bar",3},

    /* === DRUID (dru) === */
    {221,"Raven","dru",1}, {222,"Poison Creeper","dru",1}, {223,"Werewolf","dru",1},
    {224,"Lycanthropy","dru",1}, {225,"Firestorm","dru",1}, {226,"Oak Sage","dru",1},
    {227,"Summon Spirit Wolf","dru",1}, {228,"Werebear","dru",1}, {229,"Molten Boulder","dru",1},
    {230,"Arctic Blast","dru",1},
    {231,"Carrion Vine","dru",2}, {232,"Feral Rage","dru",2}, {233,"Maul","dru",2},
    {234,"Fissure","dru",2}, {235,"Cyclone Armor","dru",2}, {236,"Heart of Wolverine","dru",2},
    {237,"Summon Dire Wolf","dru",2}, {238,"Rabies","dru",2}, {239,"Fire Claws","dru",2},
    {240,"Twister","dru",2},
    {241,"Solar Creeper","dru",3}, {242,"Hunger","dru",3}, {243,"Shock Wave","dru",3},
    {244,"Volcano","dru",3}, {245,"Tornado","dru",3}, {246,"Spirit of Barbs","dru",3},
    {247,"Summon Grizzly","dru",3}, {248,"Fury","dru",3}, {249,"Armageddon","dru",3},
    {250,"Hurricane","dru",3},

    /* === ASSASSIN (ass) === */
    {251,"Fire Blast","ass",1}, {252,"Claw Mastery","ass",1}, {253,"Psychic Hammer","ass",1},
    {254,"Tiger Strike","ass",1}, {255,"Dragon Talon","ass",1}, {256,"Shock Web","ass",1},
    {257,"Blade Sentinel","ass",1}, {258,"Burst of Speed","ass",1}, {259,"Fists of Fire","ass",1},
    {260,"Dragon Claw","ass",1},
    {261,"Charged Bolt Sentry","ass",2}, {262,"Wake of Fire","ass",2},
    {263,"Weapon Block","ass",2}, {264,"Cloak of Shadows","ass",2}, {265,"Cobra Strike","ass",2},
    {266,"Blade Fury","ass",2}, {267,"Fade","ass",2}, {268,"Shadow Warrior","ass",2},
    {269,"Claws of Thunder","ass",2}, {270,"Dragon Tail","ass",2},
    {271,"Lightning Sentry","ass",3}, {272,"Wake of Inferno","ass",3},
    {273,"Mind Blast","ass",3}, {274,"Blades of Ice","ass",3}, {275,"Dragon Flight","ass",3},
    {276,"Death Sentry","ass",3}, {277,"Blade Shield","ass",3}, {278,"Venom","ass",3},
    {279,"Shadow Master","ass",3}, {280,"Phoenix Strike","ass",3},

    /* === EXPERIMENTAL WAVE 1 — new skills (ids 357+) === Only enter the pool when [settings] ExperimentalSpells=1 (standalone) or the AP option is on — see the g_experimentalSpells filter in InitSkillPool. */
    {357,"Test 1","sor",1},  {358,"Test 2","sor",2},  {359,"Test 3","sor",2},
    {360,"Test 4","sor",1},  {361,"Test 5","sor",1},  {362,"Test 6","sor",2},
    {363,"Test 7","sor",2},  {364,"Test 8","sor",1},  {365,"Test 9","sor",1},
    {366,"Test 10","sor",1}, {367,"Test 11","sor",2}, {368,"Test 12","sor",3},
    {369,"Test 13","sor",3}, {370,"Test 14","sor",2}, {371,"Test 15","sor",3},
    {372,"Test 16","sor",1}, {373,"Test 17","sor",3}, {374,"Test 18","sor",3},

    /* Wave 2, phase 1 — one skill per UNTESTED engine chassis (ids 377-402). */
    {377,"Chassis 1","sor",1},  {378,"Chassis 2","sor",1},
    {379,"Chassis 3","sor",1},  {380,"Chassis 4","sor",1},
    {381,"Chassis 5","sor",1},  {382,"Chassis 6","sor",1},
    {383,"Chassis 7","sor",1},  {384,"Chassis 8","sor",1},
    {385,"Chassis 9","sor",1},  {386,"Chassis 10","sor",1},
    {387,"Chassis 11","sor",1}, {388,"Chassis 12","sor",1},
    {389,"Chassis 13","sor",1}, {390,"Chassis 14","sor",1},
    {391,"Chassis 15","sor",1}, {392,"Chassis 16","sor",1},
    {393,"Chassis 17","sor",1}, {394,"Chassis 18","sor",1},
    {395,"Chassis 19","sor",1}, {396,"Chassis 20","sor",1},
    {397,"Chassis 21","sor",1}, {398,"Chassis 22","sor",1},
    {399,"Chassis 23","sor",1}, {400,"Chassis 24","sor",1},
    {401,"Chassis 25","sor",1}, {402,"Chassis 26","sor",1},

    /* Wave 2, phase 2 -- monster and boss abilities as player skills (ids 403-457). */
    {403,"Mon2 1","sor",1},       {404,"Mon2 2","sor",1},
    {405,"Mon2 3","sor",1},       {406,"Mon2 4","sor",1},
    {407,"Mon2 5","sor",1},       {408,"Mon2 6","sor",1},
    {409,"Mon2 7","sor",1},       {410,"Mon2 8","sor",1},
    {411,"Mon2 9","sor",1},       {412,"Mon2 10","sor",1},
    {413,"Mon2 11","sor",1},      {414,"Mon2 12","sor",1},
    {415,"Mon2 13","sor",1},      {416,"Mon2 14","sor",1},
    {417,"Mon2 15","sor",1},      {418,"Mon2 16","sor",1},
    {419,"Mon2 17","sor",1},      {420,"Mon2 18","sor",1},
    {421,"Mon2 19","sor",1},      {422,"Mon2 20","sor",1},
    {423,"Mon2 21","sor",1},      {424,"Mon2 22","sor",1},
    {425,"Mon2 23","sor",1},      {426,"Mon2 24","sor",1},
    {427,"Mon2 25","sor",1},      {428,"Mon2 26","sor",1},
    {429,"Mon2 27","sor",1},      {430,"Mon2 28","sor",1},
    {431,"Mon2 29","sor",1},      {432,"Mon2 30","sor",1},
    {433,"Mon2 31","sor",1},      {434,"Mon2 32","sor",1},
    {435,"Mon2 33","sor",1},      {436,"Mon2 34","sor",1},
    {437,"Mon2 35","sor",1},      {438,"Mon2 36","sor",1},
    {439,"Mon2 37","sor",1},      {440,"Mon2 38","sor",1},
    {441,"Mon2 39","sor",1},      {442,"Mon2 40","sor",1},
    {443,"Mon2 41","sor",1},      {444,"Mon2 42","sor",1},
    {445,"Mon2 43","sor",1},      {446,"Mon2 44","sor",1},
    {447,"Mon2 45","sor",1},      {448,"Mon2 46","sor",1},
    {449,"Mon2 47","sor",1},      {450,"Mon2 48","sor",1},
    {451,"Mon2 49","sor",1},      {452,"Mon2 50","sor",1},
    {453,"Mon2 51","sor",1},      {454,"Mon2 52","sor",1},
    {455,"Mon2 53","sor",1},      {456,"Mon2 54","sor",1},
    {457,"Mon2 55","sor",1},

    /* Wave 2, phase 3 -- 46 summons that keep their monster's abilities (ids 458-503). */
    {458,"Pet 1","sor",2},      {459,"Pet 2","sor",2},
    {460,"Pet 3","sor",2},      {461,"Pet 4","sor",2},
    {462,"Pet 5","sor",2},      {463,"Pet 6","sor",2},
    {464,"Pet 7","sor",2},      {465,"Pet 8","sor",2},
    {466,"Pet 9","sor",2},      {467,"Pet 10","sor",2},
    {468,"Pet 11","sor",2},     {469,"Pet 12","sor",2},
    {470,"Pet 13","sor",2},     {471,"Pet 14","sor",2},
    {472,"Pet 15","sor",2},     {473,"Pet 16","sor",2},
    {474,"Pet 17","sor",2},     {475,"Pet 18","sor",2},
    {476,"Pet 19","sor",2},     {477,"Pet 20","sor",2},
    {478,"Pet 21","sor",2},     {479,"Pet 22","sor",2},
    {480,"Pet 23","sor",2},     {481,"Pet 24","sor",2},
    {482,"Pet 25","sor",2},     {483,"Pet 26","sor",2},
    {484,"Pet 27","sor",2},     {485,"Pet 28","sor",2},
    {486,"Pet 29","sor",2},     {487,"Pet 30","sor",2},
    {488,"Pet 31","sor",2},     {489,"Pet 32","sor",2},
    {490,"Pet 33","sor",2},     {491,"Pet 34","sor",2},
    {492,"Pet 35","sor",2},     {493,"Pet 36","sor",2},
    {494,"Pet 37","sor",2},     {495,"Pet 38","sor",2},
    {496,"Pet 39","sor",2},     {497,"Pet 40","sor",2},
    {498,"Pet 41","sor",2},     {499,"Pet 42","sor",2},
    {500,"Pet 43","sor",2},     {501,"Pet 44","sor",2},
    {502,"Pet 45","sor",2},     {503,"Pet 46","sor",2},

    /* Wave 2, phase 4 -- 24 traps on the sentry chassis (ids 504-527). */
    {504,"Trap 1","sor",2},      {505,"Trap 2","sor",2},
    {506,"Trap 3","sor",2},      {507,"Trap 4","sor",2},
    {508,"Trap 5","sor",2},      {509,"Trap 6","sor",2},
    {510,"Trap 7","sor",2},      {511,"Trap 8","sor",2},
    {512,"Trap 9","sor",2},      {513,"Trap 10","sor",2},
    {514,"Trap 11","sor",2},     {515,"Trap 12","sor",2},
    {516,"Trap 13","sor",2},     {517,"Trap 14","sor",2},
    {518,"Trap 15","sor",2},     {519,"Trap 16","sor",2},
    {520,"Trap 17","sor",2},     {521,"Trap 18","sor",2},
    {522,"Trap 19","sor",2},     {523,"Trap 20","sor",2},
    {524,"Trap 21","sor",2},     {525,"Trap 22","sor",2},
    {526,"Trap 23","sor",2},     {527,"Trap 24","sor",2},

    /* Wave 2, phase 5 -- Aura of the Pantheon (id 531). */
    {531,"Pantheon","sor",3},

    /* Wave 2, phase 6 -- form transformations (ids 532-589). */
    {532,"Form 1","sor",2},      {533,"Form 2","sor",2},
    {534,"Form 3","sor",2},      {535,"Form 4","sor",2},
    {536,"Form 5","sor",2},      {537,"Form 6","sor",2},
    {538,"Form 7","sor",2},      {539,"Form 8","sor",2},
    {540,"Form 9","sor",2},      {541,"Form 10","sor",2},
    {542,"Form 11","sor",2},     {543,"Form 12","sor",2},
    {544,"Form 13","sor",2},     {545,"Form 14","sor",2},
    {546,"Form 15","sor",2},     {547,"Form 16","sor",2},
    {548,"Form 17","sor",2},     {549,"Form 18","sor",2},
    {550,"Form 19","sor",2},     {551,"Form 20","sor",2},
    {552,"Form 21","sor",2},     {553,"Form 22","sor",2},
    {554,"Form 23","sor",2},     {555,"Form 24","sor",2},
    {556,"Form 25","sor",2},     {557,"Form 26","sor",2},
    {558,"Form 27","sor",2},     {559,"Form 28","sor",2},
    {560,"Form 29","sor",2},     {561,"Form 30","sor",2},
    {562,"Form 31","sor",2},     {563,"Form 32","sor",2},
    {564,"Form 33","sor",2},     {565,"Form 34","sor",2},
    {566,"Form 35","sor",2},     {567,"Form 36","sor",2},
    {568,"Form 37","sor",2},     {569,"Form 38","sor",2},
    {570,"Form 39","sor",2},     {571,"Form 40","sor",2},
    {572,"Form 41","sor",2},     {573,"Form 42","sor",2},
    {574,"Form 43","sor",2},     {575,"Form 44","sor",2},
    {576,"Form 45","sor",2},     {577,"Form 46","sor",2},
    {578,"Form 47","sor",2},     {579,"Form 48","sor",2},
    {580,"Form 49","sor",2},     {581,"Form 50","sor",2},
    {582,"Form 51","sor",2},     {583,"Form 52","sor",2},
    {584,"Form 53","sor",2},     {585,"Form 54","sor",2},
    {586,"Form 55","sor",2},     {587,"Form 56","sor",2},
    {588,"Form 57","sor",2},     {589,"Form 58","sor",2},

    /* Wave 2, phase 7 -- the remainder of the approved list (ids 590-644): 16 ground fields, 8 charge-up chargers and finishers, 12 melee / mobility / crowd-control, and 19 auras and curses. */
    {590,"Fin 1","sor",2},      {591,"Fin 2","sor",2},
    {592,"Fin 3","sor",2},      {593,"Fin 4","sor",2},
    {594,"Fin 5","sor",2},      {595,"Fin 6","sor",2},
    {596,"Fin 7","sor",2},      {597,"Fin 8","sor",2},
    {598,"Fin 9","sor",2},      {599,"Fin 10","sor",2},
    {600,"Fin 11","sor",2},     {601,"Fin 12","sor",2},
    {602,"Fin 13","sor",2},     {603,"Fin 14","sor",2},
    {604,"Fin 15","sor",2},     {605,"Fin 16","sor",2},
    {606,"Fin 17","sor",2},     {607,"Fin 18","sor",2},
    {608,"Fin 19","sor",2},     {609,"Fin 20","sor",2},
    {610,"Fin 21","sor",2},     {611,"Fin 22","sor",2},
    {612,"Fin 23","sor",2},     {613,"Fin 24","sor",2},
    {614,"Fin 25","sor",2},     {615,"Fin 26","sor",2},
    {616,"Fin 27","sor",2},     {617,"Fin 28","sor",2},
    {618,"Fin 29","sor",2},     {619,"Fin 30","sor",2},
    {620,"Fin 31","sor",2},     {621,"Fin 32","sor",2},
    {622,"Fin 33","sor",2},     {623,"Fin 34","sor",2},
    {624,"Fin 35","sor",2},     {625,"Fin 36","sor",2},
    {626,"Fin 37","sor",2},     {627,"Fin 38","sor",2},
    {628,"Fin 39","sor",2},     {629,"Fin 40","sor",2},
    {630,"Fin 41","sor",2},     {631,"Fin 42","sor",2},
    {632,"Fin 43","sor",2},     {633,"Fin 44","sor",2},
    {634,"Fin 45","sor",2},     {635,"Fin 46","sor",2},
    {636,"Fin 47","sor",2},     {637,"Fin 48","sor",2},
    {638,"Fin 49","sor",2},     {639,"Fin 50","sor",2},
    {640,"Fin 51","sor",2},     {641,"Fin 52","sor",2},
    {642,"Fin 53","sor",2},     {643,"Fin 54","sor",2},
    {644,"Fin 55","sor",2},
    /* === WAVE 2 PHASE 8: morphs (icons Y1-Y30) === Werewolf-pipeline skins: monster look + temp stats, no abilities. */
    {645,"Morph 1","sor",2},    {646,"Morph 2","sor",2},
    {647,"Morph 3","sor",2},    {648,"Morph 4","sor",2},
    {649,"Morph 5","sor",2},    {650,"Morph 6","sor",2},
    {651,"Morph 7","sor",2},    {652,"Morph 8","sor",2},
    {653,"Morph 9","sor",2},    {654,"Morph 10","sor",2},
    {655,"Morph 11","sor",2},   {656,"Morph 12","sor",2},
    {657,"Morph 13","sor",2},   {658,"Morph 14","sor",2},
    {659,"Morph 15","sor",2},   {660,"Morph 16","sor",2},
    {661,"Morph 17","sor",2},   {662,"Morph 18","sor",3},
    {663,"Morph 19","sor",2},   {664,"Morph 20","sor",2},
    {665,"Morph 21","sor",2},   {666,"Morph 22","sor",2},
    {667,"Morph 23","sor",2},   {668,"Morph 24","sor",3},
    {669,"Morph 25","sor",2},   {670,"Morph 26","sor",2},
    {671,"Morph 27","sor",2},   {672,"Morph 28","sor",2},
    {673,"Morph 29","sor",2},   {674,"Morph 30","sor",3},
};

/* First id of the experimental wave — everything >= this is gated. */
#define EXPERIMENTAL_SKILL_ID_MIN 357

#define SKILL_DB_COUNT (sizeof(g_skillDB) / sizeof(g_skillDB[0]))

/* Player's skill pool — ALL 210 skills, 6 start unlocked */
/* Phase 0 (new-skills wave): capacity raised 210 -> 260. */
#define POOL_SIZE 600
#define NUM_STARTING 6

typedef struct {
    int dbIndex;     /* Index into g_skillDB */
    BOOL unlocked;   /* TRUE if available to assign */
    BOOL assigned;   /* TRUE if placed in a slot */
    int assignTab;   /* Tab 0-2 if assigned */
    int assignSlot;  /* Slot 0-9 if assigned */
} PoolSkill;

static PoolSkill g_pool[POOL_SIZE];
static int       g_poolCount = 0;
/* class fallback for InitSkillPool when the live player unit isn't up yet (GetPlayerClass()==-1 during the OnCharacterLoad window). */
static int       g_skillClassHint = -1;
static DWORD     g_seed = 0;
/* launcher-controlled standalone seed. */
static DWORD     g_standaloneSeed = 0;
static BOOL      g_poolInitialized = FALSE;

/* Tab/Slot assignments */
static int g_tabSlots[3][10]; /* skill DB index, -1 = empty */

/* Skill point tracking: how many points each skill had before reset. */
static int  g_reinvestSkills[30]; /* skill IDs to reinvest */
static int  g_reinvestPoints[30]; /* points per skill */
static int  g_reinvestBtnIdx[30]; /* original btnIdx (tab*10+slot) per reinvest entry. */
static int  g_reinvestCount = 0;  /* number of skills to reinvest */
static BOOL g_reinvestPending = FALSE;
static DWORD g_reinvestTime = 0;  /* when to start reinvesting */
static BOOL g_reinvestDone = FALSE; /* set TRUE after reinvest completes — triggers level reload */
static int  g_reinvestLevels[30] = {0}; /* levels loaded from files after reinvest */
static BOOL g_reinvestLevelsReady = FALSE; /* TRUE when g_reinvestLevels has fresh data */

/* Forward declaration - GetPlayerClass is defined later but needed here */
static int GetPlayerClass(void);

/* Assassin trap skills - "lay trap" animation only exists for Assassin class. */
static const int TRAP_SKILL_IDS[] = { 251, 256, 257, 261, 262, 266, 271, 272, 276, 277 };
#define TRAP_SKILL_COUNT 10

static BOOL IsAssassinTrapSkill(int skillId) {
    for (int i = 0; i < TRAP_SKILL_COUNT; i++)
        if (TRAP_SKILL_IDS[i] == skillId) return TRUE;
    return FALSE;
}

/* 1.9.5 Bugs 7-14 fix — skills whose animation sequence cannot be faithfully reproduced under the A1 cross-class fallback. */
static const int NATIVE_ONLY_SKILL_IDS[] = {
    /* Amazon — pure throwing javelins */
    15, 20, 25, 35,
    /* Paladin — shield-bash */
    97,
    /* Barbarian — sequence skills */
    133, 140, 143, 151,
    /* Druid — werewolf-form bites */
    238, 242,
    /* Assassin — kicks/claws/blade-fury/charge-up combo */
    255, 259, 260, 266, 269, 274,
};
#define NATIVE_ONLY_SKILL_COUNT \
    (sizeof(NATIVE_ONLY_SKILL_IDS) / sizeof(NATIVE_ONLY_SKILL_IDS[0]))

/* CLASS-LOCKED skill = a skill only its OWN class can use: the native-only set (class-specific animations) PLUS the assassin trap skills (the "lay trap" animation exists only for the Assassin; others go invisible). */
static BOOL IsClassLockedSkillId(int skillId) {
    int i;
    for (i = 0; i < (int)NATIVE_ONLY_SKILL_COUNT; i++)
        if (NATIVE_ONLY_SKILL_IDS[i] == skillId) return TRUE;
    if (IsAssassinTrapSkill(skillId)) return TRUE;
    return FALSE;
}

/* Convert int class id (0..6) to the SkillEntry classCode string. */
static const char* SkillClassCodeForId(int classId) {
    switch (classId) {
        case 0: return "ama";
        case 1: return "sor";
        case 2: return "nec";
        case 3: return "pal";
        case 4: return "bar";
        case 5: return "dru";
        case 6: return "ass";
        default: return NULL;
    }
}

/* SKILL RANDOMIZER */
/* RETIRED skills: rows that survive in the data but never join the pool. */
static int IsRetiredSkillId(int id) {
    switch (id) {
        case 378:  /* Chassis 2 == Bone Spirit (nec) */
        case 386:  /* Chassis 10 == Chain Lightning (sor) */
        case 387:  /* Chassis 11 == Frozen Orb (sor) */
        case 388:  /* Chassis 12 == Blade Shield (ass) */
        case 393:  /* Chassis 17 == Twister (dru) */
        case 426:  /* Mon2 24 == Power Strike (ama) */
        case 430:  /* Mon2 28 == Freezing Arrow (ama) */
            return 1;
        default:
            return 0;
    }
}

static void InitSkillPool(DWORD seed) {
    /* Phase 0: 70 -> 100 per tier. */
    static int t1[POOL_SIZE], t2[POOL_SIZE], t3[POOL_SIZE];
    int n1 = 0, n2 = 0, n3 = 0;
    int excludedNative = 0;

    /* All skills are now available for all classes. */

    /* 1.9.5 Bugs 7-14 — resolve player class for the native-only filter. */
    int playerClassId = GetPlayerClass();
    /* if the live player unit isn't ready (InitSkillPool ran during the OnCharacterLoad window before fnGetPlayer() returns the unit), fall back to the saved-character class hint LoadStateFile provided. */
    if (playerClassId < 0 && g_skillClassHint >= 0) playerClassId = g_skillClassHint;
    const char* playerClassCode = SkillClassCodeForId(playerClassId);

        /* Categorize all skills by tier */
    EnsureExperimentalSpellsResolved();
    int excludedExperimental = 0;
    int excludedRetired = 0;
    for (int i = 0; i < (int)SKILL_DB_COUNT; i++) {
        /* Experimental wave gate: ids >= 357 only join the pool when the player opted in (ini ExperimentalSpells / AP experimental_spell_pool). */
        if (!g_experimentalSpells && g_skillDB[i].id >= EXPERIMENTAL_SKILL_ID_MIN) {
            excludedExperimental++;
            continue;
        }
        /* Retired: a duplicate of a skill some class already has. */
        if (IsRetiredSkillId(g_skillDB[i].id)) { excludedRetired++; continue; }
        /* Class filter: skip skills from disabled classes (standalone only) */
        if (!g_apMode && g_classFilter && !IsClassEnabled(g_skillDB[i].classCode))
            continue;
        /* Exclude class-locked skills (native-only animations + assassin traps) unless this IS the player's own class — they can't be used cross-class and the apworld never places them, so a non-owner must not list them. */
        if (playerClassCode
            && strcmp(g_skillDB[i].classCode, playerClassCode) != 0
            && IsClassLockedSkillId(g_skillDB[i].id)) {
            excludedNative++;
            continue;
        }
        switch (g_skillDB[i].tier) {
            /* Bounds guards: a mis-tiered future skillDB must log, not smash the stack (the pre-Phase-0 arrays were exactly full — silent corruption waiting to happen). */
            case 1: if (n1 < (int)(sizeof(t1)/sizeof(t1[0]))) t1[n1++] = i;
                    else Log("InitSkillPool: tier1 FULL — skill idx %d dropped\n", i); break;
            case 2: if (n2 < (int)(sizeof(t2)/sizeof(t2[0]))) t2[n2++] = i;
                    else Log("InitSkillPool: tier2 FULL — skill idx %d dropped\n", i); break;
            case 3: if (n3 < (int)(sizeof(t3)/sizeof(t3[0]))) t3[n3++] = i;
                    else Log("InitSkillPool: tier3 FULL — skill idx %d dropped\n", i); break;
        }
    }
    if (excludedExperimental > 0) {
        Log("InitSkillPool: experimental wave OFF - %d new skills excluded\n",
            excludedExperimental);
    } else if (g_experimentalSpells) {
        /* The experimental pack is ALL-OR-NOTHING and sits ON TOP of the pool size, which counts vanilla skills only. */
        extern int g_apSkillPoolSize;
        int waveCount = 0;
        for (int wi = 0; wi < (int)SKILL_DB_COUNT; wi++)
            if (g_skillDB[wi].id >= EXPERIMENTAL_SKILL_ID_MIN) waveCount++;
        if (g_apSkillPoolSize > 0 && g_apSkillPoolSize + waveCount <= POOL_SIZE) {
            Log("InitSkillPool: experimental pack ON - cap %d + %d new = %d\n",
                g_apSkillPoolSize, waveCount, g_apSkillPoolSize + waveCount);
            g_apSkillPoolSize += waveCount;
        } else {
            /* No usable cap (0 = unset, or cap+wave would exceed the arrays): fall back to SKILL_DB_COUNT, not POOL_SIZE. */
            Log("InitSkillPool: experimental pack ON - cap lifted to %d (all skills)\n",
                (int)SKILL_DB_COUNT);
            g_apSkillPoolSize = (int)SKILL_DB_COUNT;
        }
    }
    if (excludedNative > 0) {
        Log("InitSkillPool: excluded %d cross-class-broken skills (player=%s)\n",
            excludedNative, playerClassCode ? playerClassCode : "?");
    }

    /* Fisher-Yates shuffle each tier */
    srand(seed);
    for (int i = n1 - 1; i > 0; i--) { int j = rand() % (i + 1); int tmp = t1[i]; t1[i] = t1[j]; t1[j] = tmp; }
    for (int i = n2 - 1; i > 0; i--) { int j = rand() % (i + 1); int tmp = t2[i]; t2[i] = t2[j]; t2[j] = tmp; }
    for (int i = n3 - 1; i > 0; i--) { int j = rand() % (i + 1); int tmp = t3[i]; t3[i] = t3[j]; t3[j] = tmp; }

    /* the skill-pool slider governs MEMBERSHIP, not just display. */
    if (!g_apMode) {
        extern int g_apSkillPoolSize;
        int limit = g_apSkillPoolSize;
        int vc[3] = {0, 0, 0};
        int* tt[3] = {t1, t2, t3};
        int* nn[3] = {&n1, &n2, &n3};
        for (int t = 0; t < 3; t++)
            for (int i = 0; i < *nn[t]; i++) {
                int id = g_skillDB[tt[t][i]].id;
                BOOL ownLk = playerClassCode
                    && strcmp(g_skillDB[tt[t][i]].classCode, playerClassCode) == 0
                    && IsClassLockedSkillId(id);
                if (id < EXPERIMENTAL_SKILL_ID_MIN && !ownLk) vc[t]++;
            }
        int vtotal = vc[0] + vc[1] + vc[2];
        if (limit > 0 && limit < vtotal) {
            /* Largest-remainder split of the quota across tiers. */
            int q[3], rem[3], given = 0;
            for (int t = 0; t < 3; t++) {
                q[t] = (limit * vc[t]) / vtotal;
                rem[t] = (limit * vc[t]) % vtotal;
                given += q[t];
            }
            while (given < limit) {
                int best = 0;
                for (int t = 1; t < 3; t++) if (rem[t] > rem[best]) best = t;
                if (q[best] < vc[best]) { q[best]++; given++; }
                rem[best] = -1;
                if (rem[0] < 0 && rem[1] < 0 && rem[2] < 0) break;
            }
            for (int t = 0; t < 3; t++) {
                int kept = 0, w = 0, quota = q[t];
                for (int i = 0; i < *nn[t]; i++) {
                    int dbi = tt[t][i];
                    int id = g_skillDB[dbi].id;
                    BOOL ownLk = playerClassCode
                        && strcmp(g_skillDB[dbi].classCode, playerClassCode) == 0
                        && IsClassLockedSkillId(id);
                    BOOL keep;
                    if (id >= EXPERIMENTAL_SKILL_ID_MIN || ownLk) keep = TRUE;
                    else if (kept < quota) { keep = TRUE; kept++; }
                    else keep = FALSE;
                    if (keep) tt[t][w++] = dbi;
                }
                *nn[t] = w;
            }
            Log("InitSkillPool: pool slider=%d applied — tiers now %d/%d/%d "
                "(vanilla quota %d/%d/%d, class-locked + wave kept on top)\n",
                limit, n1, n2, n3, q[0], q[1], q[2]);
        }
    }

    /* Take ALL skills from each tier — shuffled order determines unlock priority. */
    g_poolCount = 0;
    for (int i = 0; i < n1; i++) {
        int dbIdx = t1[i];
        /* class-locked skills (native-only anims + Assassin traps) are granted FREE to the OWNING class in BOTH AP and standalone (was gated on g_apMode, so standalone players never got their own class-specific skills auto-unlocked — Marco). */
        BOOL ownLocked = playerClassCode
            && strcmp(g_skillDB[dbIdx].classCode, playerClassCode) == 0
            && IsClassLockedSkillId(g_skillDB[dbIdx].id);
        g_pool[g_poolCount].dbIndex = dbIdx;
        g_pool[g_poolCount].unlocked = ownLocked || (g_apMode ? FALSE : (i < g_apStartingSkills));
        g_pool[g_poolCount].assigned = FALSE;
        g_pool[g_poolCount].assignTab = -1;
        g_pool[g_poolCount].assignSlot = -1;
        g_poolCount++;
    }
    for (int i = 0; i < n2; i++) {
        int dbIdx = t2[i];
        /* class-locked skills (native-only anims + Assassin traps) are granted FREE to the OWNING class in BOTH AP and standalone (was gated on g_apMode, so standalone players never got their own class-specific skills auto-unlocked — Marco). */
        BOOL ownLocked = playerClassCode
            && strcmp(g_skillDB[dbIdx].classCode, playerClassCode) == 0
            && IsClassLockedSkillId(g_skillDB[dbIdx].id);
        g_pool[g_poolCount].dbIndex = dbIdx;
        g_pool[g_poolCount].unlocked = ownLocked;
        g_pool[g_poolCount].assigned = FALSE;
        g_pool[g_poolCount].assignTab = -1;
        g_pool[g_poolCount].assignSlot = -1;
        g_poolCount++;
    }
    for (int i = 0; i < n3; i++) {
        int dbIdx = t3[i];
        /* class-locked skills (native-only anims + Assassin traps) are granted FREE to the OWNING class in BOTH AP and standalone (was gated on g_apMode, so standalone players never got their own class-specific skills auto-unlocked — Marco). */
        BOOL ownLocked = playerClassCode
            && strcmp(g_skillDB[dbIdx].classCode, playerClassCode) == 0
            && IsClassLockedSkillId(g_skillDB[dbIdx].id);
        g_pool[g_poolCount].dbIndex = dbIdx;
        g_pool[g_poolCount].unlocked = ownLocked;
        g_pool[g_poolCount].assigned = FALSE;
        g_pool[g_poolCount].assignTab = -1;
        g_pool[g_poolCount].assignSlot = -1;
        g_poolCount++;
    }

    /* Clear tab slots */
    for (int t = 0; t < 3; t++)
        for (int s = 0; s < 10; s++)
            g_tabSlots[t][s] = -1;

    g_seed = seed;
    g_poolInitialized = TRUE;
    Log("Skill pool initialized: seed=%u, %d skills (%d unlocked)\n", seed, g_poolCount, NUM_STARTING);
}

/* Accessors for d2arch_customgoal.c (which is included earlier in the unity build than skills.c so it can't reach the static globals directly). */
int Skills_GetPoolCount(void) { return g_poolCount; }
int Skills_GetUnlockedCount(void) {
    int n = 0;
    for (int i = 0; i < g_poolCount; i++) {
        if (g_pool[i].unlocked) n++;
    }
    return n;
}

/* class id (from player unit dwClassId) -> skill DB class code. */
static const char* ClassIdToCode(int classId) {
    switch (classId) {
        case 0: return "ama";
        case 1: return "sor";
        case 2: return "nec";
        case 3: return "pal";
        case 4: return "bar";
        case 5: return "dru";
        case 6: return "ass";
        default: return NULL;
    }
}

/* Skill Hunting = OFF path — no shuffle, no drag-drop, no cross-class. */
static void InitClassOnlySkills(int classId) {
    const char* code = ClassIdToCode(classId);
    if (!code) {
        Log("InitClassOnlySkills: unknown classId=%d — falling back to InitSkillPool\n", classId);
        InitSkillPool(GetTickCount());
        return;
    }

    int t1Idx[10], t2Idx[10], t3Idx[10];
    int n1 = 0, n2 = 0, n3 = 0;

    for (int i = 0; i < (int)SKILL_DB_COUNT; i++) {
        if (strcmp(g_skillDB[i].classCode, code) != 0) continue;
        switch (g_skillDB[i].tier) {
            case 1: if (n1 < 10) t1Idx[n1++] = i; break;
            case 2: if (n2 < 10) t2Idx[n2++] = i; break;
            case 3: if (n3 < 10) t3Idx[n3++] = i; break;
        }
    }

    g_poolCount = 0;
    for (int t = 0; t < 3; t++)
        for (int s = 0; s < 10; s++)
            g_tabSlots[t][s] = -1;

    for (int i = 0; i < n1; i++) {
        g_pool[g_poolCount].dbIndex   = t1Idx[i];
        g_pool[g_poolCount].unlocked  = TRUE;
        g_pool[g_poolCount].assigned  = TRUE;
        g_pool[g_poolCount].assignTab = 0;
        g_pool[g_poolCount].assignSlot = i;
        g_tabSlots[0][i] = g_poolCount;
        g_poolCount++;
    }
    for (int i = 0; i < n2; i++) {
        g_pool[g_poolCount].dbIndex   = t2Idx[i];
        g_pool[g_poolCount].unlocked  = TRUE;
        g_pool[g_poolCount].assigned  = TRUE;
        g_pool[g_poolCount].assignTab = 1;
        g_pool[g_poolCount].assignSlot = i;
        g_tabSlots[1][i] = g_poolCount;
        g_poolCount++;
    }
    for (int i = 0; i < n3; i++) {
        g_pool[g_poolCount].dbIndex   = t3Idx[i];
        g_pool[g_poolCount].unlocked  = TRUE;
        g_pool[g_poolCount].assigned  = TRUE;
        g_pool[g_poolCount].assignTab = 2;
        g_pool[g_poolCount].assignSlot = i;
        g_tabSlots[2][i] = g_poolCount;
        g_poolCount++;
    }

    g_seed = 0;
    g_poolInitialized = TRUE;
    Log("InitClassOnlySkills: class=%d (%s), %d skills (T1=%d T2=%d T3=%d), all assigned\n",
        classId, code, g_poolCount, n1, n2, n3);
}
