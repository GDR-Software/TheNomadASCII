#include "c_campaign.h"
#include "c_mob.h"

using namespace Campaign;

int Mob::mobMakeID(const std::string& mobName, int index)
{
	int numMob = 0;
	// gets the # of specific mob in the vector
	for (size_t size = 0; size < m_ActiveNames.size(); size++)
	{
		if (m_ActiveNames[size] == mobName)
		{
			numMob++;
		}
	}
	// makes the id
	return mID = mob_id[index] + (numMob + 1);
}

void Mob::spawnMob(const std::string& mobName, const int mapID)
{
	for (size_t i = 0; i < mob_ls.size(); i++)
	{
		if (mob_ls[i] == mName)
		{
			m_ActiveNames.push_back(mName);
			m_ActiveHP.push_back(mob_hp[i]);
			m_ActiveSprite.push_back(mob_char[i]);
			m_ActiveID.push_back(mobMakeID(mobName, i));
		}
	}
	// TODO: write spawn x & y for mobs
}

// triggers whenever a mob dies
void Mob::killMob(const int id)
{
	maps = std::make_unique<SoloPlayer>();
	playr = std::make_unique<Playr>();
	for (size_t i = 0; i < m_ActiveID.size(); i++)
	{
		if (m_ActiveID[i] == id)
		{
			// hardcoded until I can write a better algorithm
			switch (playr->map_active) {
			case WMAP_NORTHEAST: maps->map_ne[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
								 break;
			case WMAP_NORTHWEST: maps->map_nw[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
								 break;
			case WMAP_SOUTHEAST: maps->map_se[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
								 break;
			case WMAP_SOUTHWEST: maps->map_sw[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
								 break;
			case WMAP_MIDWEST: maps->map_mw[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
							   break;
			case WMAP_MIDEAST: maps->map_me[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
							   break;
			case WMAP_MIDNORTH: maps->map_mn[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
								break;
			case WMAP_MIDSOUTH: maps->map_ms[m_ActiveY[i]][m_ActiveX[i]] = maps->refresh_map(playr->map_active, 																										m_ActiveID[i]);
								break;
			};
		}
		m_ActiveNames.erase(i);
		m_ActiveHP.erase(i);
		m_ActiveSprite.erase(i);
		m_ActiveY.erase(i);
		m_ActiveX.erase(i);
		m_ActiveID.erase(i);
	}
}
