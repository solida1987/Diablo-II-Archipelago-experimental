"""
Diablo II Archipelago - Item Definitions

210 skill items (7 classes x 30 skills) + 7 filler item types.
AP ID = 45000 + D2 skill ID for skills.

IMPORTANT: D2 skill IDs must match g_skillDB[] in d2arch.c exactly!
"""
from BaseClasses import ItemClassification

ITEM_BASE = 45000

# ============================================================
# Skill items - one per D2 skill
# (d2_skill_id, name, classification)
#
# IDs come from the actual D2 1.10f skill IDs (skills.txt).
# Names must match what the game displays.
# ============================================================

# Amazon skills: D2 IDs 6-35
AMAZON_SKILLS = [
    # Bow and Crossbow
    (6,  "Magic Arrow",          ItemClassification.progression),
    (7,  "Fire Arrow",           ItemClassification.progression),
    (11, "Cold Arrow",           ItemClassification.progression),
    (12, "Multiple Shot",        ItemClassification.progression),
    (16, "Exploding Arrow",      ItemClassification.progression),
    (21, "Ice Arrow",            ItemClassification.progression),
    (22, "Guided Arrow",         ItemClassification.progression),
    (26, "Strafe",               ItemClassification.progression),
    (27, "Immolation Arrow",     ItemClassification.progression),
    (31, "Freezing Arrow",       ItemClassification.progression),
    # Passive and Magic
    (8,  "Inner Sight",          ItemClassification.progression),
    (9,  "Critical Strike",      ItemClassification.progression),
    (13, "Dodge",                ItemClassification.progression),
    (17, "Slow Missiles",        ItemClassification.progression),
    (18, "Avoid",                ItemClassification.progression),
    (23, "Penetrate",            ItemClassification.progression),
    (28, "Decoy",                ItemClassification.progression),
    (29, "Evade",                ItemClassification.progression),
    (32, "Valkyrie",             ItemClassification.progression),
    (33, "Pierce",               ItemClassification.progression),
    # Javelin and Spear
    (10, "Jab",                  ItemClassification.progression),
    (14, "Power Strike",         ItemClassification.progression),
    (15, "Poison Javelin",       ItemClassification.progression),
    (19, "Impale",               ItemClassification.progression),
    (20, "Lightning Bolt",       ItemClassification.progression),
    (24, "Charged Strike",       ItemClassification.progression),
    (25, "Plague Javelin",       ItemClassification.progression),
    (30, "Fend",                 ItemClassification.progression),
    (34, "Lightning Strike",     ItemClassification.progression),
    (35, "Lightning Fury",       ItemClassification.progression),
]

# Sorceress skills: D2 IDs 36-65
SORCERESS_SKILLS = [
    # Fire
    (36, "Fire Bolt",            ItemClassification.progression),
    (37, "Warmth",               ItemClassification.progression),
    (41, "Inferno",              ItemClassification.progression),
    (46, "Blaze",                ItemClassification.progression),
    (47, "Fire Ball",            ItemClassification.progression),
    (51, "Fire Wall",            ItemClassification.progression),
    (52, "Enchant",              ItemClassification.progression),
    (56, "Meteor",               ItemClassification.progression),
    (61, "Fire Mastery",         ItemClassification.progression),
    (62, "Hydra",                ItemClassification.progression),
    # Lightning
    (38, "Charged Bolt",         ItemClassification.progression),
    (42, "Static Field",         ItemClassification.progression),
    (43, "Telekinesis",          ItemClassification.progression),
    (48, "Nova",                 ItemClassification.progression),
    (49, "Lightning",            ItemClassification.progression),
    (53, "Chain Lightning",      ItemClassification.progression),
    (54, "Teleport",             ItemClassification.progression),
    (57, "Thunder Storm",        ItemClassification.progression),
    (58, "Energy Shield",        ItemClassification.progression),
    (63, "Lightning Mastery",    ItemClassification.progression),
    # Cold
    (39, "Ice Bolt",             ItemClassification.progression),
    (40, "Frozen Armor",         ItemClassification.progression),
    (44, "Frost Nova",           ItemClassification.progression),
    (45, "Ice Blast",            ItemClassification.progression),
    (50, "Shiver Armor",         ItemClassification.progression),
    (55, "Glacial Spike",        ItemClassification.progression),
    (59, "Blizzard",             ItemClassification.progression),
    (60, "Chilling Armor",       ItemClassification.progression),
    (64, "Frozen Orb",           ItemClassification.progression),
    (65, "Cold Mastery",         ItemClassification.progression),
]

# Necromancer skills: D2 IDs 66-95
NECROMANCER_SKILLS = [
    # Curses
    (66, "Amplify Damage",       ItemClassification.progression),
    (71, "Dim Vision",           ItemClassification.progression),
    (72, "Weaken",               ItemClassification.progression),
    (76, "Iron Maiden",          ItemClassification.progression),
    (77, "Terror",               ItemClassification.progression),
    (81, "Confuse",              ItemClassification.progression),
    (82, "Life Tap",             ItemClassification.progression),
    (86, "Attract",              ItemClassification.progression),
    (87, "Decrepify",            ItemClassification.progression),
    (91, "Lower Resist",         ItemClassification.progression),
    # Poison and Bone
    (67, "Teeth",                ItemClassification.progression),
    (68, "Bone Armor",           ItemClassification.progression),
    (73, "Poison Dagger",        ItemClassification.progression),
    (74, "Corpse Explosion",     ItemClassification.progression),
    (78, "Bone Wall",            ItemClassification.progression),
    (83, "Poison Explosion",     ItemClassification.progression),
    (84, "Bone Spear",           ItemClassification.progression),
    (88, "Bone Prison",          ItemClassification.progression),
    (92, "Poison Nova",          ItemClassification.progression),
    (93, "Bone Spirit",          ItemClassification.progression),
    # Summoning
    (70, "Raise Skeleton",       ItemClassification.progression),
    (69, "Skeleton Mastery",     ItemClassification.progression),
    (75, "Clay Golem",           ItemClassification.progression),
    (79, "Golem Mastery",        ItemClassification.progression),
    (80, "Raise Skeletal Mage",  ItemClassification.progression),
    (85, "Blood Golem",          ItemClassification.progression),
    (89, "Summon Resist",        ItemClassification.progression),
    (90, "Iron Golem",           ItemClassification.progression),
    (94, "Fire Golem",           ItemClassification.progression),
    (95, "Revive",               ItemClassification.progression),
]

