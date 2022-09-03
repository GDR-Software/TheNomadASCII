#include <stdlib.h>
#include <stdio.h>

#include "keycodes.h"
#include "playr.h"
#include "data.h"

int change_keyBinds(int keybind, int new_keycode)
{
	for (int i = 0; i < NUMKEYCODES; i++)
	{
		if (keyBindings[i][0] == keybind)
		{
			keyBindings[i][1] = new_keycode;
		}
	}
	return new_keycode;
}

int get_keyCode(int keybind)
{
	static int keycode;
	for (int i = 0; i < NUMKEYCODES; i++)
	{
		if (keyBindings[i][0] == keybind)
		{
			keycode = keyBindings[i][1];
			return keycode;
		}
	}
}