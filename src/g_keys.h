#ifndef _G_KEYS_
#define _G_KEYS_

#ifdef __cplusplus
extern "C" {
#endif

#include "n_keycodes.h"

typedef int keybind_t;

typedef enum
{
	kbMove_n,
	kbStrafe_l,
	kbStrafe_r,
	kbMove_e,
	kbShowWpns,
	kbRun,
	kbDash,
	kbReload,
	kbShoot,
	kbThrowGrenade,
	kbShowScore,
	kbSaySomething,
	kbInteract,
	kbSlide,
	kbFlashyKill,
	kbSS_left, // transitioning between HUD, inventory, map
	kbSS_right,
	kbTurn_l,
	kbTurn_r,
	kbSwimUp,
	kbSwimDown,
	kbOpenCMD, // opens launcher program
	kbJump,
	kbAimDownSights,
	kbAltADS,
	kbFlashlight,
	kbOpenChat,
	kbOpenConsole,
	
	NUMBINDS
} binds_t;

typedef short kbmod_t;

typedef struct
{
	char* name;
	short bind;
	short button;
	kbmod_t shiftbind;
	kbmod_t altbind;
} key_binds_t;

extern key_binds_t kb_binds[NUMBINDS];

void K_changeName(const char* old_name, const char* new_name);
void K_changeBind(keybind_t old_bind, keybind_t new_bind);
void K_changeButton(keybind_t old_key, keybind_t new_key);
void K_changeAltBind(keybind_t old_alt, keybind_t new_alt);
void K_changeShiftBind(keybind_t old_shift, keybind_t new_shift);

#ifdef __cplusplus
}
#endif

#endif