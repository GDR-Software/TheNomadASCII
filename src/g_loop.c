#include "n_shared.h"
#include "g_game.h"
#include "g_playr.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

unsigned int tickrate = ;

// a literal single-tick-delay
void STD(void)
{
	usleep(/);
}

// this is essentially a tickrate-based game timer, might be a bit off, but it'll work
// this tick timer won't be in sync with the main game loop, unlike doom
void WaitFor(game_t game, int ticks)
{
	int ttick = game.ticcount + ticks;
	int ctick = game.ticcount;
	while (ctick != tticks)
	{
		STD();
		ctick = game.ticcount;
	}
	return;
}

void mainLoop(playr_t playr, mobj_t mob, game_t game, map_t map, entity_base_t e)
{
	pthread_attr_t p_thread;
	pthread_t p, m;
	pthread_attr_init(&p_thread);
	pthread_attr_setdetachstate(&p_thread, PTHREAD_MAKE_DETACHED);
	pthread_create(&p, &p_thread, &G_playrLoop, &playr);
	do {
		STD();
		game.ticcount++; // used for in-game delays, animations, etc.
		pthread_create(&m, NULL, &M_makeMob, &mob);
		if (game.redraw) {
			printScreen();
			game.redraw = false;
		}
		pthread_join(&m);
	} while (game.game_is_running);
}