# Paladin skills: D2 IDs 96-125
PALADIN_SKILLS = [
    # Combat
    (96,  "Sacrifice",           ItemClassification.progression),
    (97,  "Smite",               ItemClassification.progression),
    (101, "Holy Bolt",           ItemClassification.progression),
    (106, "Zeal",                ItemClassification.progression),
    (107, "Charge",              ItemClassification.progression),
    (111, "Vengeance",           ItemClassification.progression),
    (112, "Blessed Hammer",      ItemClassification.progression),
    (116, "Conversion",          ItemClassification.progression),
    (117, "Holy Shield",         ItemClassification.progression),
    (121, "Fist of the Heavens", ItemClassification.progression),
    # Offensive Auras
    (98,  "Might",               ItemClassification.progression),
    (102, "Holy Fire",           ItemClassification.progression),
    (103, "Thorns",              ItemClassification.progression),
    (108, "Blessed Aim",         ItemClassification.progression),
    (113, "Concentration",       ItemClassification.progression),
    (114, "Holy Freeze",         ItemClassification.progression),
    (118, "Holy Shock",          ItemClassification.progression),
    (119, "Sanctuary",           ItemClassification.progression),
    (122, "Fanaticism",          ItemClassification.progression),
    (123, "Conviction",          ItemClassification.progression),
    # Defensive Auras
    (99,  "Prayer",              ItemClassification.progression),
    (100, "Resist Fire",         ItemClassification.progression),
    (104, "Defiance",            ItemClassification.progression),
    (105, "Resist Cold",         ItemClassification.progression),
    (109, "Cleansing",           ItemClassification.progression),
    (110, "Resist Lightning",    ItemClassification.progression),
    (115, "Vigor",               ItemClassification.progression),
    (120, "Meditation",          ItemClassification.progression),
    (124, "Redemption",          ItemClassification.progression),
    (125, "Salvation",           ItemClassification.progression),
]

# Barbarian skills: D2 IDs 126-155
BARBARIAN_SKILLS = [
    # Combat Skills
    (126, "Bash",                ItemClassification.progression),
    (132, "Leap",                ItemClassification.progression),
    (133, "Double Swing",        ItemClassification.progression),
    (139, "Stun",                ItemClassification.progression),
    (140, "Double Throw",        ItemClassification.progression),
    (143, "Leap Attack",         ItemClassification.progression),
    (144, "Concentrate",         ItemClassification.progression),
    (147, "Frenzy",              ItemClassification.progression),
    (151, "Whirlwind",           ItemClassification.progression),
    (152, "Berserk",             ItemClassification.progression),
    # Combat Masteries
    (127, "Sword Mastery",       ItemClassification.progression),
    (128, "Axe Mastery",         ItemClassification.progression),
    (129, "Mace Mastery",        ItemClassification.progression),
    (134, "Pole Arm Mastery",    ItemClassification.progression),
    (135, "Throwing Mastery",    ItemClassification.progression),
    (136, "Spear Mastery",       ItemClassification.progression),
    (141, "Increased Stamina",   ItemClassification.progression),
    (145, "Iron Skin",           ItemClassification.progression),
    (148, "Increased Speed",     ItemClassification.progression),
    (153, "Natural Resistance",  ItemClassification.progression),
    # Warcries
    (130, "Howl",                ItemClassification.progression),
    (131, "Find Potion",         ItemClassification.progression),
    (137, "Taunt",               ItemClassification.progression),
    (138, "Shout",               ItemClassification.progression),
    (142, "Find Item",           ItemClassification.progression),
    (146, "Battle Cry",          ItemClassification.progression),
    (149, "Battle Orders",       ItemClassification.progression),
    (150, "Grim Ward",           ItemClassification.progression),
    (154, "War Cry",             ItemClassification.progression),
    (155, "Battle Command",      ItemClassification.progression),
]

# Druid skills: D2 IDs 221-250
DRUID_SKILLS = [
    # Elemental
    (225, "Firestorm",           ItemClassification.progression),
    (229, "Molten Boulder",      ItemClassification.progression),
    (230, "Arctic Blast",        ItemClassification.progression),
    (234, "Fissure",             ItemClassification.progression),
    (235, "Cyclone Armor",       ItemClassification.progression),
    (240, "Twister",             ItemClassification.progression),
    (244, "Volcano",             ItemClassification.progression),
    (245, "Tornado",             ItemClassification.progression),
    (249, "Armageddon",          ItemClassification.progression),
    (250, "Hurricane",           ItemClassification.progression),
    # Shape Shifting
    (223, "Werewolf",            ItemClassification.progression),
    (224, "Lycanthropy",         ItemClassification.progression),
    (228, "Werebear",            ItemClassification.progression),
    (233, "Maul",                ItemClassification.progression),
    (232, "Feral Rage",          ItemClassification.progression),
    (239, "Fire Claws",          ItemClassification.progression),
    (238, "Rabies",              ItemClassification.progression),
    (243, "Shock Wave",          ItemClassification.progression),
    (242, "Hunger",              ItemClassification.progression),
    (248, "Fury",                ItemClassification.progression),
    # Summoning
    (221, "Raven",               ItemClassification.progression),
    (222, "Poison Creeper",      ItemClassification.progression),
    (226, "Oak Sage",            ItemClassification.progression),
    (227, "Summon Spirit Wolf",  ItemClassification.progression),
    (231, "Carrion Vine",        ItemClassification.progression),
    (236, "Heart of Wolverine",  ItemClassification.progression),
    (237, "Summon Dire Wolf",    ItemClassification.progression),
    (241, "Solar Creeper",       ItemClassification.progression),
    (246, "Spirit of Barbs",     ItemClassification.progression),
    (247, "Summon Grizzly",      ItemClassification.progression),
]

# Assassin skills: D2 IDs 251-280
ASSASSIN_SKILLS = [
    # Martial Arts
    (254, "Tiger Strike",        ItemClassification.progression),
    (255, "Dragon Talon",        ItemClassification.progression),
    (259, "Fists of Fire",       ItemClassification.progression),
    (260, "Dragon Claw",         ItemClassification.progression),
    (265, "Cobra Strike",        ItemClassification.progression),
    (269, "Claws of Thunder",    ItemClassification.progression),
    (270, "Dragon Tail",         ItemClassification.progression),
    (274, "Blades of Ice",       ItemClassification.progression),
    (275, "Dragon Flight",       ItemClassification.progression),
    (280, "Phoenix Strike",      ItemClassification.progression),
    # Shadow Disciplines
    (252, "Claw Mastery",        ItemClassification.progression),
    (253, "Psychic Hammer",      ItemClassification.progression),
    (258, "Burst of Speed",      ItemClassification.progression),
    (263, "Weapon Block",        ItemClassification.progression),
    (264, "Cloak of Shadows",    ItemClassification.progression),
    (267, "Fade",                ItemClassification.progression),
    (268, "Shadow Warrior",      ItemClassification.progression),
    (273, "Mind Blast",          ItemClassification.progression),
    (278, "Venom",               ItemClassification.progression),
    (279, "Shadow Master",       ItemClassification.progression),
    # Traps - ONLY included when "I play Assassin" is ON
    # Non-Assassin characters become invisible and can't act when using these
]

