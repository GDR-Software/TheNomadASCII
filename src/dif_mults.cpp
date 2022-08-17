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
	Multipliers Determined Based On Campaign Difficulty
##########################################################################
*/
// dif_mults.cpp

#include <math.h>
#include <time.h>
#include <memory.h>

#include "campaign.h"
#include "nomaddef.h"

std::unique_ptr<Game> mod = std::make_unique<Game>();
std::unique_ptr<Mob> num = std::make_unique<Mob>();
std::unique_ptr<Playr> game = std::make_unique<Playr>();

float mult;

float Campaign::M_spawnMultiplier()
{ mult = 0.0f;
	if (mod->dif == 0) {mult = num->spawnMult * (noob_mult + extra_mult);}
	else if (mod->dif == 1) {mult = num->spawnMult * (recruit_mult + extra_mult);}
	else if (mod->dif == 2) {mult = num->spawnMult * (merc_mult + extra_mult);}
	else if (mod->dif == 3) {mult = num->spawnMult * (nomad_mult + extra_mult);}
	else if (mod->dif == 4) {mult = num->spawnMult * (blackdeath_mult + extra_mult);}
	else {mult = num->spawnMult + extra_mult;} // kinda sorta undefined behaviour, leaves room for mods
	return mult;
}

float Campaign::M_statMultiplier()
{ mult = 0.0f;
	if (mod->dif == 0) {mult = num->statMult * (noob_mult + extra_mult);}
	else if (mod->dif == 1) {mult = num->statMult * (recruit_mult + extra_mult);}
	else if (mod->dif == 2) {mult = num->statMult * (merc_mult + extra_mult);}
	else if (mod->dif == 3) {mult = num->statMult * (nomad_mult + extra_mult);}
	else if (mod->dif == 4) {mult = num->statMult * (blackdeath_mult + extra_mult);}
	else {mult = num->spawnMult + extra_mult;} // kinda sorta undefined behaviour, leaves room for mods
	return mult;
}

float Campaign::P_statMultiplier()
{ mult = 0.0f;
	if (mod->dif == 0) {mult = game->playr_stat_mult - (noob_mult * extra_mult);}
	else if (mod->dif == 1) {mult = game->playr_stat_mult - (recruit_mult * extra_mult);}
	else if (mod->dif == 2) {mult = game->playr_stat_mult - (merc_mult * extra_mult);}
	else if (mod->dif == 3) {mult = game->playr_stat_mult - (nomad_mult * extra_mult);}
	else if (mod->dif == 4) {mult = game->playr_stat_mult - (blackdeath_mult * extra_mult);}
	else {mult = game->playr_stat_mult - extra_mult;}
	return mult;
}

float Campaign::I_spawnMultiplier()
{ mult = 0.0f;
	if (mod->dif == 0) {mult = mod->i_mult + (noob_mult * extra_mult);}
	else if (mod->dif == 1) {mult = mod->i_mult + (recruit_mult * extra_mult);}
	else if (mod->dif == 2) {mult = mod->i_mult + (merc_mult * extra_mult);}
	else if (mod->dif == 3) {mult = mod->i_mult + (nomad_mult * extra_mult);}
	else if (mod->dif == 4) {mult = mod->i_mult + (blackdeath_mult * extra_mult);}
	else {mult = mod->i_mult + extra_mult;}
	return mult;
}

float Campaign::I_statMultiplier()
{ mult = 0.0f;
	if (mod->dif == 0) {mult = mod->i_mult - (noob_mult * extra_mult);}
	else if (mod->dif == 1) {mult = mod->i_mult - (recruit_mult * extra_mult);}
	else if (mod->dif == 2) {mult = mod->i_mult - (merc_mult * extra_mult);}
	else if (mod->dif == 3) {mult = mod->i_mult - (nomad_mult * extra_mult);}
	else if (mod->dif == 4) {mult = mod->i_mult - (blackdeath_mult * extra_mult);}
	else {mult = mod->i_mult - extra_mult}
	return mult;
}
