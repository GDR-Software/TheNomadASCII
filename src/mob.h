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
	Mob Header File
##########################################################################
*/
// mob.h

#ifndef _MOB_H_
#define _MOB_H_

#include <memory>
#include <vector>

#include "nomaddef.h"

class Mob
{
private:
	std::vector<std::string> m_ActiveNames;
	std::vector<float> m_ActiveHP;
	std::vector<float> m_ActiveY;
	std::vector<float> m_ActiveX;
	std::vector<char> m_ActiveSprite;
	std::vector<int> m_ActiveID;
public:
	int mobID; // this is the variable that is used to located a temp mob's stats in the vectors, then remove the stats
	float spawnMult = 2.55f;
	float statMult = 3.06f;
public:
	std::unique_ptr<Item> mobGear;
};

#endif
