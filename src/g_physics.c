#include "n_shared.h"
#include "g_entity.h"
#include "g_mob.h"
#include "c_map.h"
#include "c_campaign.h"
#include "g_playr.h"

map_t* map;

// used for melee and wall collision
int P_closeCollider(playr_t* playr)
{
	short o, a;
	short y, x;
	switch (playr->pdir) {
	case D_NORTH:
		y = -1; x = 0;
		break;
	case D_WEST:
		y = 0; x = -1;
		break;
	case D_SOUTH:
		y = 1; x = 0;
		break;
	case D_EAST:
		y = 0; x = 1;
		break;
	default:
#ifdef DEVMODE
		gameError(UNKNOWN_OR_INVALID_DIR);
#else
		return ET_AIR; // technically this is a built-in bug,
					   // but if it happens, then you'll know something's up
#endif
		break;
	};
	for (i = 0; i < sizeof(map->map_walls); i++) {
		if (map->sector->sector_map[playr->py + y][playr->px + x] == map->map_walls[i]) {
			return ET_WALL;
			// NOTE: may want to add in a feature where it actually hurts to punch a wall
		}
	}
	for (i = 0; i < sizeof(playr->entity->mobsprites); i++) {
		if (map->sector->sector_map[playr->py + y][playr->px + x] == playr->entity->mobsprites[i]) {
			return ET_MOB;
		}
	}
	return ET_AIR; // hit nothing, air
}

int P_rangedCollider(playr_t* playr, short range)
{
	short o, a;
	switch (playr->pdir) {
	case D_NORTH:
		o = playr->py;
		a = -1;
		break;
	case D_WEST:
		o = playr->px;
		a = -1;
		break;
	case D_SOUTH:
		o = playr->py;
		a = 1;
		break;
	case D_EAST:
		o = playr->px;
		a = 1;
		break;
	default:
#ifdef DEVMODE
		gameError(UNKNOWN_OR_INVALID_DIR);
#else
		return ET_AIR;
#endif
		break;
	};
	short z = 0;
	for (i = o; i == range; i += a) {
		if (i == playr->px) {
			for (z < sizeof(map->map_walls); z++) {
				if (map->sector->sector_map[playr->py][i] == map->map_walls[z]) {
					return ET_WALL;
				}
			}
			for (z = 0; z < sizeof(playr->entity->mobsprites); z++) {
				if (map->sector->sector_map[playr->py][i] == playr->entity->mobsprites[z]) {
					return ET_MOB;
				}
			}
		}
		else if (i == playr->py) {
			for (z < sizeof(map->map_walls); z++) {
				if (map->sector->sector_map[i][playr->px] == map->map_walls[z]) {
					return ET_WALL;
				}
			}
			for (z = 0; z < sizeof(playr->entity->mobsprites); z++) {
				if (map->sector->sector_map[i][playr->px] == playr->entity->mobsprites[z]) {
					return ET_MOB;
				}
			}
		}
	}
	return ET_AIR; // never hit anything
}

// slower than calling specific collider funcs, but more efficient
int E_collider(short y, short x, short dir)
{
	short w, d;
	entity_base_t* entity;
	switch (dir) {
	case D_NORTH:
		w = -1; d = 0;
		break;
	case D_WEST:
		w = 0; d = -1;
		break;
	case D_SOUTH:
		w = 1; d = 0;
		break;
	case D_EAST:
		w = 0; d = 1;
		break;
	default:
#ifdef DEVMODE
		gameError(UNKNOWN_OR_INVALID_DIR);
#else
		return ET_AIR
#endif
		break;
	};
	for (i = 0; i < sizeof(map->map_walls); i++) {
		if (map->sector->sector_map[y + w][x + d] == map->map_walls[i]) {
			return ET_WALL;
		}
	}
	for (i = 0; i < sizeof(entity->mobsprites); i++) {
		if (map->sector->sector_map[y + w][x + d] == entity->mobsprites[i]) {
			return ET_MOB;
		}
	}
	if (map->sector->sector_map[y + w][x + d] == '@') {
		return ET_PLAYR;
	}
	return ET_AIR;
}

