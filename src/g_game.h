#ifndef _G_GAME_
#define _G_GAME_

#ifndef NOMADMAIN
#define NOMADMAIN
#endif

#include "n_shared.h"
#include "n_bff.h"
#include "c_campaign.h"
#include "g_map.h"
#include "g_entity.h"
#include "g_playr.h"
#include "g_mob.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HUD				0
#define INVENTORY		1
#define MAP				2
#define PAUSE			3

#define MAX_HUD_HEIGHT	50

typedef char hud_layer_t;

typedef struct
{
	char* c_hud[MAX_HUD_HEIGHT];
	hud_layer_t c_hud_tbox[c_hud_tbox_y][c_hud_tbox_x];
	short c_hud_tbox_y;
	short c_hud_tbox_x;
	
	bool game_is_running;
	
	long ticcount;
	
	bff_t bff;
	soloplayr_t* solo;
	map_t* map;
} game_t;

void WaitFor(game_t game, int ticks);
void mainLoop(playr_t playr, game_t game);
void STD(void);

#ifdef __cplusplus
}
#endif

#endif