#include "../n_shared.h"
#include "g_game.h"

static void I_processArgs(game_t* args)
{
	for (int i = 0; i < args->argc; i++) {
		if (args->myargv[i] == "-fastmobs") { // fast mobs
			args->solo.fastmobs = true;
		}
		if (args->myargv[i] == "-iwtbag") { // god mode
			args->solo.godmode = true;
		}
		//if (args->myargv[i] == "-devperms") { // dev permissions
		//	args->solo.devparm = true;
		//}
		//if (args->myargv[i] == "-noclip") { // collision checker off
		//	args->solo.collision = false;
		//}
		if (args->myargv[i] == "-nomobs") { // mob spawning off
			args->solo.nomobs = true;
		}
		//if (args->myargv[i] == "-peacemobs") { // peaceful mobs
		//	args->solo.passivemobs = true;
		//}
		//if (args->myargv[i] == "-tgdnec") { // bottomless clip, "that god damned never-ending clip"
		//	args->solo.bottomless_mag = true;
		//}
		if (args->myargv[i] == "-ammoinf") { // infinite ammunition
			args->solo.infinite_ammo = true;
		}
		//if (args->myargv[i] == "-nofric") { // friction off
		//	args->solo
		//}
	}
}

static void I_nomadInit(game_t* game)
{
	playr_t p;
	entity_base_t e;
	map_t a;
	if (game->solo.fastmobs) {
		e.mob_speed *= 2;
	}
	if (game->solo.godmode) {
		e.playr_killable = false;
	}
	// alll vars are initialized before loading an ngd. Data will be overwritten once
	// the user does this
	p.health = 100;
	p.armor = 12;
	p.speed = PLAYR_STD_SPEED;
	p.coin = 0;
	p.py = 0;
	p.px = 0;
	p.wpn_in_hand[0] = WPN_NULL;
	p.wpn_in_hand[1] = WPN_NULL;
	
	for (short i = 0; i < MAX_MOBS_ACTIVE; i++) {
		e.m_ActiveNames[i] = " ";
		e.m_ActiveSprite[i] = ' ';
		e.m_Active
	}
	
	mainLoop(p, m, *(&game), a, e);
}

int main(int argc, char* argv[])
{
	game_t game;
	if (argc) {
		I_processArgs(&game);
	}
	I_NomadInit(&game);
}