ASSASSIN_TRAP_SKILLS = [
    (251, "Fire Blast",          ItemClassification.progression),
    (256, "Shock Web",           ItemClassification.progression),
    (257, "Blade Sentinel",      ItemClassification.progression),
    (261, "Charged Bolt Sentry", ItemClassification.progression),
    (262, "Wake of Fire",        ItemClassification.progression),
    (266, "Blade Fury",          ItemClassification.progression),
    (271, "Lightning Sentry",    ItemClassification.progression),
    (272, "Wake of Inferno",     ItemClassification.progression),
    (276, "Death Sentry",        ItemClassification.progression),
    (277, "Blade Shield",        ItemClassification.progression),
]

# === BEGIN GENERATED: experimental spell pack ===
# Generated by Tools/gen_apworld_spellpack.py -- do not hand-edit.
#
# One item per PUBLIC skill in the experimental spell pack. Ids and
# names come from the DLL's g_skillDB and the same string files that
# feed the game's own tooltips, so an item's name here is the name the
# player sees in game. AP id = ITEM_BASE + skill id.
#
# Classification is `useful`, never `progression`: nothing in the pack
# gates access to anything, so the fill algorithm is free to place
# these anywhere without solving logic around them.
EXPERIMENTAL_SPELL_ITEMS = [
    (357, "Test 1 - Summon Zombie", ItemClassification.useful),
    (358, "Test 2 - Summon Magic Zombie", ItemClassification.useful),
    (359, "Test 3 - Summon Wraith", ItemClassification.useful),
    (360, "Test 4 - Ground Lightning", ItemClassification.useful),
    (361, "Test 5 - Spirit Orb", ItemClassification.useful),
    (362, "Test 6 - Fire Teeth", ItemClassification.useful),
    (363, "Test 7 - Bone Nova", ItemClassification.useful),
    (364, "Test 8 - Quill Spray", ItemClassification.useful),
    (365, "Test 9 - Poison Breath", ItemClassification.useful),
    (366, "Test 10 - Blood Star", ItemClassification.useful),
    (367, "Test 11 - Ember Strike", ItemClassification.useful),
    (368, "Test 12 - Fortune Trap", ItemClassification.useful),
    (369, "Test 13 - Storm Trap", ItemClassification.useful),
    (370, "Test 14 - Fire Nova", ItemClassification.useful),
    (371, "Test 15 - Immolation Aura", ItemClassification.useful),
    (372, "Test 16 - Poison Bolt", ItemClassification.useful),
    (373, "Test 17 - Holy Poison", ItemClassification.useful),
    (374, "Test 18 - Meteor Strike", ItemClassification.useful),
    (377, "C1 - piercing projectile", ItemClassification.useful),
    (378, "C2 - homing projectile", ItemClassification.useful),
    (379, "C3 - cone / sustained stream", ItemClassification.useful),
    (380, "C4 - repeated rain from the sky", ItemClassification.useful),
    (381, "C5 - storm that follows you", ItemClassification.useful),
    (382, "C6 - wall on the ground", ItemClassification.useful),
    (383, "C7 - travelling ground wave", ItemClassification.useful),
    (384, "C8 - eruption from one point", ItemClassification.useful),
    (385, "C9 - random impacts nearby", ItemClassification.useful),
    (386, "C10 - chains between targets", ItemClassification.useful),
    (387, "C11 - spiral emitter", ItemClassification.useful),
    (388, "C12 - orbits your body", ItemClassification.useful),
    (389, "C13 - instant beam", ItemClassification.useful),
    (390, "C14 - delayed cluster from above", ItemClassification.useful),
    (391, "C15 - floating tracking hammer", ItemClassification.useful),
    (392, "C16 - instant area burst", ItemClassification.useful),
    (393, "C17 - travelling vortex", ItemClassification.useful),
    (394, "C18 - self buff", ItemClassification.useful),
    (395, "C19 - curse on enemies", ItemClassification.useful),
    (396, "C20 - barrier wall", ItemClassification.useful),
    (397, "C21 - periodic strikes over time", ItemClassification.useful),
    (398, "C22 - knockback push", ItemClassification.useful),
    (399, "C23 - mobility blink", ItemClassification.useful),
    (400, "C24 - crowd control, no damage", ItemClassification.useful),
    (401, "C25 - lobbed arc", ItemClassification.useful),
    (402, "C26 - splits on hit (needs a bow)", ItemClassification.useful),
    (403, "Armageddon of Diablo", ItemClassification.useful),
    (404, "Rupture", ItemClassification.useful),
    (405, "Triple Frost Nova", ItemClassification.useful),
    (406, "Ring of Fire", ItemClassification.useful),
    (407, "Mephisto's Bolt", ItemClassification.useful),
    (408, "Vampiric Meteor", ItemClassification.useful),
    (409, "Healing Vortex", ItemClassification.useful),
    (410, "Curse of Frailty", ItemClassification.useful),
    (411, "Blood for Mana", ItemClassification.useful),
    (412, "Countess' Firewall", ItemClassification.useful),
    (413, "Mephisto's Orb", ItemClassification.useful),
    (414, "Burning Skull", ItemClassification.useful),
    (415, "Twin Bone Spirits", ItemClassification.useful),
    (416, "Succubus Bolt", ItemClassification.useful),
    (417, "Ghoul Lord's Fireball", ItemClassification.useful),
    (418, "Ghoul Lord's Firewall", ItemClassification.useful),
    (419, "Glacial Shard", ItemClassification.useful),
    (420, "Triple Venom Ball", ItemClassification.useful),
    (421, "Sexton's Blizzard", ItemClassification.useful),
    (422, "Bone Ward", ItemClassification.useful),
    (423, "Rime Ward", ItemClassification.useful),
    (424, "Imp's Fire Bomb", ItemClassification.useful),
    (425, "Imp's Charged Bolt", ItemClassification.useful),
    (426, "Bear Smite", ItemClassification.useful),
    (427, "Zakarum Lightning", ItemClassification.useful),
    (428, "Skeleton Volley", ItemClassification.useful),
    (429, "Bursting Arrow", ItemClassification.useful),
    (430, "Rimebound Arrow", ItemClassification.useful),
    (431, "Lancer's Power Strike", ItemClassification.useful),
    (432, "Lancer's Ice Strike", ItemClassification.useful),
    (433, "Unholy Bolt", ItemClassification.useful),
    (434, "Shaman's Fireball", ItemClassification.useful),
    (435, "Imp Missile", ItemClassification.useful),
    (436, "Baal's Nova", ItemClassification.useful),
    (437, "Trap Nova", ItemClassification.useful),
    (438, "Venom Orb", ItemClassification.useful),
    (439, "Cursed Skull", ItemClassification.useful),
    (440, "Cursed Skull II", ItemClassification.useful),
    (441, "Andariel's Venom Spray", ItemClassification.useful),
    (442, "Baal's Glacial Fan", ItemClassification.useful),
    (443, "Imp Inferno", ItemClassification.useful),
    (444, "Horror's Arctic Breath", ItemClassification.useful),
    (445, "Diablo's Wall of Flame", ItemClassification.useful),
    (446, "Diablo's Bone Cage", ItemClassification.useful),
    (447, "Groper's Brood", ItemClassification.useful),
    (448, "Death Maul", ItemClassification.useful),
    (449, "Grasping Vines", ItemClassification.useful),
    (450, "Impregnate", ItemClassification.useful),
    (451, "Baal's Rupture", ItemClassification.useful),
    (452, "Blood Frenzy", ItemClassification.useful),
    (453, "Bloodlord's Frenzy", ItemClassification.useful),
    (454, "Siege Bombardment", ItemClassification.useful),
    (455, "Baal's Taunt", ItemClassification.useful),
    (456, "Serpent Charge", ItemClassification.useful),
    (457, "Siege Stomp", ItemClassification.useful),
    (458, "Summon Greater Mummy", ItemClassification.useful),
    (459, "Summon Fire Skeleton Mage", ItemClassification.useful),
    (460, "Summon Cold Skeleton Mage", ItemClassification.useful),
    (461, "Summon Storm Skeleton Mage", ItemClassification.useful),
    (462, "Summon Plague Skeleton Mage", ItemClassification.useful),
    (463, "Summon Will-o-Wisp", ItemClassification.useful),
    (464, "Summon Ghoul Lord", ItemClassification.useful),
    (465, "Summon Succubus Witch", ItemClassification.useful),
    (466, "Summon Succubus", ItemClassification.useful),
    (467, "Summon Imp", ItemClassification.useful),
    (468, "Summon Abyss Knight", ItemClassification.useful),
    (469, "Summon Oblivion Knight", ItemClassification.useful),
    (470, "Summon Fallen Shaman", ItemClassification.useful),
    (471, "Summon Fetish Shaman", ItemClassification.useful),
    (472, "Summon Zakarum Priest", ItemClassification.useful),
    (473, "Summon Council Member", ItemClassification.useful),
    (474, "Summon Bone Fetish", ItemClassification.useful),
    (475, "Summon Blowdart Fetish", ItemClassification.useful),
    (476, "Summon Zombie", ItemClassification.useful),
    (477, "Summon Wraith", ItemClassification.useful),
    (478, "Summon Mummy", ItemClassification.useful),
    (479, "Summon Skeleton", ItemClassification.useful),
    (480, "Summon Reanimated Horde", ItemClassification.useful),
    (481, "Summon Hell Bovine", ItemClassification.useful),
    (482, "Summon Zealot", ItemClassification.useful),
    (483, "Summon Corrupt Rogue", ItemClassification.useful),
    (484, "Summon Megademon", ItemClassification.useful),
    (485, "Summon Venom Lord", ItemClassification.useful),
    (486, "Summon Blood Lord", ItemClassification.useful),
    (487, "Summon Frozen Horror", ItemClassification.useful),
    (488, "Summon Death Mauler", ItemClassification.useful),
    (489, "Summon Siege Beast", ItemClassification.useful),
    (490, "Summon Blunderbore", ItemClassification.useful),
    (491, "Summon Baal Minion", ItemClassification.useful),
    (492, "Summon Snow Yeti", ItemClassification.useful),
    (493, "Summon Thorn Hulk", ItemClassification.useful),
    (494, "Summon Doom Knight", ItemClassification.useful),
    (495, "Summon Sand Raider", ItemClassification.useful),
    (496, "Summon Claw Viper", ItemClassification.useful),
    (497, "Summon Frost Baboon", ItemClassification.useful),
    (498, "Summon Bighead", ItemClassification.useful),
    (499, "Summon Bat Demon", ItemClassification.useful),
    (500, "Summon Arach", ItemClassification.useful),
    (501, "Summon Scarab", ItemClassification.useful),
    (502, "Summon Foul Crow", ItemClassification.useful),
    (503, "Summon Mosquito", ItemClassification.useful),
    (504, "Storm Trap", ItemClassification.useful),
    (505, "Charged Bolt Trap", ItemClassification.useful),
    (506, "Piercing Storm Trap", ItemClassification.useful),
    (507, "Lightning Nova Trap", ItemClassification.useful),
    (508, "Arcane Trap", ItemClassification.useful),
    (509, "Venom Orb Trap", ItemClassification.useful),
    (510, "Cursed Skull Trap", ItemClassification.useful),
    (511, "Cursed Skull Trap II", ItemClassification.useful),
    (512, "Poison Bolt Trap", ItemClassification.useful),
    (513, "Magic Bolt Trap", ItemClassification.useful),
    (514, "Unholy Bolt Trap", ItemClassification.useful),
    (515, "Fire Bolt Trap", ItemClassification.useful),
    (516, "Hydra Bolt Trap", ItemClassification.useful),
    (517, "Homing Skull Trap", ItemClassification.useful),
    (518, "Frost Nova Trap", ItemClassification.useful),
    (519, "Fire Nova Trap", ItemClassification.useful),
    (520, "Ghoul Fire Trap", ItemClassification.useful),
    (521, "Ice Shard Trap", ItemClassification.useful),
    (522, "Blizzard Trap", ItemClassification.useful),
    (523, "Corpse Trap", ItemClassification.useful),
    (524, "Fortune Trap", ItemClassification.useful),
    (525, "Vigor Trap", ItemClassification.useful),
    (526, "Mending Trap", ItemClassification.useful),
    (527, "Warcry Trap", ItemClassification.useful),
    (531, "Aura of the Pantheon", ItemClassification.useful),
    (532, "Fire Nova", ItemClassification.useful),
    (533, "Magic Nova", ItemClassification.useful),
    (534, "Shrapnel Nova", ItemClassification.useful),
    (535, "Blood Nova", ItemClassification.useful),
    (536, "Skull Nova", ItemClassification.useful),
    (537, "Arc Nova", ItemClassification.useful),
    (538, "Void Nova", ItemClassification.useful),
    (539, "Frost Shard Nova", ItemClassification.useful),
    (540, "Spore Nova", ItemClassification.useful),
    (541, "Quill Nova", ItemClassification.useful),
    (542, "Shuriken Nova", ItemClassification.useful),
    (543, "Rime Nova", ItemClassification.useful),
    (544, "Seeking Flame", ItemClassification.useful),
    (545, "Seeking Frost", ItemClassification.useful),
    (546, "Seeking Spark", ItemClassification.useful),
    (547, "Seeking Venom", ItemClassification.useful),
    (548, "Hunting Skull", ItemClassification.useful),
    (549, "Wraith Orb", ItemClassification.useful),
    (550, "Blood Star", ItemClassification.useful),
    (551, "Homing Shuriken", ItemClassification.useful),
    (552, "Vengeful Spirit", ItemClassification.useful),
    (553, "Seeking Boulder", ItemClassification.useful),
    (554, "Venom Cone", ItemClassification.useful),
    (555, "Ash Cone", ItemClassification.useful),
    (556, "Rime Cone", ItemClassification.useful),
    (557, "Void Stream", ItemClassification.useful),
    (558, "Spine Fan", ItemClassification.useful),
    (559, "Crimson Beam", ItemClassification.useful),
    (560, "Pillar of Light", ItemClassification.useful),
    (561, "Skyfall Bolt", ItemClassification.useful),
    (562, "Beam of the Den", ItemClassification.useful),
    (563, "Hellfire Rain", ItemClassification.useful),
    (564, "Bone Hail", ItemClassification.useful),
    (565, "Masonry Fall", ItemClassification.useful),
    (566, "Icicle Storm", ItemClassification.useful),
    (567, "Corpse Rain", ItemClassification.useful),
    (568, "Debris Storm", ItemClassification.useful),
    (569, "Gas Bombardment", ItemClassification.useful),
    (570, "Ember Shower", ItemClassification.useful),
    (571, "Orbiting Flame", ItemClassification.useful),
    (572, "Orbiting Blade", ItemClassification.useful),
    (573, "Chain Venom", ItemClassification.useful),
    (574, "Chain Frost", ItemClassification.useful),
    (575, "Chain Magic", ItemClassification.useful),
    (576, "Splitting Bone", ItemClassification.useful),
    (577, "Trailing Flame", ItemClassification.useful),
    (578, "Trailing Venom", ItemClassification.useful),
    (579, "Forking Bolt", ItemClassification.useful),
    (580, "Splitting Skull", ItemClassification.useful),
    (581, "Shatter Bolt", ItemClassification.useful),
    (582, "Unholy Spear", ItemClassification.useful),
    (583, "Ember Lance", ItemClassification.useful),
    (584, "Storm Lance", ItemClassification.useful),
    (585, "Venom Lance", ItemClassification.useful),
    (586, "Frost Lance", ItemClassification.useful),
    (587, "Shuriken Volley", ItemClassification.useful),
    (588, "Pilum", ItemClassification.useful),
    (589, "Blowdart", ItemClassification.useful),
    (590, "Pillar of Immolation", ItemClassification.useful),
    (591, "Phoenix Trail", ItemClassification.useful),
    (592, "Shock Field", ItemClassification.useful),
    (593, "Sanctuary Ring", ItemClassification.useful),
    (594, "Plague Cloud", ItemClassification.useful),
    (595, "Choking Fog", ItemClassification.useful),
    (596, "Ice Field", ItemClassification.useful),
    (597, "Ember Wake", ItemClassification.useful),
    (598, "Lava Pool", ItemClassification.useful),
    (599, "Frost Mist", ItemClassification.useful),
    (600, "Blood Puddle", ItemClassification.useful),
    (601, "Yawning Rift", ItemClassification.useful),
    (602, "Lava Geyser", ItemClassification.useful),
    (603, "Ember Storm", ItemClassification.useful),
    (604, "Molten Path", ItemClassification.useful),
    (605, "Creeping Vines", ItemClassification.useful),
    (606, "Rising Fury", ItemClassification.useful),
    (607, "Leeching Fury", ItemClassification.useful),
    (608, "Ember Fists", ItemClassification.useful),
    (609, "Storm Claws", ItemClassification.useful),
    (610, "Rime Blades", ItemClassification.useful),
    (611, "Nova Fists", ItemClassification.useful),
    (612, "Chain Fists", ItemClassification.useful),
    (613, "Shatter Fists", ItemClassification.useful),
    (614, "Shadow Step", ItemClassification.useful),
    (615, "Blink", ItemClassification.useful),
    (616, "Knockback Slam", ItemClassification.useful),
    (617, "Stunning Roar", ItemClassification.useful),
    (618, "Bone Totem", ItemClassification.useful),
    (619, "Whirl of Blades", ItemClassification.useful),
    (620, "Bound", ItemClassification.useful),
    (621, "Bewilder", ItemClassification.useful),
    (622, "Lure", ItemClassification.useful),
    (623, "Panic", ItemClassification.useful),
    (624, "Blind", ItemClassification.useful),
    (625, "War Shout", ItemClassification.useful),
    (626, "Aura of Greed", ItemClassification.useful),
    (627, "Aura of Piercing", ItemClassification.useful),
    (628, "Aura of Haste", ItemClassification.useful),
    (629, "Aura of Vitality", ItemClassification.useful),
    (630, "Aura of Retribution", ItemClassification.useful),
    (631, "Aura of Warding", ItemClassification.useful),
    (632, "Aura of Focus", ItemClassification.useful),
    (633, "Mark of the Prey", ItemClassification.useful),
    (634, "Mark of Ash", ItemClassification.useful),
    (635, "Mark of Rime", ItemClassification.useful),
    (636, "Mark of the Storm", ItemClassification.useful),
    (637, "Mark of Rot", ItemClassification.useful),
    (638, "Mark of Frailty", ItemClassification.useful),
    (639, "Mark of Sloth", ItemClassification.useful),
    (640, "Mark of Ruin", ItemClassification.useful),
    (641, "Mark of Weakness", ItemClassification.useful),
    (642, "Mark of Blunting", ItemClassification.useful),
    (643, "Mark of Exposure", ItemClassification.useful),
    (644, "Mark of Silence", ItemClassification.useful),
    (645, "Cow Form", ItemClassification.useful),
    (646, "Fallen Form", ItemClassification.useful),
    (647, "Shaman Form", ItemClassification.useful),
    (648, "Zombie Form", ItemClassification.useful),
    (649, "Skeleton Form", ItemClassification.useful),
    (650, "Quill Rat Form", ItemClassification.useful),
    (651, "Fetish Form", ItemClassification.useful),
    (652, "Goatman Form", ItemClassification.useful),
    (653, "Huntress Form", ItemClassification.useful),
    (654, "Sand Raider Form", ItemClassification.useful),
    (655, "Gloam Form", ItemClassification.useful),
    (656, "Ghoul Lord Form", ItemClassification.useful),
    (657, "Spider Form", ItemClassification.useful),
    (658, "Scarab Form", ItemClassification.useful),
    (659, "Frog Demon Form", ItemClassification.useful),
    (660, "Blunderbore Form", ItemClassification.useful),
    (661, "Succubus Form", ItemClassification.useful),
    (662, "Balrog Form", ItemClassification.useful),
    (663, "Corpulent Form", ItemClassification.useful),
    (664, "Wraith Form", ItemClassification.useful),
    (665, "Tomb Viper Form", ItemClassification.useful),
    (666, "Sand Maggot Form", ItemClassification.useful),
    (667, "Doom Minion Form", ItemClassification.useful),
    (668, "Siege Beast Form", ItemClassification.useful),
    (669, "Yeti Form", ItemClassification.useful),
    (670, "Overseer Form", ItemClassification.useful),
    (671, "Imp Form", ItemClassification.useful),
    (672, "Death Mauler Form", ItemClassification.useful),
    (673, "Horde Form", ItemClassification.useful),
    (674, "Baal's Minion Form", ItemClassification.useful),
]
# === END GENERATED: experimental spell pack ===

