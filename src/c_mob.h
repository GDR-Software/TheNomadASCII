#ifndef _MOB_H_
#define _MOB_H_

#ifdef WINDOWS_FOR_PUSSIES
	#pragma once
#endif

// maximum allowed monsters to spawn on a single thread
#define MAX_MOBS_SPAWN				100

// maximum allowed active monsters within a player-active map
#define MAX_MOBS_ALIVE				150


#include <memory>
#include <vector>

#include "nomaddef.h"

namespace Campaign {
	using Monster = uint16_t;
	enum : Monster
	{
		// zurguts
		z_Brute,
		z_Hulk,
		z_Ravager,
		z_MadMocker,
		
		// gursgo legion
		gl_Elite,
		gl_Grunt,
		
		// kingdom of sortior
		kos_Soldier,
		kos_HeavyShielder,
		
		// eternal city of galakas 
		ecg_,
		
		// latan
		l_blacksmith,
		
		
		NUMMOBS
	};

	class Mob
	{
	private:
		std::vector<std::string> m_ActiveNames;
		std::vector<int> m_ActiveType;
		std::vector<float> m_ActiveHP;
		std::vector<float> m_ActiveY;
		std::vector<float> m_ActiveX;
		std::vector<char> m_ActiveSprite;
		std::vector<char> m_ActiveDir;
		std::vector<int> m_ActiveMap;
	public:
		int mob_id[NUMMOBS] = {};
		int mID{}; // this is the variable that is used to locate a temp mob's stats in the vectors, then remove the stats
		std::vector<int> m_ActiveID;
	public:
		std::unique_ptr<Item> mobGear = std::make_unique<Item>();
		std::unique_ptr<Playr> dmg = std::make_unique<Playr>();
		std::unique_ptr<Game> mod = std::make_unique<Game>();
		std::unique_ptr<SoloPlayer> add = std::make_unique<SoloPlayer>();
	};
};

#endif