#ifndef _G_ENTITY_
#define _G_ENTITY_

#include "../n_shared.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_MOBS_ACTIVE			50

typedef int stat_t;

enum
{
	ET_MOB,
	ET_WALL,
	ET_PLAYR,
	ET_AIR
};

typedef struct
{
	const char mobsprites[NUMMOBS] = {
		'H', // hulk
		'R', // ravager
		'Z', // grunt
		'P', // pistol guy
		'G', // heavy gunner guy
		'S', // shotgun guy
		'K', // rocket guy
		'M', // mercenary
		'N' // nomad
	};
	short mob_speed = MOB_SPEED_STD;
	bool playr_killable = false;
	char* m_ActiveNames[MAX_MOBS_ACTIVE];
	char m_ActiveSprite[MAX_MOBS_ACTIVE];
	stat_t m_ActiveHP[MAX_MOBS_ACTIVE];
	stat_t m_ActiveY[MAX_MOBS_ACTIVE];
	stat_t m_ActiveX[MAX_MOBS_ACTIVE];
	stat_t m_ActiveIndex[MAX_MOBS_ACTIVE];
	stat_t m_ActiveDir[MAX_MOBS_ACTIVE];
	stat_t m_ActivePursuitCounter[MAX_MOBS_ACTIVE];
	stat_t m_ActiveState[MAX_MOBS_ACTIVE];
	stat_t m_ActiveType[MAX_MOBS_ACTIVE];
} entity_base_t;

#ifdef __cplusplus
}
#endif

#endif