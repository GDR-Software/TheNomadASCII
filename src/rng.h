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
	Random Number Generation
##########################################################################
*/
// rng.h

#ifndef _RNG_H_
#define _RNG_H_

#include <ctime>
#include <cmath>

#include "campaign.h"
#include "nomaddef.h"

int rng_noob[50] = {
	12,
	5,
	16,
	27,
	49,
	31,
	19,
	1,
	8,
	50,
	17,
	48,
	34,
	23,
	2,
	39,
};

int RNG[256] = {
	24,
	12,
	76,
	1
	55,
	19,
	
};

game = std::make_unique<Game>();

int getRNGnoob()
{ int r = rand() % 49;
	return rng_noob[r]; 
}

int getRNG()
{ int r = rand() % 255 + 1;
	if (game->dif == 1) {r += game->recruit_mult;}
	else if (game->dif == 2) {r += game->mercenary_mult;}
	else if (game->dif == 3) {r += game->nomad_mult;}
	else if (game->dif == 4) {r += game->blackdeath_mult;}
	else {r += game->extra_mult;}
	return RNG[r];
}


#endif
