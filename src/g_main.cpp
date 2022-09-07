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
	Game Entry Point
##########################################################################
*/
// main.cpp

#include <iostream>

#include "nomaddef.h"
#include "game.h"

void entry_point()
{
	game = std::make_unique<Game>();
	game->titleScreen();
}

int main()
{
	char d;
	std::cout << "'The Nomad' ASCII/Text-Based Roleplaying Game\n";
	std::cout << "Written In C/C++ By SIGAAM\n";
	std::cout << "Continue? [y/n]> "; std::cin >> d;
	if (d == 'y')
	{
		entry_point();
	}
	else {
		system("pause");
	}
}