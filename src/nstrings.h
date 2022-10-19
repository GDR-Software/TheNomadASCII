#ifndef _NSTRINGS_
#define _NSTRINGS_

#include "n_shared.h"

#define K_MOVEN							"MOVE NORTH / FOREWARD"
#define K_MOVEW							"STRAFE WEST / LEFT"
#define K_MOVES							"MOVE SOUTH / BACK"
#define K_MOVEE							"STRAFE EAST / RIGHT"
#define K_SHOWWPNS						"SHOW CURRENT WEAPONS"
#define K_SLIDE							"SLIDE"
#define K_RUN							"RUN"
#define K_SHOOT							"SHOOT / FIRE GUN"
#define K_DASH							"DASH / SUPER-SPRINT"
#define K_JUMP							"JUMP"
#define K_RELOAD						"RELOAD"
#define K_SWITCHWPNS					"SWITCH WEAPONS"
#define K_TURNLEFT						"TURN LEFT"
#define K_TURNRIGHT						"TURN RIGHT"
#define K_ADS							"AIM DOWN SIGHTS (ADS)"
#define K_ALTAIM						"ALTERNATE ADS / SCOPING"
#define K_MELEE							"MELEE"
#define K_FLASHYKILL					"GLORY KILL"
#define K_THROWGRND						"THROW ORDNANCE"
#define K_OPENCHAT						"OPEN CHAT"
#define K_SAYTOCHAT						"SAY TO CHAT"
	// can either be over a network game or a single-player game
#define K_OPENCONSOLE					"OPEN CMD CONSOLE"
#define K_FLASHLIGHT					"TURN ON FLASHLIGHT"
#define K_SWIMUP						"SWIM UP"
#define K_SWIMDOWN						"SWIM DOWN"

#ifdef REALISM_SUPER

#define GOTSHELLS_12					"Picked Up 6 12-gauge Shells"
#define GOTSHELLS_12_BOX				"Picked Up A Box of 12-gauge Shells"

#define GOTSHELLS_20					"Picked Up 10 20-gauge Shells"
#define GOTSHELLS_20_BOX				"Picked Up A Box of 20-gauge Shells"

#define GOTBULLETS_762					"Picked Up A Clip of 7.62mm Bullets"
#define GOTBULLETS_762_BOX				"Picked Up An Extended Clip of 7.62mm Bullets"

#define PLAYRWATER_LOW					"Water Levels Low!"
#define PLAYRWATER_CRITICAL				"Water Critical, Dehydration Eminent!"

#define PLAYRFOOD_LOW					"Food Levels Low!"
#define PLAYRFOOD_CRITICAL				"Food Critical, Starvation Eminent!"

#define PLAYRBLEEDING_LOW				"You're Bleeding Out Slowly!"
#define PLAYRBLEEDING_ALOT				"You're Bleeding Heavily!"

#define PLAYRTIRED_LOW					"You Feel A Bit Tired"
#define PLAYRTIRED_ALOT					"You Feel Very Tired, Take A Nap"

#elif REALISM_COD

#elif REALISM_DOOM

#define GOTSHELLS						"You Picked Up 8 Shells"
#define GOTSHELLS_BOX					"You Picked Up A Box of Shells"
	// really is just 16 shells
#define GOTSHELLS_BOX_1					"You Picked Up 16 Shells"

#define GOTBULLETS						"You Picked Up A Clip"
#define GOTBULLETS_BOX					"You Picked Up A Box of Bullets"
#define GOTBULLETS_1					"You Picked Up An Extended Magazine"

#define GOTROCKETS						"You Picked Up A Rocket"
#define GOTROCKETS_BOX					"You Picked Up A Barrel of Rockets"
#define GOTROCKETS_1					"You Picked Up 10 Rockets"

#endif

#define PLAYRHP_LOW						"Health Low, Medpacks Advised!"
#define PLAYRHP_CRITICAL				"Near Death, Seek Medical Attention!"

#define PLAYRDEAD_NORM					"YOU HAVE DIED!"
#define PLAYRDEAD_FUNNY_1				"U GOT REKT! GIT GUD!"
#define PLAYRDEAD_FUNNY_2				"U R DED! NO BIG SOOPRISE!"
#define PLAYRDEAD_BRUTAL				"The Walls Have Been Painted In Your Guts"

#define FOUND_SECRET					"You Found A Secret!"

#ifdef EMPOWERED_MOBS

#define EM_IN_AREA						"Empowered Mob In Your Area! Watch Out!"
#define EM_DEAD							"Empowered Mob Has Died! Snatch The Goods!"
#define EM_BOSS							"Empowered Boss Has Spawned! Death Awaits You..."

#endif

#endif