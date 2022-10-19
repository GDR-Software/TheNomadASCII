#include "n_shared.h"
#include "g_entity.h"
#include "g_mob.h"
#include "c_map.h"
#include "c_campaign.h"
#include "g_playr.h"
#include "g_items.h"

map_t* map;

static bool M_meleeCheck(mobj_t* mob, short id)
{
	short h = M_closeCollider(mob, id)
}

static bool M_hitscanCheck(mobj_t* mob, short id)
{
	if (M_rangedCollider(mob, id,
		mobinfo[mob->entity->m_ActiveIndex[id]+MI_HITSCAN_RANGE] & ET_PLAYR) {
		return true;
	}
	else if (M_rangedCollider(mob, id,
		mobinfo[mob->entity->m_ActiveIndex[id]+MI_HITSCAN_RANGE] & ET_WALL) {
		playSfx("hit_wall");
		return false;
	}
	else if (M_rangedCollider(mob, id,
		mobinfo[mob->entity->m_ActiveIndex[id]+MI_HITSCAN_RANGE] & ET_AIR) {
		return false;
	}
	// TODO: add in mob-on-mob checks for infighting
}

static bool P_meleeCheck(playr_t* playr)
{
	
}