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
	Bullets Header File, Self-Explanatory
##########################################################################
*/
// bullet.h

#ifndef _BULLET_H_
#define _BULLET_H_

class Bullet
{
public:
	std::array<int> bullet_ls = {
		762,
		556,
		9,
		10,
		45,
		
	};
	std::array<int> bullet_dmg = {
	
	};
};

#endif