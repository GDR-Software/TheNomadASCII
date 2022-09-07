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

#include <ncurses.h>

#ifndef _NOMADDEF_H_
#define _NOMADDEF_H_

#ifndef null
#define null 0
#endif

#ifdef _WIN32
	// normal win32 headers
	#include <windows.h>
	#include <conio.h>
	#include <mmsystem.h>
	#include <shellapi.h>
	// dos.h isn't really normal, but it's used for some cli shit
	#include <dos.h>

	// windows x86/32 lean and mean
	#define WIN32_LEAN_AND_MEAN
	
	// don't ask
	#define WINDOWS_FOR_PUSSIES
	#define WFP
	#pragma once
#elif __linux__
	#include <unistd.h>
	#include <termios.h>
	
	// since it's a free os
	#define LINUX_FOR_ALL
	#define LFA
#else
// using anything other than linux and/or windows will make this program lose a lot of functionality, but it'll still run
	#define UNKOWN_OS
	#define NOMAD_VM
#endif

/*#if __cplusplus == 1
	#define _CPP_PRE98
	#define _ANCIENT_CPP
#elif __cplusplus == 199711L
	#define _CPP_98
	#define _BOOMER_CPP
#elif __cplusplus == 201103L
	#define _CPP_11
	#define _OLD_CPP
#elif __cplusplus == 201402L
	#define _CPP_14
	#define _DECENT_CPP
#elif __cplusplus == 201703L
	#define _CPP_17
	#define _MODERNISH_CPP 
*/
#if __cplusplus == 202002L
	#define _CPP_20
	#define _IDEAL_CPP
#else
	#define _CPP_INCOMPAT
#endif

/*
#if defined(__clang__)
	
#elif defined(__GNUG__)
	
#endif

void* operator new(size_t size)
{
	return malloc(size);
}

void operator delete(void* memory)
{
	return free(memory);
}
*/

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
#define DIF_NOOB						0
// some teen content, more mature, harder
#define DIF_RECRUIT					1
// call of duty kind of content, as difficult as doom eternal
#define DIF_MERCENARY				2
// most dark content from the book is cut, but the difficulty is matched with the book
#define DIF_NOMAD					3
// everything bad *cancer, basically dark souls difficulty. No story cuts, hardest fucking thing ever, a scary mode.
#define DIF_BLACKDEATH				4
// somehow, this mode is harder than BD, w/ permadeath
#define DIF_MINORINCONVENIENCE		5

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