// Language: C++20
/*
##########################################################################
Copyright(c) 2021-2022 SIGAAMDAD

This file is part of The Nomad (ASCII) source code

The Nomad (ASCII) source code is distrubuted as free software. You can di-
stribute it and/or modify it, just make sure you credit me. This software
uses the terms and policies of the GNU General Public License as published
by the Free Software Foundation

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

class Campaign
{
private:
	float extra_mult = 0.1f;
	float noob_mult = 1.3f; // can ya shoot straight lad? or are ya fuckin' blind?
	float recruit_mult = 3.7f; // baby steps
	float merc_mult = 6.19f; // medium shit
	float nomad_mult = 10.5f; // game's pretty hard
	float blackdeath_mult = 20.12f; // they're asking for it
public:
	float M_spawnMultiplier();
	float M_statMultiplier();
	float P_statMultiplier();
	
	float I_spawnMultiplier();
	float I_statMultiplier();
	
	float L_spawnMultiplier();
};

#endif
