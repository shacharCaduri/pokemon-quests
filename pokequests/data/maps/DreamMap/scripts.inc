@	.include "data/maps/DreamMap/letpass.inc"

DreamMap_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DreamMap_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DreamMap_OnTransition
	.byte 0

DreamMap_OnLoad::
	call_if_set FLAG_AGATHA_MOVED_ASIDE, DreamMap_SetAgathaNewPosition
	end

DreamMap_SetAgathaNewPosition::
	setobjectxyperm 1, 12, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	return

DreamMap_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	@msgbox DreamMap_Text_HelloWorld, MSGBOX_DEFAULT 
	end

DreamMap_AgathaTalk::
	lockall
	faceplayer
	getpartysize
	compare VAR_RESULT, 0
	goto_if_eq DreamMap_AgathaTalk_NoPokemon
	goto_if_set FLAG_AGATHA_MOVED_ASIDE, DreamMap_AgathaTalk_Repeat
	msgbox DreamMap_Text_GoodYouCanPass, MSGBOX_NPC
	msgbox DreamMap_Text_HereSomePrizeItems, MSGBOX_NPC
	giveitem ITEM_ULTRA_BALL, 10
	giveitem ITEM_TIMER_BALL, 10
	giveitem ITEM_REPEAT_BALL, 10
	giveitem ITEM_LUXURY_BALL, 10
	giveitem ITEM_REVIVE, 5
	giveitem ITEM_HYPER_POTION, 5
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DreamMap_Movement_PlayerStepBack
	waitmovement 0
	applymovement 1, DreamMap_Movement_AgathaMoveAside
	waitmovement 0
	setflag FLAG_AGATHA_MOVED_ASIDE
	releaseall
	end

DreamMap_AgathaTalk_Repeat::
	msgbox DreamMap_Text_GoodYouCanPass, MSGBOX_NPC
	releaseall
	end

DreamMap_AgathaTalk_NoPokemon::
	msgbox DreamMap_Text_NoPokemon, MSGBOX_NPC
	msgbox DreamMap_Text_MoveAside, MSGBOX_NPC
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DreamMap_Movement_PlayerForcedBack
	waitmovement 0
	releaseall
	end

DreamMap_Movement_PlayerStepBack:
	walk_down
	walk_down
	face_up
	step_end

DreamMap_Movement_PlayerForcedBack:
	walk_down
	walk_down
	step_end

DreamMap_Movement_AgathaMoveAside:
	walk_down
	face_left
	walk_left
	face_right
	step_end
