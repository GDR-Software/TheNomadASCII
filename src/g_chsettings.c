#include "n_shared.h"
#include "g_scf.h"
#include "g_keys.h"

bool K_changeName(const char* old_name, const char* new_name)
{
	for (i = 0; i < NUMBINDS; i++) {
		if (kb_binds[i] == *old_name) {
			kb_binds[i] = *new_name;
		}
	}
	return false;
}

bool K_changeBind(keybind_t old_bind, keybind_t new_bind)
{
	for (i = 0; i < NUMBINDS; i++) {
		if (kb_binds[i + 1] == old_bind) {
			for (int x = 0; x < NUMBINDS; x++) {
				if (keybinds[x] == new_bind) {
					kb_binds[i + 1] = new_bind;
					return true;
				}
			}
			return false;
		}
	}
	return false;
}

bool K_changeButton(keybind_t old_key, keybind_t new_key)
{
	for (i = 0; i < NUMBINDS; i++) {
		if (kb_binds[i + 2] == old_key) {
			for (int x = 0; x < NUMKEYS; x++) {
				if (keyarr[x] == new_key) {
					kb_binds[i + 2] = new_key;
					return true;
				}
			}
			return false;
		}
	}
}

bool K_changeAltBind(keybind_t old_alt, keybind_t new_alt)
{
	for (i = 0; i < NUMBINDS; i++) {
		if (kb_binds[i + 3] == old_alt) {
			for (int x = 0; x < NUMBINDS; x++) {
				if (keybinds[x] == new_alt) {
					kb_binds[i + 3] = new_alt;
					return true;
				}
			}
			return false;
		}
	}
	return false;
}

bool K_changeShiftBind(keybind_t old_shift, keybind_t new_shift)
{
	for (i = 0; i < NUMBINDS; i++) {
		if (kb_binds[i + 4] == old_shift) {
			for (int x = 0; x < NUMBINDS; x++) {
				if (keybinds[x] == new_shift) {
					kb_binds[i + 4] = new_shift;
				}
			}
			return false;
		}
	}
	return false;
}