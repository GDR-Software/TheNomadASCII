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
	Header File Including The One Massive Class That Is Used In All Elemen-
	ts Of This Game
##########################################################################
*/
// game.h

#ifndef _GAME_H_
#define _GAME_H_

class Game
{
public:
	float i_mult;
	int dif = 0;
	std::vector<std::vector<std::string>> HUD;
public:
	void entry_point();
	class Settings;
	class Externals;
};

#endif