# Per-class skill lists for class filter
# ============================================================
# TIER 1 skill ids — the 10 lowest-row skills of each class (70 total).
#
# Mirrors the `tier` column of g_skillDB in d2arch_skills.c, which is the
# authoritative table; regenerate with Tools/gen_tier1_ids.py if that table
# ever changes. Starting skills are drawn ONLY from this set, in AP exactly
# as in standalone: a run that opens with Frozen Orb or Blessed Hammer is not
# a run, and the standalone side has always granted its starting skills from
# tier 1 (the unlock loop only touches the T1 array) — AP handed out the first
# N of a pool shuffled across all three tiers, so the two modes disagreed.
# ============================================================
TIER1_SKILL_IDS = frozenset([6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260])

# Tiers 2 and 3, from the same g_skillDB column as tier 1. Used by the
# pool-size option to split its quota evenly across the three tiers.
TIER2_SKILL_IDS = frozenset([16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 358, 359, 362, 363, 367, 370, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 663, 664, 665, 666, 667, 669, 670, 671, 672, 673])
TIER3_SKILL_IDS = frozenset([26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 368, 369, 371, 373, 374, 531, 662, 668, 674])

CLASS_SKILLS = {
    "amazon":      AMAZON_SKILLS,
    "sorceress":   SORCERESS_SKILLS,
    "necromancer": NECROMANCER_SKILLS,
    "paladin":     PALADIN_SKILLS,
    "barbarian":   BARBARIAN_SKILLS,
    "druid":       DRUID_SKILLS,
    "assassin":    ASSASSIN_SKILLS,
}

