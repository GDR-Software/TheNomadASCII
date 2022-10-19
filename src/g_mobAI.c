#include "g_mob.h"
#include "c_map.h"
#include "n_shared.h"
#include "g_entity.h"

entity_base_t e;

void M_makeMob(mobj_t mob, stat_t y, stat_t x, bool boss)
{
	short* mptr = NULL;
	for (short i = 0; i < NUMMOBS; i++) {
		
	}
	for (short i = 0; i < NUMMOBS; i++) {
		if (e.m_ActiveIndex[i] == NULL) {
			
		}
	}
	if (mptr == NULL) {
		return;
	}
}

static int M_testDir(mobj_t* mob, short id)
{
	map_t map;
	switch (e.m_ActiveDir[id]) { // test the mob's current dir before changing
	case D_NORTH:
		if (map.c_map[e.m_ActiveY[id] - mobinfo[e.m_ActiveIndex[id]+M_SPEED]][e.m_ActiveX[id]] == ' '
		|| '.' || ',' || '_') {
			return e.m_ActiveY[id] -= MOB_SPEED;
		}
		break;
	case D_WEST:
		if (map.c_map[e.m_ActiveY[id]][e.m_ActiveX[id] - mobinfo[e.m_ActiveIndex[id]+M_SPEED]] == ' '
		|| '.' || ',' || '_') {
			return e.m_ActiveX[id] -= MOB_SPEED;
		}
		break;
	case D_SOUTH:
		if (map.c_map[e.m_ActiveY[id] + mobinfo[e.m_ActiveIndex[id]+M_SPEED]][e.m_ActiveX[id]] == ' '
		|| '.' || ',' || '_') {
			return e.m_ActiveY[id] += MOB_SPEED;
		}
		break;
	case D_EAST:
		if (map.c_map[e.m_ActiveY[id]][e.m_ActiveX[id] + mobinfo[e.m_ActiveIndex[id]+M_SPEED]] == ' '
		|| '.' || ',' || '_') {
			return e.m_ActiveX[id] += MOB_SPEED;
		}
		break;
	default:
		gameError(TMIDDLE_ISNT_A_VALID_DIR);
		break;
	};
	
	//
	// if the mob's current dir fails, then test all other dirs
	//
	if (map.c_map[e.m_ActiveY[id] - 1][e.m_ActiveX[id]] == ' ' || '.' || ',' || '_') {
		return D_NORTH;
	}
	else if (map.c_map[e.m_ActiveY[id]][e.m_ActiveX[id] - 1] == ' ' || '.' || ',' || '_') {
		return D_WEST;
	}
	else if (map.c_map[e.m_ActiveY[id] + 1][e.m_ActiveX[id]] == ' ' || '.' || ',' || '_') {
		return D_SOUTH;
	}
	else if (map.c_map[e.m_ActiveY[id]][e.m_ActiveX[id] + 1] == ' ' || '.' || ',' || '_') {
		return D_EAST;
	}
	else {
		return 0;
	}
}

