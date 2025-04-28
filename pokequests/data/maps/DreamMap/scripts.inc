@	.include "data/maps/DreamMap/letpass.inc"

DreamMap_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamMap_OnTransition
	.byte 0

DreamMap_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
	@msgbox DreamMap_Text_HelloWorld, MSGBOX_DEFAULT 
	end

DreamMap_AgathaTalk::
	lockall
	msgbox DreamMap_Text_HelloWorld, MSGBOX_NPC
	releaseall
	end