bool E_wallCollider(short y, short x, short dir)
{
	short w, d;
	switch (dir) {
	case D_NORTH:
		w = -1; d = 0;
		break;
	case D_WEST:
		w = 0; d = -1;
		break;
	case D_SOUTH:
		w = 1; d = 0;
		break;
	case D_EAST:
		w = 0; d = 1;
		break;
	default:
#ifdef DEVMODE
		gameError(UNKNOWN_OR_INVALID_DIR);
#else
		return ET_AIR;
#endif
		break;
	};
	for (i = 0; i < sizeof(map->map_walls); i++) {
		if (map->sector->sector_map[y + w][x + d] == map->map_walls[i]) {
			return true;
		}
	}
	return false;
}

int M_closeCollider(mobj_t* mob, short id)
{
	short o, a;
	short y, x;
	switch (mob->entity->m_ActiveDir[id]) {
	case D_NORTH:
		y = -1; x = 0;
		break;
	case D_WEST:
		y = 0; x = -1;
		break;
	case D_SOUTH:
		y = 1; x = 0;
		break;
	case D_EAST:
		y = 0; x = 1;
		break;
	default:
#ifdef DEVMODE
		gameError(UNKNOWN_OR_INVALID_DIR);
#else
		return ET_AIR;
#endif
		break;
	};
	for (i = 0; i < sizeof(map->map_walls); i++) {
	  if(map->sector->sector_map[mob->entity->m_ActiveY[id]+y][mob->entity->m_ActiveX[id]+x]==map->map_walls[i]){
			return ET_WALL;
			// NOTE: may want to add in a feature where it actually hurts to punch a wall
	  }
	}
	if (map->sector->sector_map[mob->entity->m_ActiveY[id]+y][mob->entity->m_ActiveX[id]+x]=='@') {
		return ET_PLAYR;
	}
	return ET_AIR; // hit nothing, air
}

int M_rangedCollider(mobj_t* mob, short id, short range)
{
	short o, a;
	switch (mob->entity->m_ActiveDir[id]) {
	case D_NORTH:
		o = mob->entity->m_ActiveY[id];
		a = -1;
		break;
	case D_WEST:
		o = mob->entity->m_ActiveX[id];
		a = -1;
		break;
	case D_SOUTH:
		o = mob->entity->m_ActiveY[id];
		a = 1;
		break;
	case D_EAST:
		o = mob->entity->m_ActiveX[id];
		a = 1;
		break;
	default:
#ifdef DEVMODE
		gameError(UNKNOWN_OR_INVALID_DIR);
#else
		return ET_AIR;
#endif
		break;
	};
	short z = 0;
	for (i = o; i == range; i += a) {
		if (i == mob->entity->m_ActiveX[id]) {
			for (z < sizeof(map->map_walls); z++) {
				if (map->sector->sector_map[mob->entity->m_ActiveY[id]][i] == map->map_walls[z]) {
					return ET_WALL;
				}
			}
			if (map->sector->sector_map[mob->entity->m_ActiveY[id]][i] == '@') {
				return ET_PLAYR;
			}
		}
		else if (i == mob->entity->m_ActiveX[id]) {
			for (z < sizeof(map->map_walls); z++) {
				if (map->sector->sector_map[i][mob->entity->m_ActiveX[id]] == map->map_walls[z]) {
					return ET_WALL;
				}
			}
			if (map->sector->sector_map[i][mob->m_ActiveX[id]] == '@') {
				return ET_PLAYR;
			}
		}
		else {
#ifdef DEVMODE
			gameError(VAR_IS_INCORRECT_VALUE);
#else
			return ET_AIR;
#endif
		}
	}
}