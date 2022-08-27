// Language: C++20
/*
##########################################################################
Copyright(c) 2021-2022 SIGAAMDAD

This file is part of The Nomad (ASCII) source code

The Nomad (ASCII) source code is distrubuted as free software. You can di-
stribute it and/or modify it, just make sure you credit me. This software
uses the terms and policies of the SACE Source Code License.

The Nomad (ASCII) source code is distributed in hopes that it could be us-
eful and/or helpful in your own projects. This game is meant for playing
and modification. So, have fun customizing the source code to your own pe-
rsonal wishes!

DESCRIPTION:
	Header File Containing The Non-Class Non-Function Macros, Constants, A-
	nd Variables
##########################################################################
*/
// nomaddef.h

#ifndef _NOMADDEF_H_
#define _NOMADDEF_H_

#include <ctime>
#include <cstdlib>
#include <cstdio>

#include "campaign.h"
#include "game.h"
#include "rng.h"
#include "playr.h"
#include "sounds.h"
#include "mob.h"
#include "thread.h"

// all dependencies
#include <SFML/Audio.hpp>

typedef enum
{
	infinite_ammo,
	fast_mobs,
	immortality,
	kaboom,
	double_speed,
	
	NUMEXTERNALS
} externals_t;
struct External
{
	int id_arr[NUMEXTERNALS] = {};
	int id{};
	char name[20];
};

std::unique_ptr<Game> game;
std::unique_ptr<Campaign> menu;
std::unique_ptr<Campaign> mult;
std::unique_ptr<Mob> spawn;
std::unique_ptr<Playr> playr;

void* operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void* memory)
{
	return free(memory);
}

void ncurses_con(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

void ncurses_des(void)
{
	refresh();
	getch();
	endwin();
}

srand(time(NULL));

#define BACK					'\b'
#define SPACE				' '
#define ENTER				'\n'

char c;

// standard ranges, doesn't apply to everything
#define RNG_CLOSE			10
#define RNG_MID				30
#define RNG_LONG				45
#define RNG_ULTRA			60

#define WMAP_NORTHWEST		1
#define WMAP_MIDWEST		2
#define WMAP_SOUTHWEST		3
#define WMAP_MIDSOUTH		4
#define WMAP_SOUTHEAST		5
#define WMAP_MIDEAST		6
#define WMAP_NORTHEAST		7
#define WMAP_MIDNORTH		8
#define WMAP_MIDDLE			9

// multipliers for the game, stuff like mob spawns, hp, and also dividers for ammo spawns and buffs
// the regular, easiest, and most kid-friendly difficulty
#define DIF_NOOB				0
// some teen content, more mature, harder
#define DIF_RECRUIT			1
// call of duty kind of content, as difficult as doom eternal
#define DIF_MERCENARY		2
// most dark content from the book is cut, but the difficulty is matched with the book
#define DIF_NOMAD			3
// everything bad *cancer, basically dark souls difficulty. No story cuts, hardest fucking thing ever, a scary mode.
#define DIF_BLACKDEATH		4

// stationary nomadic tribe
#define NOMAD_TRIBE_S		'%'
// wandering nomadic tribe
#define NOMAD_TRIBE_W		'*'

#define MOUNTAIN				'∆'
#define HILL					'^'
#define MINERAL_DEPO		'π'
#define TEMPLE				'Ω'

enum
{
	ammo762,
	ammo556,
	ammo9mm,
	ammo10mm,
	ammo45ACP,
	
	NUMBULLETS
};

#endif