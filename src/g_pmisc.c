#include "n_shared.h"

#include "g_playr.h"

// misc. player functions

void P_rmName(playr_t* playr)
{
	if (sizeof(playr->name) == sizeof(char*)) {
		HudPrintf("");
	}
}

void P_name(playr_t* playr, const char* new_name)
{
	
}

void* G_playrLoop(playr_t* playr)
{
	if (!playr->alive) {
		game_t dif;
		do {
			
			if (playr)
		} while(!playr->alive);
	}
}

bool P_checkInput(int c)
{
	if ((c = getchar()) != 0) {
		return true;
	}
	microDelay(15); // should be 20, but its an unorganic system
	if ((c = getchar()) != 0) {
		return true;
	}
	return false;
}