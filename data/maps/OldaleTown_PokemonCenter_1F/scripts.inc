.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

Script_Synchronise_NPC::
	lock
	faceplayer
	goto_if_set FLAG_SYNCHRONIZE_ENABLED, Synchronise_NPC_DoYouWantMeToStop
	showmoneybox 0, 0
	msgbox Text_Synchronise_NPC_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Synchronise_NPC_PleaseComeAgain
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, Synchronise_NPC_NotEnoughMoney
	removemoney 1000
	updatemoneybox
	playse SE_SHOP
	msgbox Text_Synchronise_NPC_ExplainSynchronise
	hidemoneybox
	setflag FLAG_SYNCHRONIZE_ENABLED
	release
	end

OldaleTown_EventScript_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox OldaleTown_House1_Text_Kirlia, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	
Synchronise_NPC_DoYouWantMeToStop::
	msgbox Text_Synchronise_NPC_DoYouWantMeToStop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Synchronise_NPC_PleaseComeAgain
	msgbox Text_Synchronise_NPC_StoppedSynchronise
	clearflag FLAG_SYNCHRONIZE_ENABLED
	release
	end

Synchronise_NPC_PleaseComeAgain::
	msgbox Text_Synchronise_NPC_PleaseComeAgain
	hidemoneybox
	release
	end

Text_Synchronise_NPC_Intro::
	.string "Shall I foresee the NATURE of those\n"
	.string "fateful allies you have yet to meet?\p"
	.string "I'll charge you just ¥1000.\n"
	.string "Wouldn't you like to know your fate?$"

Text_Synchronise_NPC_PleaseComeAgain::
	.string "Very well, please come again if\n"
	.string "you desire to change your fate.$"

Text_Synchronise_NPC_ExplainSynchronise::
	.string "Very well, now every wild POKéMON will\n"
	.string "synchronise with your leading partner.\p"
	.string "You can talk to me again if you\n"
	.string "want me to stop using my powers.$"

Text_Synchronise_NPC_DoYouWantMeToStop::
	.string "Do you want me to stop my power?$"

Text_Synchronise_NPC_StoppedSynchronise::
	.string "Very well, it is done. I can no longer\n"
	.string "foresee the fate of your fateful allies.$"

Synchronise_NPC_NotEnoughMoney::
	msgbox Text_Synchronise_NPC_NotEnoughMoney
	hidemoneybox
	release
	end

Text_Synchronise_NPC_NotEnoughMoney:
	.string "You don't have enough money.$"

OldaleTown_House1_Text_Kirlia:
	.string "KIRLIA: Kiii.$"
