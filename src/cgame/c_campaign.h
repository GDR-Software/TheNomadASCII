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
	The Game's Campaign Class
##########################################################################
*/
// campaign.h

#ifndef _CAMPAIGN_H_
#define _CAMPAIGN_H_

#ifdef _WIN32
	#pragma once
#endif

// for playr lives
#include <limits>
#include <algorithm>
#include <array>

namespace Campaign {
	class SoloPlayer
	{
	public:
		float extra_mult = 0.1f,
		float noob_mult = 1.3f,
		float recruit_mult = 3.7f,
		float merc_mult = 6.19f,
		float nomad_mult = 10.5f,
		float blackdeath_mult = 20.12f,
		float minorinconvenience_mult = 20.25f,
		float rng_mult = 0.05f
	public:
		float M_spawnMultiplier();
		float M_statMultiplier();
		float P_statMultiplier();
		float I_spawnMultiplier();
		float I_statMultiplier();
	
		int playr_lose_life();
		float L_spawnMultiplier();
		
		bool RNG_bool();
	};
	typedef enum
	{
		infinite_ammo,
		fast_mobs,
		infinite_lives,
		immortality,
		kaboom,
		double_speed,
		bottomless_mag,
		perm_invis,
		double_dmg,
	
		NUMEXTERNALS
	} externals_t;

	class External
	{
	public:
		int id_arr[NUMEXTERNALS] = {
			100, // infinite ammo
			101, // infinite lives
			102, // immortality
		};
		int id{};
		std::string name;
		
		const char* cheat_codes[NUMEXTERNALS] = { // cheats are essentially just externals, but you don't have to unlock them
			"IWTBAG", // I Want To Be A God, immortality
			"IWTLF", // I Want To Live Forever, infinite lives
			"FTEBS", // Faster Than Ever But Still, double speed
			""
		};
		void activate_external(void)
		{
			
		}
	
		void activate_cheat_code(void)
		{
			
		}
	};
};

#endif
