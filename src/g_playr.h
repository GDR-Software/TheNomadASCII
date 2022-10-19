#ifndef _G_PLAYR_
#define _G_PLAYR_

#include "../n_shared.h"
#include "../n_keys.h"

#define DASH_SPEED		5
#define PLAYR_STD_SPEED	1
#define MAX_PNAME_CHARS 20

#ifdef __cplusplus
extern "C" {
#endif

#include "g_items.h"

typedef struct
{
	//char* guild;
	//short torpor;
	binds_t kb_binds;
	short py, px;
	short coin;
	short health;
	short armor;
	short speed;
	short wpn_in_hand[2] = { WPN_NULL, WPN_NULL };
	// 1 - wpn id
	// 2 - wpn current ammo
	char* P_wpns[11];
};

void P_rename(playr_t* playr);
void P_checkInput(playr_t* playr);
void P_processInput(playr_t* playr);

#ifdef __cplusplus
}
#endif

#endif