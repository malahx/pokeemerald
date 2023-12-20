EventScript_StartDexNavBattle::
	lock
	playse 0x15
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	dowildbattle    
	release
	end


EventScript_NotFoundNearby::
    msgbox sText_NotFoundNearby, MSGBOX_SIGN
    end
sText_NotFoundNearby:
    .string "Aucun Pokémon à proximité, Réessayez."


EventScript_MovedTooFast::
    msgbox sText_TryMovingSlower, MSGBOX_SIGN
    end
sText_TryMovingSlower:
    .string "Le Pokémon s'est échappé !\n"
    .string "Essayez d'avancer plus lentement.$"


EventScript_PokemonGotAway::
    msgbox sText_PokemonGotAway, MSGBOX_SIGN
    end
sText_PokemonGotAway:
    .string "Le Pokémon s'est échappé !$"


EventScript_LostSignal::
    msgbox sText_LostSignal, MSGBOX_SIGN
    end
sText_LostSignal:
    .string "Il n'y a pas de réaction.\n"
    .string "Le signal a été perdu !$"


EventScript_TooDark::
    msgbox sText_TooDark, MSGBOX_SIGN
    end
sText_TooDark:
    .string "Il fait trop sombre\npour chercher un Pokémon !$"
