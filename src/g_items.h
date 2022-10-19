#ifndef _G_ITEMS_
#define _G_ITEMS_

#include "n_shared.h"

enum
{
	// snipers
	HOSIG,
	DesertRifle,
	FAL50,
	
	// assault rifles
	AK77,
	M32B5,
	RAGm15,
	RAGm14,
	RAGm13,
	
	// SMGs
	SDSG,
	
	
	// anti-personnel
	M79,
	
	// pistols
	AUPm9,
	COLT7011,
	Browning49,
	
	NUMWPNS
}

enum
{
	HP_TINY,
	HP_NORMAL,
	HP_BIG,
	
	BANDAGE, // basically HP_NORMAL but stops player from bleeding
	
	AP_STREET, // armor version of HP_TINY
	AP_ARMY, // armor version of HP_NORMAL
	AP_MERC, // armor version of HP_BIG
	
	FLAK, // armor version of BANDAGE, but negates armor piercing and increases armor by small amount
	
	NUMITEMS
}

typedef struct
{
	const char* name;
	short dmg;
	short firerate;
	short range;
} weapon_t;

typedef struct
{
	const char* name;
	short chance_to_drop_from_mob;
	short chance_to_spawn;
	
	short capacity; // how much in lbs it can carry
	short base_weight; // how much the backpack itself is
	short cost;
	
	short scrap; // scrap metal
	short ore; // the basic building block of anything in the game
	short rubber; // for strings, elastic stuff
	short craft_skill_pr;
} item_t;

extern uint16_t floorpickups[4][2];

extern item_t iteminfo[NUMITEMS];
extern weapon_t wpninfo[NUMWPNS];

#endif