# 1.9.11 — NATIVE-ONLY skill IDs (mirror of d2arch_skills.c:300-311).
#
# These skills are tied to class-specific animations (Amazon javelins use TH,
# Paladin Smite uses S1 shield-bash, Barbarian sequences use SQ, Druid bites
# use S3, Assassin kicks/claws use KK). When a non-native class receives one,
# the DLL's `IsNativeOnlySkill` filter excludes it from the local pool and
# the skill never appears in the player's right-click list.
#
# Pre-1.9.11 the apworld didn't know about this and would happily place these
# skill items into a slot for any class. The DLL then deferred (B2 fix) or
# permanently ate (pre-B2) the apId. Now the apworld filters them out when
# the player's class (via `skill_class_filter` toggles) is not the native
# owner — saving multiworld bandwidth and avoiding deferred-skill spam.
#
# Keep this list in sync with d2arch_skills.c. The DLL is the runtime
# source of truth; the apworld filter is a build-time optimisation.
NATIVE_ONLY_SKILL_IDS = {
    15, 20, 25, 35,            # Amazon — pure throwing javelins
    97,                         # Paladin — shield-bash (Smite)
    133, 140, 143, 151,         # Barbarian — sequence skills
    238, 242,                   # Druid — werewolf-form bites
    255, 259, 260, 266, 269, 274,  # Assassin — kicks/claws/blade-fury/charge-up
}

