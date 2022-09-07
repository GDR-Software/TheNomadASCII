#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#ifdef _WIN32
	#pragma once
#endif

#include <memory>
#include <stdlib.h>

#include "c_campaign.h"
#include "c_mob.h"
#include "c_item.h"
#include "c_playr.h"
#include "nomaddef.h"

namespace Campaign {
	std::unique_ptr<Animation> motion = std::make_unique<Animation>();
	typedef struct
	{
		int S_name; // how to find the shit in the array
		int S_unspawn; // inactive
		int S_spawn; // spawn
		int S_roam; // randomly moving around and/or moving with a legion
		int S_hunt; // hunting for player
		int S_attack1; // melee
		int S_attack2; // hitscan
		int S_attack3; // projectile
		int S_dead;
		int states[NUMMOBSTATES];
	} moba_t; // mob animation states
	
	typedef enum
	{
		P_INACTIVE, // when in menu, loading, or anything other than roam or campaign
		P_DEAD,
		P_SPAWN,
		P_ROAM,
		P_COMBAT,
		P_SHOP,
		NUMPLAYRSTATES
	} playrstate_t;
	
	typedef enum
	{
		Z_SNIFF,
		Z_FLEE,
		Z_FIGHT,
		Z_PAIN,
		Z_RAGE,
		Z_SUPERCHARGE,
		NUMZURSTATES
	} zurstate_t;
	
	typedef enum
	{
		// zurgut hulk
		Z_HULK,
		Z_HULK_INACTIVE,
		Z_HULK_SPAWN,
		Z_HULK_MOVE,
		Z_SNIFF,
		Z_HULK_PUNCH,
		Z_HULK_NULL,
		Z_HULK_RAM,
		Z_HULK_DEAD,
		// zurgut ravager
		Z_RAV,
		Z_RAV_INACTIVE,
		Z_RAV_SPAWN,
		Z_RAV_MOVE,
		Z_RAV_COMMAND, // ravagers are unit leaders in zurgut legions
		Z_RAV_
		
		
		NUMMOBSTATES
	} mobstate_t;
	
	class Animation
	{
	public:
	};
};

#endif
