@	.include "data/maps/DreamMap/letpass.inc"

DreamMap_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamMap_OnTransition
	.byte 0

DreamMap_OnTransition::
	@ setworldmapflag FLAG_WORLD_MAP_DREAM_MAP
	msgbox DreamMap_Text_HelloWorld, MSGBOX_NPC 
	end

	