# Which class each NATIVE_ONLY skill belongs to (for include-class filtering).
NATIVE_ONLY_SKILL_CLASS = {
    15: "amazon", 20: "amazon", 25: "amazon", 35: "amazon",
    97: "paladin",
    133: "barbarian", 140: "barbarian", 143: "barbarian", 151: "barbarian",
    238: "druid", 242: "druid",
    255: "assassin", 259: "assassin", 260: "assassin",
    266: "assassin", 269: "assassin", 274: "assassin",
}

# All skill items combined (without trap skills — those are opt-in)
# Skill display name -> skill id. Built from the per-class tables so nothing
# has to be listed twice; used to test a placed item against TIER1_SKILL_IDS.
SKILL_ID_BY_NAME = {
    name: sid
    for skills in CLASS_SKILLS.values()
    for (sid, name, _cls) in skills
}

ALL_SKILL_ITEMS = (
    AMAZON_SKILLS + SORCERESS_SKILLS + NECROMANCER_SKILLS +
    PALADIN_SKILLS + BARBARIAN_SKILLS + DRUID_SKILLS + ASSASSIN_SKILLS
)

# Full pool including trap skills (only used when "I play Assassin" is ON)
ALL_SKILL_ITEMS_WITH_TRAPS = ALL_SKILL_ITEMS + ASSASSIN_TRAP_SKILLS