void M_mobLoop(short id)
{
	mobj_t* mob;
	if (e.m_ActiveState[id] == MS_WANDER || MS_IDLE) {
		if (e.m_ActiveState[id] == MS_WANDER) {
			short dir = M_testDir(mob, id);
			if (!dir) {
				e.m_ActiveState = MS_IDLE;
			}
			else {
				switch (dir) {
				case D_NORTH:
					e.m_ActiveY[id] -= MOB_SPEED;
					break;
				case D_WEST:
					e.m_ActiveX[id] -= MOB_SPEED;
					break;
				case D_SOUTH:
					e.m_ActiveY[id] += MOB_SPEED;
					break;
				case D_EAST:
					e.m_ActiveX[id] += MOB_SPEED;
					break;
				default:
					gameError(INVALID_DIR);
					break;
				};
			}
		}
		if (M_checkSnd(mob, id)) {
			e.m_ActivePursuitCounter[id]++;
		}
		else {
			e.m_ActivePursuitCounter[id]--;
		}
		if (M_checkSight(mob, id)) {
			e.m_ActivePursuitCounter[id]++;
		}
		else {
			e.m_ActivePursuitCounter[id]--;
		}
		if (M_checkSmell(mob, id)) {
			e.m_ActivePursuitCounter[id]++;
		}
		else {
			e.m_ActivePursuitCounter[id]--;
		}
		if (!e.m_ActiveTakenDamage[id]) {
			e.m_ActiveState = MS_IDLE;
		}
		else {
			switch (e.m_ActiveTakenDamage[id]) {
			case MD_PLAYR:
				e.m_ActiveState[id] = MS_ENGAGE;
				break;
			case MD_MOB:
				e.m_ActiveState[id] = MS_INFIGHT;
				break;
			case MD_ENVIRONMENT:
				e.m_ActiveState[id] = MS_CHASEPLAYR;
				break;
			default:
				gameError(MOB_TAKEN_DMG_WITHOUT_SOURCE);
				break;
			};
		}
		if (e.m_ActivePursuitCounter[id] >= mobinfo[e.m_ActiveIndex[id] + M_PC]) {
			e.m_ActiveState[id] = MS_CHASEPLAYR;
		}
		else {
			game_t rng;
			if (getRNG(&rng) > 70) {
				e.m_ActiveState[id] = MS_WANDER;
			}
			else {
				e.m_ActiveState[id] = MS_IDLE;
			}
		}
	}
	else if (e.m_ActiveState[id] == MS_CHASEPLAYR) {
		short c = 0;
		bool hear = false, see = false, smell = false;
		if (M_checkSight(mob, id)) {
			c++
			see = true;
		}
		else {
			c--;
		}
		if (c) {
			e.m_ActiveState[id] = MS_ENGAGE;
		}
		else if (c == -1) {
			if (M_checkSmell(mob, id)) {
				smell = true;
			}
			if (M_checkSnd(mob, id)) {
				hear = true;
			}
			if (!hear && !smell) {
				e.m_ActiveState[id] = MS_IDLE;
			}
			else if ((!hear && smell) || (!smell && hear)) {
				game_t rng;
				if (getRNG(&rng) > 70) {
					e.m_ActiveState[id] = MS_WANDER;
				}
				else {
					e.m_ActiveState[id] = MS_IDLE;
				}
			}
			else if (hear && smell) {
				e.m_ActiveState[id] = MS_CHASEPLAYR;
			}
		}
		if (e.m_ActiveState[id] == MS_CHASEPLAYR) { // checking if current state is still chaseplayr
			playr_t p;
			if (hear && smell && !see) {
				short dir = M_testDir(mob, id);
				if (!dir) {
					e.m_ActiveState = MS_IDLE;
				}
				else {
					// TODO: write algorithm that locates where the mob smells && hears the player from
				}
			}
			else if (smell && see && hear) {
				// TODO: write algorithm that has mob chasing player
			}
		}
	}
	else if (e.m_ActiveState[id] == MS_ENGAGE) {
		if (M_playrInRange(mob, id)) { // mobs can't really attack npc's for now, but it'll change
			e.m_ActiveState[id] = MS_FIGHT;
		}
		else {
			e.m_ActiveState[id] = MS_CHASEPLAYR;
		}
	}
	else if (e.m_ActiveState[id] == MS_FIGHT) {
		
	}
	else if (e.m_ActiveState[id] == MS_INFIGHT) {
	
	}
	
	if (e.m_ActiveHP[id] < 1) {
		M_mobKill(mob, id);
	}
}

static bool M_checkSmell(mobj_t* mob, short id)
{
	section_t s;
	for (short y = 0; y < mobinfo[e.m_ActiveIndex[id] + M_MAXSMELL_AREA]; y++) {
		for (short x = 0; x < mobinfo[e.m_ActiveIndex[id] + M_MAXSMELL_AREA]; x++) {
			if (s.smell_map[e.m_ActiveY[id]+y][e.m_ActiveX[id]+x] >= mobinfo[e.m_ActiveIndex[id]+M_SMELLTOL]) {
				return true;
			}
		}
	}
	return false;
}

static bool M_checkSight(mobj_t* mob, short id)
{
	map_t map;
	switch (e.m_ActiveDir[id]) {
	case D_NORTH:
		for (short y = 0; y < mobinfo[e.m_ActiveIndex[id] + M_MAXSIGHT]; y++) {
			if (map.c_map[e.m_ActiveY[id] - y][e.m_ActiveX[id]] == '@') {
				return true;
			}
		}
		return false;
		break;
	case D_WEST:
		for (short x = 0; x < mobinfo[e.m_ActiveIndex[id] + M_MAXSIGHT]; x++) {
			if (map.c_map[e.m_ActiveY[id]][e.m_ActiveX[id] - x] == '@') {
				return true;
			}
		}
		return false;
		break;
	case D_SOUTH:
		for (short y = 0; y < mobinfo[e.m_ActiveIndex[id] + M_MAXSIGHT]; y++) {
			if (map.c_map[e.m_ActiveY[id] + y][e.m_ActiveX[id]] == '@') {
				return true;
			}
		}
		return false;
		break;
	case D_EAST:
		for (short x = 0; x < mobinfo[e.m_ActiveIndex[id] + M_MAXSIGHT]; x++) {
			if (map.c_map[e.m_ActiveY[id]][e.m_ActiveX[id] + x] == '@') {
				return true;
			}
		}
		return false;
		break;
	default:
		gameError(NOT_VALID_DIR);
		break;
	};
}

static bool M_checkSnd(mobj_t* mob, short id)
{
	section_t snd;
	// scans first from top-left-hand-corner to the bottom-right-hand-corner for sound
	for (short y = 0; y < mobinfo[e.m_ActiveIndex[id] + M_MAXSND_AREA]; y++) {
		for (short x = 0; x < mobinfo[e.m_ActiveIndex[id] + M_MAXSND_AREA]; x++) {
			if(snd.snd_map[e.m_ActiveY[id]+y][e.m_ActiveX[id]+x] >= mobinfo[e.m_ActiveIndex[id]+M_SNDTOL]) {
			    return true;
  			}
		}
	}
	return false;
}