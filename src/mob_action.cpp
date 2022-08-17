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
	Mob/Enemy/Monster Actions
##########################################################################
*/
// mob_action.cpp

#include <memory.h>

#include "mob.h"

std::unique_ptr<Playr> tempMob = std::make_unique<Playr>();

Mob::Mob(std::string mobName)
{
	for (size_t i = 0; i < mName.size(); i++)
	{
		if (mName[i] == mobName)
		{
			returnM_name(i);
			returnM_hp(i);
			returnM_wpn(i);
		}
	}
}

Mob::~Mob()
{
	tempMob->T_mobName = nullptr;
	tempMob->T_mobHP = nullptr;
	tempMob->T_mobWpn = nullptr;
}

void Mob::returnM_hp(int mIndex)
{
	int mhp = mHP[mIndex];
	tempMob->T_mobHP = &mhp;
	return;
}