# Filler items
#
# 1.9.0 redesign: replaced the 8 generic placeholders with 17 typed
# fillers. The DLL pre-rolls specific magnitudes (gold 1-10000, xp
# 1-250000) and specific item picks (which charm / which set piece /
# which unique) at character creation, stores them in the per-char
# state file, and consumes them deterministically when the matching
# AP item arrives. This replaces the old "roll-at-drop-time" model
# so spoilers (both AP and the new standalone spoiler file) can show
# what each location's reward will be before the run starts.
FILLER_ITEMS = [
    # Direct stat / point items
    (45500, "Gold",                       ItemClassification.filler),  # DLL rolls 1-10000
    (45503, "5 Stat Points",              ItemClassification.filler),
    (45504, "Skill Point",                ItemClassification.filler),
    (45506, "Reset Point",                ItemClassification.filler),
    (45508, "Experience",                 ItemClassification.filler),  # DLL rolls 1-250000

    # Trap variants (replaces single 45505 "Trap")
    (45505, "Trap: Monsters",             ItemClassification.trap),
    (45511, "Trap: Slow",                 ItemClassification.trap),
    (45512, "Trap: Weaken",               ItemClassification.trap),
    (45513, "Trap: Poison",               ItemClassification.trap),

    # Boss-loot drops (replaces single 45507 "Boss Loot Drop")
    # Each drops the named boss's TC at the player's ilvl+5.
    (45514, "Drop: Andariel Loot",        ItemClassification.filler),
    (45515, "Drop: Duriel Loot",          ItemClassification.filler),
    (45516, "Drop: Mephisto Loot",        ItemClassification.filler),
    (45517, "Drop: Diablo Loot",          ItemClassification.filler),
    (45518, "Drop: Baal Loot",            ItemClassification.filler),

    # Specific-item drops. DLL pre-rolls WHICH charm / set piece /
    # unique to drop at char creation; the spoiler file shows the
    # specific name. Items always drop unidentified, like a real
    # monster drop.
    (45519, "Drop: Random Charm",         ItemClassification.filler),
    (45520, "Drop: Random Set Item",      ItemClassification.filler),
    (45521, "Drop: Random Unique",        ItemClassification.filler),

    # Ordinary-item bundles. Each maps to one entry in the
    # DLL's g_fillerBatches table by id order; do not reorder.
    (45522, "Random Rune",              ItemClassification.filler),
    (45523, "Random Gem",               ItemClassification.filler),
    (45524, "Rejuvenation Potions",     ItemClassification.filler),
    (45525, "Full Rejuvenation Potions",  ItemClassification.filler),
    (45526, "Greater Healing Potions",  ItemClassification.filler),
    (45527, "Greater Mana Potions",     ItemClassification.filler),
    (45528, "Throwing Potions",         ItemClassification.filler),
    (45529, "Random Jewel",             ItemClassification.filler),
    (45530, "Tome of Town Portal",      ItemClassification.filler),
    (45531, "Tome of Identify",         ItemClassification.filler),
    (45532, "Skeleton Keys",            ItemClassification.filler),
    (45533, "Utility Potions",          ItemClassification.filler),

    # Tiered variants of the bundles above. Same table, same id ordering
    # rule. These are the ones tierfill.py pushes into the later spheres,
    # which is where their rarity comes from.
    (45534, "Random Rune (Mid)",        ItemClassification.filler),
    (45535, "Random Rune (High)",       ItemClassification.filler),
    (45536, "Flawless Gem",             ItemClassification.filler),
    (45537, "Perfect Gem",              ItemClassification.filler),
    (45538, "Small Charm",              ItemClassification.filler),
    (45539, "Large Charm",              ItemClassification.filler),
    (45540, "Grand Charm",              ItemClassification.filler),

    # Point items in discrete sizes. Not part of the batch table — these
    # have their own cases in the DLL and may sit at any id.
    (45541, "1 Stat Point",             ItemClassification.filler),
    (45542, "3 Stat Points",            ItemClassification.filler),
    (45543, "10 Stat Points",           ItemClassification.filler),
    (45544, "2 Skill Points",           ItemClassification.filler),
    (45545, "3 Skill Points",           ItemClassification.filler),
    (45546, "3 Reset Points",           ItemClassification.filler),

    # Object traps. These spawn real world objects around the player
    # rather than applying a status effect, so they are the first traps
    # that can physically get in the way.
    (45547, "Trap: Barrel Field",       ItemClassification.trap),
    (45548, "Trap: Urn Garden",         ItemClassification.trap),
    (45549, "Trap: False Treasure",     ItemClassification.trap),
    (45550, "Trap: Junk Backpack",      ItemClassification.trap),

    # Set and unique drops narrowed to one equipment slot. The eight slot
    # names appear in the same order in both blocks and the DLL derives
    # the slot as (id - 45551) % 8, so the ORDER here is load-bearing.
    # If a slot turns out empty the DLL falls back to an unfiltered roll
    # rather than dropping nothing.
    (45551, "Drop: Set Armor",          ItemClassification.filler),
    (45552, "Drop: Set Helm",           ItemClassification.filler),
    (45553, "Drop: Set Shield",         ItemClassification.filler),
    (45554, "Drop: Set Gloves",         ItemClassification.filler),
    (45555, "Drop: Set Boots",          ItemClassification.filler),
    (45556, "Drop: Set Belt",           ItemClassification.filler),
    (45557, "Drop: Set Weapon",         ItemClassification.filler),
    (45558, "Drop: Set Jewelry",        ItemClassification.filler),
    (45559, "Drop: Unique Armor",       ItemClassification.filler),
    (45560, "Drop: Unique Helm",        ItemClassification.filler),
    (45561, "Drop: Unique Shield",      ItemClassification.filler),
    (45562, "Drop: Unique Gloves",      ItemClassification.filler),
    (45563, "Drop: Unique Boots",       ItemClassification.filler),
    (45564, "Drop: Unique Belt",        ItemClassification.filler),
    (45565, "Drop: Unique Weapon",      ItemClassification.filler),
    (45566, "Drop: Unique Jewelry",     ItemClassification.filler),
]

