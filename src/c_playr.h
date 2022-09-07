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
	The Game's Player Class
##########################################################################
*/
// playr.h

#ifndef _PLAYR_H_
#define _PLAYR_H_

#ifdef _WIN32
	#pragma once
#endif

#include <memory>
#include <string>

#include "c_campaign.h"
#include "nomaddef.h"
#include "c_item.h"
#include "g_weapon.h"

namespace Campaign {
	std::unique_ptr<Playr> playr = std::make_unique<Playr>();
	class Playr
	{
	private:
		bool flash = false;
		bool showing_wpns = false;
	public:
		float playr_stat_mult = 15.7f; // noob difficulty stat mult
		uint16_t playr_hp = 100; // health
		float playr_aq = 12.5f; // armor quality
		uint32_t playr_coin = 10;
		bool playr_alive = true;
		const float playr_height = 2.5; // round to 3
		float py = playr_height;
		float pz{};
		float px{};
		float playr_speed = 1.0f;
		char next_space = ' ';
		const std::string playr_name;
		std::string P_wpn[8] = {
			"NULL", "NULL", // reg sidearm, heavy sidearm
			"NULL", "NULL", // reg primary, heavy primary
			"NULL", "FIST", // anti-material, melee 1
			"NULL", "NULL" // melee 2, melee 3
		};
		
		int P_grenade[4][2] = {
			{null, 0},
			{null, 0},
			{null, 0},
			{null, 0}
		};
		int map_active = WPMAP_MIDDLE;
		std::string wpn_in_hand{};
		int wih = wpn_id[wpn_in_hand];
		int wpn_in_hand_ammo{};
		int wpn_in_hand_reserves{};
	};
};

#endif