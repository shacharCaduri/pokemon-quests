DreamMap_MapScripts::
	.byte 0

DreamMap_Blocker::
	lockall
	msgbox DreamMap_Blocker_Text_0
	releaseall
	return


DreamMap_Blocker_Text_0:
	.string "It's a Celebi.$"
	
DreamMap_BlockEnter::
	goto_if_set FLAG_BLOCK_ENTERANCE_DREAM_MAP, DreamMap_BlockEnter_1
	hide
	return

DreamMap_BlockEnter_1:
	call
	MyScript
	return


DreamMap_MyScript::
	lock
	faceplayer
	goto_if_set FLAG_HAVE_AT_LEAST_ONE_POKEMON, MyScript_2
	msgbox MyScript_Text_1
DreamMap_MyScript_1:
	release
	end

DreamMap_MyScript_2:
	msgbox MyScript_Text_0
	set
	FLAG_BLOCK_ENTERANCE_DREAM_MAP
	goto MyScript_1


DreamMap_MyScript_Text_0:
	.string "You can pass now, catch'em all!$"

DreamMap_MyScript_Text_1:
	.string "Hmm, you don't have any pokemon by your side, without you cannot go into the grass here.$"
	
