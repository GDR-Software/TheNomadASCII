#include "n_shared.h"
#include "g_mob.h"

void M_killMob(mobj_t* mob, short id)
{
	if (mob->entity->m_ActiveType[id] == MT_BOSS) {
		mob->entity->m_ActiveNames[id] = " ";
		mob->entity->m_ActiveSprite[id] = ' ';
		mob->entity->m_ActiveY[id] = NULL;
		mob->entity->m_ActiveX[id] = NULL;
		mob->entity->m_ActiveType[id] = NULL;
		mob->entity->m_ActiveIndex[id] = NULL;
		mob->entity->m_ActiveState[id] = NULL;
		mob->entity->m_ActiveHP[id] = NULL;
		mob->entity->m_ActiveDir[id] =
		mob->entity->m_ActivePursuitCounter[id]
	}
	else {
		
	}
}

void M_AngryAttack1(mobj_t* mob, short id)
{

}

void M_AngryAttack2(mobj_t* mob, short id)
{

}

void M_AngryAttack3(mobj_t* mob, short id)
{

}

void M_AngryRageMode(mobj_t* mob, short id)
{

}

void M_AngryCalmDown(mobj_t* mob, short id)
{

}

void M_BossyAttack1(mobj_t* mob, short id)