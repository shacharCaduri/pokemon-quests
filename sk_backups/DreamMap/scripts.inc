.equ NPC_LOCAL_ID, 1

DreamMap_MapScripts::
	map_script MAP_SCRIPT_MY_SCRIPT, MyScript 
	.byte 0
 
MyScript::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PreMoveText
	closemessage
	msgbox MoveText
	closemessage
	setobjectmovementtype NPC_LOCAL_ID, MOVEMENT_TYPE_FACE_UP
	applymovement NPC_LOCAL_ID, MyScript_Movement
	setobjectmovementtype NPC_LOCAL_ID, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end
 
MyScript_Movement::
	walk_up
	step_end

