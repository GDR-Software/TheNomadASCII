#include "n_shared.h"
#include "g_playr.h"
#include "g_entity.h"

void P_WaterDrain(playr_t* playr)
{
	playr->water--;
	if (playr->water < 25) {
		playr->health -= 1;
		playSfx("low_water");
	}
}

void P_FoodDrain(playr_t* playr)
{
	playr->food--;
	if (playr->food < 25) {
		playr->health -= 1;
		playSfx("low_food");
	}
}