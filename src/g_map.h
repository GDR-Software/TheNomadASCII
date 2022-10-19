#ifndef _G_MAP_
#define _G_MAP_

#include "n_shared.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAP_MAX_Y			1080
#define MAP_MAX_X			1080

// 4 sectors per map
#define SECTOR_MAX_Y		270
#define SECTOR_MAX_X		270

#define SECTION_MAX_Y		135
#define SECTION_MAX_X		135

typedef struct
{
	
} map_t;

typedef struct
{
} sector_t;

typedef struct
{
	int snd_map[SECTION_MAX_Y][SECTION_MAX_X];
} section_t;

#ifdef __cplusplus
}
#endif

#endif