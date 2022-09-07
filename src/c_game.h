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

#ifdef _WIN32
	#pragma once
#endif

#include <memory>

namespace Campaign {
	std::unique_ptr<Game> game;
	class Game
	{
	public:
		float i_mult;
		int dif = 0;
		char HUD[75][26];
	public:
		void entry_point();
	};
};

#endif