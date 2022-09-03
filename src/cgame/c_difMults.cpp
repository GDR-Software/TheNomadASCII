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
	Multipliers Determined Based On Campaign Difficulty
##########################################################################
*/
// dif_mults.cpp

#include <cmath>
#include <ctime>
#include <memory>

#include "campaign.h"
#include "nomaddef.h"

game = std::make_unique<Game>();
mob = std::make_unique<Mob>();
playr = std::make_unique<Playr>();

float mult = 0.0f;

float Campaign::M_spawnMultiplier()
{
	if (game->dif == 0) {mult = mob->spawnMult * (noob_mult + extra_mult);}
	else if (game->dif == 1) {mult = mob->spawnMult * (recruit_mult + extra_mult);}
	else if (game->dif == 2) {mult = mob->spawnMult * (merc_mult + extra_mult);}
	else if (game->dif == 3) {mult = mob->spawnMult * (nomad_mult + extra_mult);}
	else if (game->dif == 4) {mult = mob->spawnMult * (blackdeath_mult + extra_mult);}
	else {mult = num->spawnMult + extra_mult;} // kinda sorta undefined behaviour, leaves room for mods
	return mult;
}

float Campaign::M_statMultiplier()
{
	if (game->dif == 0) {mult = mob->statMult * (noob_mult + extra_mult);}
	else if (game->dif == 1) {mult = mob->statMult * (recruit_mult + extra_mult);}
	else if (game->dif == 2) {mult = mob->statMult * (merc_mult + extra_mult);}
	else if (game->dif == 3) {mult = mob->statMult * (nomad_mult + extra_mult);}
	else if (game->dif == 4) {mult = mob->statMult * (blackdeath_mult + extra_mult);}
	else {mult = mob->spawnMult + extra_mult;} // kinda sorta undefined behaviour, leaves room for mods
	return mult;
}

float Campaign::P_statMultiplier()
{
	if (game->dif == 0) {mult = playr->playr_stat_mult - (noob_mult * extra_mult);}
	else if (game->dif == 1) {mult = playr->playr_stat_mult - (recruit_mult * extra_mult);}
	else if (game->dif == 2) {mult = playr->playr_stat_mult - (merc_mult * extra_mult);}
	else if (game->dif == 3) {mult = playr->playr_stat_mult - (nomad_mult * extra_mult);}
	else if (game->dif == 4) {mult = playr->playr_stat_mult - (blackdeath_mult * extra_mult);}
	else {mult = playr->playr_stat_mult - extra_mult;}
	return mult;
}

float Campaign::I_spawnMultiplier()
{
	if (game->dif == 0) {mult = game->i_mult + (noob_mult * extra_mult);}
	else if (game->dif == 1) {mult = game->i_mult + (recruit_mult * extra_mult);}
	else if (game->dif == 2) {mult = game->i_mult + (merc_mult * extra_mult);}
	else if (game->dif == 3) {mult = game->i_mult + (nomad_mult * extra_mult);}
	else if (game->dif == 4) {mult = game->i_mult + (blackdeath_mult * extra_mult);}
	else {mult = game->i_mult + extra_mult;}
	return mult;
}

float Campaign::I_statMultiplier()
{
	if (game->dif == 0) {mult = game->i_mult - (noob_mult * extra_mult);}
	else if (game->dif == 1) {mult = game->i_mult - (recruit_mult * extra_mult);}
	else if (game->dif == 2) {mult = game->i_mult - (merc_mult * extra_mult);}
	else if (game->dif == 3) {mult = game->i_mult - (nomad_mult * extra_mult);}
	else if (game->dif == 4) {mult = game->i_mult - (blackdeath_mult * extra_mult);}
	else {mult = game->i_mult - extra_mult}
	return mult;
}

float Campaign::G_Multiplier()
{
	if (game->dif == 0) {mult =}
}