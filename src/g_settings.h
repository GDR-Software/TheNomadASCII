#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#ifdef _WIN32
	#pragma once
#endif

//#define TEXT_BASED					1
//#define SDL2						2
//#define SFML						3

typedef struct
{
	//float sound_vol = 1.0f;
	//float FOV = 1.25f;
	bool empowered_mobs = false;
} settings_t;
/*
void T_music(void)
{
	
}
*/

settings_t* settings;

void T_empoweredMobs(void)
{
	if (settings->empowered_mobs)
		settings->empowered_mobs = false;
	else
		settings->empowered_mobs = true;
}

#endif