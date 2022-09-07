//
// sry in advance, most of this stuff is hardcoded. Mostly cause I need to find an algorithm to do it better.
// Pls have patience
//

#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <math.h>
#include <vector>

#include "g_shared.h"
#include "nomaddef.h"
#include "c_animation.h"
#include "c_playr.h"
#include "c_mob.h"
#include "c_item.h"
#include "c_mapdef.h"
#include "g_rng.h"
#include "g_sounds.h"

using namespace Campaign;
using namespace std::chrono_literals;

void Sounds::playSfx(const std::string sound)
{
#ifdef _WIN32
	sfx(sound);
#else
	playSound(sound);
}

bool hitCheckMelee(char dir, char target, int z, int x)
{
	if (dir == 'w') {
		if (maps->map_active[z - 1][x] == target) {
			return true; 
		} else if (maps->map_active[z - 1][x] == '|' || maps->map_active[z - 1][x] == '#'
				|| maps->map_active[z - 1][x] == '\' || maps->map_active[z - 1][x] == '/'
				|| maps->map_active[z - 1][x] == '+' || maps->map_active[z - 1][x] == '-'
				|| maps->map_active[z - 1][x] == '=') {
			playSfx("miss_melee");
			return false;
		}
	} else if (dir == 'a') {
		if (maps->map_active[z][x - 1] == target) {
			return true; 
		} else if (maps->map_active[z][x - 1] == '|' || maps->map_active[z][x - 1] == '#'
				|| maps->map_active[z][x - 1] == '\' || maps->map_active[z][x - 1] == '/'
				|| maps->map_active[z][x - 1] == '+' || maps->map_active[z][x - 1] == '-'
				|| maps->map_active[z][x - 1] == '=') {
			playSfx("miss_melee");
			return false;
		}
	} else if (dir == 's') {
		if (maps->map_active[z + 1][x] == target) {
			return true; 
		} else if (maps->map_active[z + 1][x] == '|' || maps->map_active[z + 1][x] == '#'
				|| maps->map_active[z + 1][x] == '\' || maps->map_active[z + 1][x] == '/'
				|| maps->map_active[z + 1][x] == '+' || maps->map_active[z + 1][x] == '-'
				|| maps->map_active[z + 1][x] == '=') {
			playSfx("miss_melee");
			return false;
		}
	} else if (dir == 'd') {
		if (maps->map_active[z][x + 1] == target) {
			return true; 
		} else if (maps->map_active[z][x + 1] == '|' || maps->map_active[z][x + 1] == '#'
				|| maps->map_active[z][x + 1] == '\' || maps->map_active[z][x + 1] == '/'
				|| maps->map_active[z][x + 1] == '+' || maps->map_active[z][x + 1] == '-'
				|| maps->map_active[z][x + 1] == '=') {
			playSfx("miss_melee");
			return false;
		}
	}
}

bool hitMobCheck(char dir, int z, int x, int wrng)
{
	std::vector<char> t_arr;
	size_t i = 0;
	if (dir == 'w') {
		for (i = z; i == (wrng / -1); i--) {
			t_arr.push_back(maps->map_active[i][x]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == ) {// TODO: List all mob sprites here
				return true;
			}
		}
	} else if (dir == 'a') {
		for (i = x; i == (wrng / -1); i--) {
			t_arr.push_back(maps->map_active[z][i]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == ) {// TODO: List all mob sprites here
				return true;
			}
		}
	} else if (dir == 's') {
		for (i = z; i == wrng; i++) {
			t_arr.push_back(maps->map_active[i][x]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == ) {// TODO: List all mob sprites here
				return true;
			}
		}
	} else if (dir == 'd') {
		for (i = x; i == wrng; i++) {
			t_arr.push_back(maps->map_active[z][i]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == ) {// TODO: List all mob sprites here
				return true;
			}
		}
	}
}

bool hitProjectileCheck(char dir, int z, int x, int wrng, int speed)
{
	
	if (dir == 'w') {
	
	} else if (dir == 'a') {
	
	} else if (dir == 's') {
	
	} else if (dir == 'd') {
	
	}
}

// hit scan
bool hitScanCheck(char dir, char target, int z, int x, int wrng)
{
	std::vector<char> t_arr;
	size_t i = 0;
	if (dir == 'w') {
		for (i = z; i == (wrng / -1); i--) {
			t_arr.push_back(maps->map_active[i][x]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == target) {
				return true;
			} else if (t_arr[i] == '#' || t_arr[i] == '|' || t_arr[i] == '\' || t_arr[i] == '/'
					|| t_arr[i] == '-' || t_arr[i] == '+' || t_arr[i] == '=') {
				return false;
			}
		}
	} else if (dir == 'a') {
		for (i = x; i == (wrng / -1); i--) { // bit-shift right? dividing shorthand...?
			t_arr.push_back(maps->map_active[z][i]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == target) {
				return true;
			} else if (t_arr[i] == '#' || t_arr[i] == '|' || t_arr[i] == '\' || t_arr[i] == '/'
					|| t_arr[i] == '-' || t_arr[i] == '+' || t_arr[i] == '=') {
				return false;
			}
		}
	} else if (dir == 's') {
		for (i = z; i == wrng; i++) {
			t_arr.push_back(maps->map_active[i][x]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == target) {
				return true;
			} else if (t_arr[i] == '#' || t_arr[i] == '|' || t_arr[i] == '\' || t_arr[i] == '/'
					|| t_arr[i] == '-' || t_arr[i] == '+' || t_arr[i] == '=') {
				return false;
			}
		}
	} else if (dir == 'd') {
		for (i = x; i == wrng; i++) {
			t_arr.push_back(maps->map_active[z][i]);
		} for (i = 0; i < wrng; i++) {
			if (t_arr[i] == target) {
				return true;
			} else if (t_arr[i] == '#' || t_arr[i] == '|' || t_arr[i] == '\' || t_arr[i] == '/'
					|| t_arr[i] == '-' || t_arr[i] == '+' || t_arr[i] == '=') {
				return false;
			}
		}
	}
}

//==================================================
// mob attacks/combat moves

int mdmg{};
int mrng{};

//
// zurgut hulk attacks
//

// hulk rush and slam
void Mob::A_zhulkRam(int id)
{
	float charge_speed = mob_speed[z_Hulk];
	if (mod->dif > 3)
	{
		charge_speed += add->M_statMultiplier();
	}
	// launch projectile
	if (dir == 'w') {
		float i = m_ActiveZ[id];
		while (i != (m_ActiveZ[id] - charge_speed))
		{
			std::this_thread::sleep_for(400ms);
			maps->map_active[m_ActiveZ
		};
	}
}

// hulk normal punch, may implement a "rage" var to increase damage and attack speed
void Mob::A_zhulkPunch(int id)
{
	mdmg = mob_dmg[z_Hulk];
	if (mod->dif > 3)
	{
		mdmg += (int)add->M_statMultiplier();
	}
	if (!hitMeleeCheck(m_ActiveDir[id], '@', (int)m_ActiveZ[id], (int)m_ActiveX[id]))
	{
		if (hitMobCheck(m_ActiveDir[id], (int)m_ActiveZ[id], (int)m_ActiveX[id], 1))
		{
			std::thread (motion->)
		}
	}
}

//
// mob infighting
// "did you just fucking hit me?", "oh no you didn't...."
void Mob::A_infight(int id1, int id2)
{
}