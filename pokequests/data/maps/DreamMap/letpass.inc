DreamMap_LetPass::
	lockall
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq CheckPokemonAndLetPass_2
	msgbox CheckPokemonAndLetPass_Text_1
DreamMap_CheckPokemonAndLetPass_1:
	releaseall
	return

DreamMap_CheckPokemonAndLetPass_2:
	msgbox CheckPokemonAndLetPass_Text_0
	goto CheckPokemonAndLetPass_1


DreamMap_CheckPokemonAndLetPass_Text_0:
	.string "Thanks for showing your Pokémon! You may pass.$"

DreamMap_CheckPokemonAndLetPass_Text_1:
	.string "Sorry, you need a Pokémon in your party to pass.$"
