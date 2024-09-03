LittlerootTown_ProfBirchLab_LetoVersion_MapScripts::
# 2 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfBirchLab_LetoVersion_OnTransition
# 3 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfBirchLab_LetoVersion_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 6 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfBirchLab_LetoVersion_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_ProfBirchLab_LetoVersion_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfBirchLab_LetoVersion_EventScript_SetPlayerPosForReceiveStarter
	.2byte 0

LittlerootTown_ProfBirchLab_LetoVersion_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GiveStarterEvent
# 8 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent
	.2byte 0


LittlerootTown_ProfBirchLab_LetoVersion_OnTransition::
# 13 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
	return


LittlerootTown_ProfBirchLab_LetoVersion_EventScript_SetPlayerPosForReceiveStarter::
# 17 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return


LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GiveStarterEvent::
# 21 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	lockall
# 22 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 23 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox TakePokemon, MSGBOX_DEFAULT
# 24 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 25 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	call NicknameStarter
# 26 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox GoSeeRival, MSGBOX_DEFAULT
# 27 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_101_BOY
# 28 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 3
# 29 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	releaseall
	return


LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent::
# 33 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	lockall
# 34 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfBirchLab_LetoVersion_Movement_PlayerEnterLabForPokedex
# 35 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	waitmovement 0
# 36 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox TakePokedex, MSGBOX_DEFAULT
# 37 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 39 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	waitfanfare
# 40 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 41 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	special SetUnlockedPokedexFlags
# 42 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 43 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
# 44 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	giveitem ITEM_INFINITE_CANDY
# 45 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 47 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	waitfanfare
# 48 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent_Text_0
# 49 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	applymovement LOCALID_RIVAL, LittlerootTown_ProfBirchLab_LetoVersion_Movement_RivalApproachPlayer
# 50 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	waitmovement 0
# 51 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 52 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	waitmovement 0
# 53 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	checkplayergender
# 54 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent_2
# 57 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox MayGotPokedexToo, MSGBOX_DEFAULT
LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent_1:
# 59 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	giveitem ITEM_MASTER_BALL, 100
# 60 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 5
# 61 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setflag FLAG_ADVENTURE_STARTED
# 62 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setvar VAR_OLDALE_TOWN_STATE, 1
# 63 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
# 64 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
# 65 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	releaseall
	return

LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent_2:
# 55 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox BrendanGotPokedexToo, MSGBOX_DEFAULT
	goto LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent_1


# 68 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
LittlerootTown_ProfBirchLab_LetoVersion_Movement_RivalApproachPlayer:
# 69 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_down
# 70 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_in_place_faster_left
# 71 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	step_end

# 74 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
LittlerootTown_ProfBirchLab_LetoVersion_Movement_PlayerEnterLabForPokedex:
# 75 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 76 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 77 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 78 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 79 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 80 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 81 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	walk_up
# 82 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	step_end

NicknameStarter::
# 86 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	msgbox NicknamePokemon, MSGBOX_YESNO
# 87 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq NicknameStarter_1
	return

NicknameStarter_1:
# 88 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 89 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	return


LittlerootTown_ProfBirchLab_LetoVersion_EventScript_GivePokedexEvent_Text_0:
# 48 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "PROF. BIRCH: Raising Pokémon should be\n"
	.string "fun and easy.$"

TakePokemon::
# 93 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "PROF. BIRCH: So, {PLAYER}.\p"
	.string "I've heard so much about you from\n"
	.string "your father.\p"
	.string "I've heard that you don't have your\n"
	.string "own POKéMON yet.\p"
	.string "But the way you battled earlier,\n"
	.string "you pulled it off with aplomb!\p"
	.string "I guess you have your father's blood\n"
	.string "in your veins after all!\p"
	.string "Oh, yes. As thanks for rescuing me,\n"
	.string "I'd like you to have the POKéMON you\l"
	.string "used earlier.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

NicknamePokemon::
# 109 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "PROF. BIRCH: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

GoSeeRival::
# 114 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "PROF. BIRCH: If you work with Pokémon\n"
	.string "and gain experience, I think you'll make\l"
	.string "an extremely good TRAINER.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "Pokémon while helping me out.\p"
	.string "You can find them on Route 103.$"

TakePokedex::
# 123 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "PROF. BIRCH: Oh, hi, {PLAYER}!\p"
	.string "I heard you beat my kiddo, {RIVAL} \n"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "Here, {PLAYER}, I ordered this for my \n"
	.string "research, but I think you should have \l"
	.string "this Pokédex.$"

MayGotPokedexToo::
# 133 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "MAY: Oh, wow, {PLAYER}\n"
	.string "You got a Pokédex, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"

BrendanGotPokedexToo::
# 140 "data/maps/LittlerootTown_ProfBirchLab_LetoVersion/scripts.pory"
	.string "Brendan: Oh, wow, {PLAYER}\n"
	.string "You got a Pokédex, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"
