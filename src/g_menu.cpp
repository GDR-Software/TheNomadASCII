#include <iostream>
#include <ncurses.h>
#include <vector>
#include <fstream>

#include "nomaddef.h"
#include "campaign.h"
#include "game.h"

int s = 0;
int key{};

std::vector<std::string> menu;

bool done = false;

using namespace std::chrono_literals;

void Game::titleScreen()
{
	std::fstream file;
	std::string line;
	menu = std::make_unique<Campaign>();
	while (!done)
	{
		file.open("../Files/GameScreens/Menus/title_screen.txt", std::ios::in);
		menu.clear();
		while (std::getline(file, line))
		{
			menu.push_back(line + "\n");
		};
		for (const auto &i : menu)
			std::cout << i;
		c = getchar();
		switch (c) {
		case ENTER: menu->menuMain();
					break;
		case BACK: EXIT_SUCCESS;
				   break;
		};
	};
}

void Campaign::arcadeScreen()
{
	std::string line;
	std::fstream file;
	ncurses_con();
	while ((key = getch()) != '\b')
	{
		file.open("../File/GameScreens/Menus/arcade_screen_select" + s + ".txt", std::ios::in);
		menu.clear();
		while (std::getline(file, line))
		{
			menu.push_back(line + "\n");
		};
		for (const auto &i : menu)
			std::cout << i;
		switch (key) {
		case KEY_UP: s--;
					 break;
		case KEY_DOWN: s++;
					   break;
		case 
		};
	};
	ncurses_des();
}

void Campaign::menuMain()
{
	game = std::make_unique<Game>();
	std::string line;
	std::fstream file;
	ncurses_con();
	while ((key = getch()) != '\b')
	{
		file.open("../Files/GameScreens/Menus/main_menu_select" + s + ".txt", std::ios::in);
		menu.clear();
		while (std::getline(file, line))
		{
			menu.push_back(line + "\n");
		};
		for (const auto &i : menu)
			std::cout << i;
		switch (key) {
		case KEY_UP: s--;
					 break;
		case KEY_DOWN: s++;
					   break;
		case BACK: game->titleScreen();
				   break;
		case ENTER: game->menuScreens[s];
					break;
		default: break;
		};
		s = 0;
	};
	ncurses_des();
}

void Campaign::menuMult()
{

}

void Campaign::campaignScreen()
{
	
}