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
	clearflag FLAG_IN_ROOFTOP_FIELD
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
	goto_if_set FLAG_AGATHA_GAVE_HM_POKEMON, DreamMap_AgathaTalk_RepeatFinal
	msgbox DreamMap_Text_OhGodForgotHMs, MSGBOX_DEFAULT
	closemessage
	getpartysize
	compare VAR_RESULT, 6
	call_if_eq DreamMap_WarnPartyFull
	bufferspeciesname STR_VAR_1, SPECIES_MARILL
	givemon SPECIES_MARILL, 1
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	copyvar VAR_TEMP_1, VAR_RESULT
	compare VAR_TEMP_1, 0
	call_if_eq DreamMap_SetMarillMove
	compare VAR_TEMP_1, 1
	call_if_eq DreamMap_MarillSentToPC
	bufferspeciesname STR_VAR_1, SPECIES_GEODUDE
	givemon SPECIES_GEODUDE, 1
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	copyvar VAR_TEMP_2, VAR_RESULT
	compare VAR_TEMP_2, 0
	call_if_eq DreamMap_SetGeodudeMove
	compare VAR_TEMP_2, 1
	call_if_eq DreamMap_GeodudeSentToPC
	msgbox DreamMap_Text_ReceivedHMPokemon, MSGBOX_DEFAULT
	setflag FLAG_AGATHA_GAVE_HM_POKEMON
	releaseall
	end

DreamMap_WarnPartyFull::
	msgbox DreamMap_Text_PartyFullWillSendToPC, MSGBOX_DEFAULT
	closemessage
	return

DreamMap_SetMarillMove::
	getpartysize
	setmonmove VAR_RESULT, 0, MOVE_SURF
	return

DreamMap_SetGeodudeMove::
	getpartysize
	setmonmove VAR_RESULT, 0, MOVE_ROCK_SMASH
	return

DreamMap_MarillSentToPC::
	msgbox DreamMap_Text_MarillSentToPC, MSGBOX_DEFAULT
	closemessage
	return

DreamMap_GeodudeSentToPC::
	msgbox DreamMap_Text_GeodudeSentToPC, MSGBOX_DEFAULT
	closemessage
	return

DreamMap_AgathaTalk_RepeatFinal::
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

DreamMap_EventScript_PC::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	setvar VAR_0x8004, HELPCONTEXT_PC
	special Script_SetHelpContext
	setvar VAR_0x8004, 0
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_BootedUpPC
	goto DreamMap_EventScript_PCMainMenu
	end

DreamMap_EventScript_PCMainMenu::
	message Text_AccessWhichPC
	waitmessage
	special CreatePCMenu
	waitstate
	switch VAR_RESULT
	case 0, DreamMap_EventScript_AccessPokemonStorage
	case 1, DreamMap_EventScript_AccessPlayersPC
	case 2, DreamMap_EventScript_AccessProfOaksPC
	case 3, DreamMap_EventScript_AccessHallOfFame
	case 4, DreamMap_EventScript_TurnOffPC
	case SCR_MENU_CANCEL, DreamMap_EventScript_TurnOffPC
	end

DreamMap_EventScript_AccessPokemonStorage::
	playse SE_PC_LOGIN
	msgbox Text_AccessedBillsPC
	msgbox Text_OpenedPkmnStorage
	special ShowPokemonStorageSystemPC
	waitstate
	setvar VAR_0x8004, HELPCONTEXT_PC
	special Script_SetHelpContext
	goto DreamMap_EventScript_PCMainMenu
	end

DreamMap_EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox Text_AccessedPlayersPC
	special PlayerPC
	waitstate
	goto DreamMap_EventScript_PCMainMenu
	end

DreamMap_EventScript_AccessProfOaksPC::
	goto_if_unset FLAG_SYS_POKEDEX_GET, DreamMap_EventScript_TurnOffPC
	playse SE_PC_LOGIN
	msgbox Text_AccessedProfOaksPC
	msgbox Text_HavePokedexRated, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DreamMap_EventScript_ExitOaksPC
	setflag FLAG_OAKS_RATING_IS_VIA_PC
	call PokedexRating_EventScript_Rate
	clearflag FLAG_OAKS_RATING_IS_VIA_PC
	goto DreamMap_EventScript_ExitOaksPC
	end

DreamMap_EventScript_ExitOaksPC::
	msgbox Text_ClosedLinkToProfOaksPC
	goto DreamMap_EventScript_PCMainMenu
	end

DreamMap_EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, DreamMap_EventScript_TurnOffPC
	playse SE_PC_LOGIN
	setvar VAR_0x8004, HELPCONTEXT_PC_MISC
	special BackupHelpContext
	special Script_SetHelpContext
	special HallOfFamePCBeginFade
	waitstate
	special RestoreHelpContext
	goto DreamMap_EventScript_PCMainMenu
	end

DreamMap_EventScript_TurnOffPC::
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	special AnimatePcTurnOff
	special SetHelpContextForMap
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
