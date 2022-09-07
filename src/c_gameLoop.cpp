#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include "nomaddef.h"
#include "c_playr.h"
#include "c_mob.h"
#include "c_game.h"
#include "c_animation.h"
#include "g_sounds.h"

using namespace std::chrono_literals;

// constexpr std::chrono::nanoseconds framerate(66ms); // 15 fps, 1000/15
constexpr std::chrono::nanoseconds tickrate(66ms); // 15 ticks per seconds, 15 game updates per seconds

enum : unsigned int
{
	GS_MENU, // in a menu
	GS_LEVEL, // in a pre-made level
	GS_ROAM // in a free-roam world
};
int gamestate = GS_MENU;

static void update()
{
	if (game->gamever == CAMPAIGN)
	{
		std::thread renderer(motion->renderLoop);
		renderer.join();
		std::thread (mob->mobLoop).detach();
		std::thread (playr->playrLoop).detach();
		if (game->using_npc)
		{
			std::thread (npc->npcLoop).detach();
		}
	}
	else if (game->gamever == FREEROAM)
	{
		std::thread renderer(motion->renderLoop);
		renderer.join();
		std::thread (mob->mobLoop).detach();
		std::thread (playr->playrLoop).detach();
		std::thread (npc->npcLoop).detach();
	}
}

void Game::gameLoop()
{
	//using clock = std::chrono::high_resolution_clock;
	//std::chrono::nanoseconds lag(0ns);
	//auto time_start = clock::now();
	bool quit_game = false;
	while (!quit_game)
	{
		std::thread updateGame(update);
		std::this_thread::sleep_for(std::chrono::millseconds(tickrate));
		updateGame.join();
	//	auto delta_time = clock::now() - time_start;
	//	time_start = clock::now();
	//	lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
	//	while (lag >= framerate)
	//	{
	//		lag -= framerate;
	//		update();
	//	};
		
	//	auto alpha = (float) lag.count() / framerate.count();
	};
}