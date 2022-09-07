#include <stdlib.h>
#include <vector>
#include <iostream>

#include "nomaddef.h"
#include "c_animation.h"

// dead, spawn, roam, hunt, melee, hitscan, projectile
mobstat_t states[NUMSTATES] = {
	{Z_HULK_NULL, Z_HULK_SPAWN, Z_HULK_STUPOR, },
};

sprite_t sprites[NUMSPRITES] = {
	{},
};