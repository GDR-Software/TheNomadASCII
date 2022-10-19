// Language: C/C++20
//-----------------------------------------------------
// Copyright (C) 2022-2023, GDR Software
//
// This file is part of The Nomad (ASCII) source code,
// and you may only modify, redistribute it under the 
// terms of the SACE License.
//
// This source code is distributed freely with hopes that
// it could be useful/helpful for one of your own projects.
//
// All repos/files using the SACE engine are copyrighted
// by GDR Software.
//
// DESCRIPTION:
//	random number generation header file with functions
//----------------------------------------------------- 
// /src
// g_rng.h

#ifndef _G_RNG_
#define _G_RNG_

#include "n_shared.h"

#define SCRAMBLE(x) \
{\
	SEED;\
	return x &= rand() % MAXINT;\
}

long long htod(long hexa)
{
	char hex[20];
	long long decimal = 0, base = 1;
	int i = 0, value, length;
	/* Get hexadecimal value from user */
	length = strlen(hex);
	for(i = length--; i >= 0; i--)
	{
		if(hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if(hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if(hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
	}
	return decimal;
}

extern const unsigned short RNG[256];
unsigned int randint(void);

int P_random(void);
int getRNG(game_t* dif);

#endif