# Zone Key items (for Zone Explorer game mode)
# AP ID = 46001 + key_index
ZONE_KEY_BASE = 46001
ZONE_KEY_ITEMS = [
    # Act 1 (10 keys)
    (46001, "Cold Plains Key",        1, ItemClassification.progression),
    (46002, "Burial Grounds Key",     1, ItemClassification.progression),
    (46003, "Stony Field Key",        1, ItemClassification.progression),
    (46004, "Dark Wood Key",          1, ItemClassification.progression),
    (46005, "Black Marsh Key",        1, ItemClassification.progression),
    (46006, "Tristram Key",           1, ItemClassification.progression),
    (46007, "Monastery Key",          1, ItemClassification.progression),
    (46008, "Jail & Cathedral Key",   1, ItemClassification.progression),
    (46009, "Catacombs Key",          1, ItemClassification.progression),
    (46010, "Andariel's Lair Key",    1, ItemClassification.progression),
    # Act 2 (8 keys)
    (46011, "Rocky Waste Key",        2, ItemClassification.progression),
    (46012, "Dry Hills Key",          2, ItemClassification.progression),
    (46013, "Far Oasis Key",          2, ItemClassification.progression),
    (46014, "Lost City Key",          2, ItemClassification.progression),
    (46015, "Palace Key",             2, ItemClassification.progression),
    (46016, "Arcane Sanctuary Key",   2, ItemClassification.progression),
    (46017, "Canyon of the Magi Key", 2, ItemClassification.progression),
    (46018, "Duriel's Lair Key",      2, ItemClassification.progression),
    # Act 3 (6 keys)
    (46019, "Spider Forest Key",      3, ItemClassification.progression),
    (46020, "Jungle Key",             3, ItemClassification.progression),
    (46021, "Kurast Key",             3, ItemClassification.progression),
    (46022, "Upper Kurast Key",       3, ItemClassification.progression),
    (46023, "Travincal Key",          3, ItemClassification.progression),
    (46024, "Durance of Hate Key",    3, ItemClassification.progression),
    # Act 4 (4 keys)
    (46025, "Outer Steppes Key",      4, ItemClassification.progression),
    (46026, "City of the Damned Key", 4, ItemClassification.progression),
    (46027, "River of Flame Key",     4, ItemClassification.progression),
    (46028, "Chaos Sanctuary Key",    4, ItemClassification.progression),
    # Act 5 (7 keys)
    (46029, "Bloody Foothills Key",   5, ItemClassification.progression),
    (46030, "Highlands Key",          5, ItemClassification.progression),
    (46031, "Caverns Key",            5, ItemClassification.progression),
    (46032, "Summit Key",             5, ItemClassification.progression),
    (46033, "Nihlathak Key",          5, ItemClassification.progression),
    (46034, "Worldstone Keep Key",    5, ItemClassification.progression),
    (46035, "Throne of Destruction Key", 5, ItemClassification.progression),
]

# 1.8.0 NEW — Gate Keys for the gated zone-locking preload system.
# 18 gates per difficulty × 3 difficulties = 54 items.
# Slot layout per difficulty: 0-3=A1G1..4, 4-7=A2G1..4, 8-11=A3G1..4,
# 12-13=A4G1..2 (Act 4 has only 2), 14-17=A5G1..4.
# AP IDs: Normal=46101-46118, Nightmare=46121-46138, Hell=46141-46158.
GATE_KEY_AP_BASE = {0: 46101, 1: 46121, 2: 46141}
GATE_KEYS_PER_DIFF = 18

def _gate_key_entries():
    out = []
    # Gates per (act, diff):
    # Act 1,2,3,5: 4 gates each. Act 4: 2 gates.
    gates_by_act = {1: 4, 2: 4, 3: 4, 4: 2, 5: 4}
    slot_by_act_gate = {
        1: lambda g: 0 + g,
        2: lambda g: 4 + g,
        3: lambda g: 8 + g,
        4: lambda g: 12 + g,
        5: lambda g: 14 + g,
    }
    diff_name = ["Normal", "Nightmare", "Hell"]
    for diff in range(3):
        base = GATE_KEY_AP_BASE[diff]
        for act, num_gates in gates_by_act.items():
            # One ITEM per (act, diff) now; the copy count is num_gates.
            for g in range(1):
                slot = slot_by_act_gate[act](0)
                ap_id = base + slot
                # V5 - PROGRESSIVE act keys. Every gate of an act now shares ONE
                # item name, delivered as `num_gates` copies: the Nth copy you
                # receive opens that act's Nth gate, so ANY copy makes progress.
                # Previously each of the 54 keys unlocked one specific gate, which
                # made the whole act a strict 54-link serial chain that AP's fill
                # could not flatten (early D2 keys landing behind other games'
                # end-game). The AP id stays the act's FIRST gate id so existing
                # id ranges and the DLL's (diff, slot) decode are unchanged.
                name = f"Progressive Act {act} Key ({diff_name[diff]})"
                out.append((ap_id, name, act, ItemClassification.progression))
    return out

GATE_KEY_ITEMS = _gate_key_entries()  # one entry per (act, diff)
# V5 - how many copies of each progressive act key exist (= that act's gate count).
GATE_COPIES_BY_ACT = {1: 4, 2: 4, 3: 4, 4: 2, 5: 4}

# 2.1 fix — boss/gate gating tokens are locked at REAL act-boss & gate
# check-locations to drive region sphere logic via state.has(<token name>).
# They MUST carry a real integer code, NOT None: AP 0.6.7's
# _speedups.LocationStore packs the multidata locations into C int arrays, and a
# None item code crashes the SERVER load with "TypeError: an integer is
# required" (generation itself doesn't validate this, so the seed gens fine but
# won't host). One shared registered id is enough — region gating keys off the
# unique token NAME; the code only feeds the network multidata / datapackage.
BOSS_TOKEN_ITEM_ID = 46200

# Build the complete item table: { name: (ap_id, classification) }
item_table: dict[str, tuple[int, ItemClassification]] = {}

for d2_id, name, classification in ALL_SKILL_ITEMS_WITH_TRAPS:
    item_table[name] = (ITEM_BASE + d2_id, classification)

for ap_id, name, classification in FILLER_ITEMS:
    item_table[name] = (ap_id, classification)

for ap_id, name, act, classification in ZONE_KEY_ITEMS:
    item_table[name] = (ap_id, classification)

# EX-1.0.69 — the experimental spell pack has to be in item_table too.
# It never was: create_items appends these by NAME and create_item then looks
# the name up here, so with the pack enabled generation died on
# `KeyError: 'C15 - floating tracking hammer'` — every AP seed using the pack,
# ever since it was added. Deliberately OUTSIDE the BEGIN/END GENERATED block
# above so Tools/gen_apworld_spellpack.py cannot overwrite the registration
# when it regenerates the list.
for d2_id, name, classification in EXPERIMENTAL_SPELL_ITEMS:
    item_table[name] = (ITEM_BASE + d2_id, classification)

# 1.8.0 NEW — Gate Keys (54 items for preload-gated zone-locking)
for ap_id, name, act, classification in GATE_KEY_ITEMS:
    item_table[name] = (ap_id, classification)

# 2.1 — register the shared boss/gate gating-token item id so the datapackage
# resolves it and AP fill accepts the locked tokens (see BOSS_TOKEN_ITEM_ID).
item_table["Boss Token"] = (BOSS_TOKEN_ITEM_ID, ItemClassification.progression)

# Reverse lookup: ap_id -> name
item_id_to_name: dict[int, str] = {v[0]: k for k, v in item_table.items()}

# Skill ID to name lookup for the bridge
skill_id_to_name: dict[int, str] = {d2_id: name for d2_id, name, _ in ALL_SKILL_ITEMS_WITH_TRAPS}
