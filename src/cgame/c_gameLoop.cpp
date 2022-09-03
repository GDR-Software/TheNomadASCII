#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include "nomaddef.h"
#include "playr.h"
#include "mob.h"
#include "game.h"
#include "sounds.h"

using namespace std::chrono_literals;

constexpr std::chrono::nanoseconds framerate(66ms); // 15 fps, 1000/15

enum : unsigned int
{
	GS_MENU, // in a menu
	GS_LEVEL, // in a pre-made level
	GS_ROAM // in a free-roam world
};
int gamestate = GS_MENU;

game = std::make_unique<Game>();
mob = std::make_unique<Mob>();
playr = std::make_unique<Playr>();
void update()
{
	std::unique_ptr<NPC> npc = std::make_unique<NPC>();
	if (gamestate == GS_MENU)
	{
		if (game->menu_done)
		{
			gamestate++;
		}
		else {
			return;
		}
	}
	else if (gamestate == GS_LEVEL)
	{
		std::thread hudthread(game->updateHUD);
		std::thread mobthread(mob->updateMobs);
		std::thread playrthread(playr->cmdPrompt);
		playrthread.join();
		hudthread.join();
		mobthread.join();
	}
	else if (gamestate == GS_ROAM)
	{
		std::thread hudthread(game->updateHUD);
		std::thread mobthread(mob->updateMobs);
		std::thread npcthread(npc->updateNPCs);
		std::thread playrthread(playr->cmdPrompt);
		playrthread.join();
		hudthread.join();
		mobthread.join();
		npcthread.join();
	}
}

void Game::gameLoop()
{	
	using clock = std::chrono::high_resolution_clock;
	std::chrono::nanoseconds lag(0ns);
	auto time_start = clock::now();
	bool quit_game = false;
	while (!quit_game)
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
		quit_game = handle_events();
		
		while (lag >= framerate)
		{
			lag -= framerate;
			update();
		};
		
		auto alpha = (float) lag.count() / framerate.count();
		std::thread screen(game->printScreen);
		printScreen.join(); // to prevent insane lag/crashes
	};
}