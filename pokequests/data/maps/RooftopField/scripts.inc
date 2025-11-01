RooftopField_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RooftopField_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, RooftopField_OnResume
	.byte 0

RooftopField_OnTransition::
	setflag FLAG_IN_ROOFTOP_FIELD
	end

RooftopField_OnResume::
	setflag FLAG_IN_ROOFTOP_FIELD
	end

RooftopField_EventScript_GrassSign::
	msgbox RooftopField_Text_GrassSign, MSGBOX_SIGN
	end

RooftopField_EventScript_WaterSign::
	msgbox RooftopField_Text_WaterSign, MSGBOX_SIGN
	end

RooftopField_EventScript_RockSign::
	msgbox RooftopField_Text_RockSign, MSGBOX_SIGN
	end
