#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#ifdef _WIN32
	#pragma once
#endif

class Settings
{
public:
	using keyBind = uint32_t;
	
	enum : keyBind
	{
		keyEscape,
		keyJump,
		keyShoot,
		keyMove_n,
		keyMove_w,
		keyMove_s,
		keyMove_e,
		keyAxis_l,
		keyAxis_r,
		keyShowWpns,
		keyFlashlight,
		keyMelee,
		keyThrowGrenade,
		keyCrouch,
		keyInteract,
		
		NUMKEYCODES
	};

	int keyBindings[NUMKEYCODES][2] =
	{
		{
		keyEscape,
		KEY_ESC
		},
		{
		keyJump,
		KEY_SPACE
		},
		{
		keyShoot,
		KEY_CTRL
		},
		{
		keyMove_n,
		KEY_W
		},
		{
		keyMove_w,
		KEY_A
		},
		{
		keyMove_s,
		KEY_S
		},
		{
		keyMove_e,
		KEY_D
		},
		{
		keyAxis_l,
		ARROW_LEFT
		},
		{
		keyAxis_r,
		ARROW_RIGHT
		},
		{
		keyShowWpns,
		KEY_TAB
		},
		{
		keyFlashlight,
		KEY_Q
		},
		{
		keyMelee,
		KEY_F
		},
		/*{
		keyRun,
		KEY_SHIFT
		},*/
		{
		keyThrowGrenade,
		KEY_G
		},
		{
		keyCrouch,
		KEY_C
		},
		{
		keyInteract,
		KEY_E
		},
	};
public:
	float sensitivity = 0.75f;
	// float gamma = 1.0f; // currently a maybe
	float sound_volume = 1.5f;
	float FOV = 7.75f; // how many exact pints a player can see in the dark ahead of them
public:
	int change_keyBinds(int keybind, int new_keycode);
	int get_keyCode(int keybind);
};

#endif