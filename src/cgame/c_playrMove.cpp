#include <ncurses.h>
#include <memory>
#include <iostream>

#include "keycodes.h"
#include "nomaddef.h"
#include "playr.h"

void Playr::move_axis(int arrow)
{	
	std::unique_ptr<Game::Settings> setting = std::make_unique<Game::Settings>();
	ncurses_con();
	while ((arrow = getch()) == ARROW_LEFT || (arrow = getch()) == ARROW_RIGHT)
	{
		switch (arrow) {
		case : paxis -= ((setting->sensitivity + playr_speed) + 0.25f);
						 break;
		case ARROW_RIGHT: paxis += ((setting->sensitivity + playr_speed) + 0.25f);
						  break;
		};
	};
	ncurses_des();
	return;
}