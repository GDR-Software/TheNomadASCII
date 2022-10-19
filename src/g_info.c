#include "g_keys.h"
#include "g_mob.h"
#include "../n_shared.h"
#include "g_items.h"

// name, bind, button, shiftbind, altbind
// all binds, buttons, etc. are default, will change upon loading a .scf file
// buttons are const, some buttons are NULL because they're an alt binding by default
key_binds_t kb_binds[NUMBINDS] = {
	{K_MOVEN,         kbMove_n,        KEY_W,     NULL,        NULL},
	{K_MOVEW,         kbMove_w,        KEY_A,     NULL,        NULL},
	{K_MOVES,         kbMove_s,        KEY_S,     NULL,        NULL},
	{K_MOVEE,         kbMove_e,        KEY_D,     NULL,        NULL},
	{K_SHOWWPNS,      kbShowWpns,      KEY_TAB,   NULL,        kbShowScore},
	{K_RUN,           kbRun,           KEY_SHIFT, NULL,        kbDash},
	{K_DASH,          kbDash,          NULL,      NULL,        NULL},
	{"RELOAD",                kbReload,        KEY_R,     kbToBestWpn, NULL},
	{"SHOOT",                 kbShoot,         KEY_CTRL,  kbCrouch,    kbSlide},
	{"THROW ORDNANCE",        kbThrowGrenade,  KEY_G,     NULL, },
};

/* BASE STATS
 name, sprite,
 health, speed, painchance, armor,
 snd_area, snd_tol,
 smell_area, smell_toll,
 has melee atk, has hitscan, has projectile
   STATES
 null state
 spawn state
 wander state
 chaseplayr state
 idle state
 engage state
 fight state
 pain state
 infight state
 flee state
 courage state
 dead state
   ATTACKS
 melee name, melee dmg, melee range,
 hitscan name, hitscan dmg, hitscan range
*/

mobj_t mobinfo[NUMMOBS] = {
	{
   "Hulk", 'H',
   254, mobspeed+3, 34, 65,
   
   MS_ZHULK_NULL,
   MS_ZHULK_SPAWN,
   MS_ZHULK_SNIFF, // hulks are blind
   MS_ZHULK_RUNAFTER,
   MS_ZHULK_SAD,
   MS_ZHULK_FUN,
   MS_ZHULK_RAGE,
   MS_ZHULK_INPAIN,
   MS_ZHULK_CONFUSED,
   MS_ZHULK_SCARED,
   MS_ZHULK_EXCITED,
   MS_ZHULK_DEAD
	},
	{
   "Ravager",
   MS_ZRAVAGER_NULL,
   MS_ZRAVAGER_SPAWN,
   MS_ZRAVAGER_ROAM,
   MS_ZRAVAGER_FINDTHEM,
   MS_ZRAVAGER_SCHEMING,
   MS_ZRAVAGER_GETTHEM,
   MS_ZRAVAGER_HANDTOHAND,
   MS_ZRAVAGER_OUCH,
   MS_ZRAVAGER_TRAITORINTHERANKS,
   MS_ZRAVAGER_ABANDONSHIP,
   MS_ZRAVAGER_RALLYTOME,
   MS_ZRAVAGER_FALLEN
	},
	{
   "Grunt",
   MS_ZGRUNT_NULL,
   MS_ZGRUNT_SPAWN,
   MS_ZGRUNT_WANDER,
   MS_ZGRUNT_CHASEPLAYR,
   MS_ZGRUNT_IDLE,
   MS_ZGRUNT_ENGAGE,
   MS_ZGRUNT_FIGHT,
   MS_ZGRUNT_PAIN,
   MS_ZGRUNT_INFIGHT,
   MS_ZGRUNT_RUNFORYOURLIVES,
   MS_ZGRUNT_RALLIED,
   MS_ZGRUNT_DEAD
	},
	{
   "Pistol Guy",
   MS_HPISTOL_NULL,
   MS_HPISTOL_SPAWN,
   MS_HPISTOL_WANDER,
   MS_HPISTOL_CHASEPLAYR,
   MS_HPISTOL_IDLE,
   MS_HPISTOL_ENGAGE,
   MS_HPISTOL_FIGHT,
   MS_HPISTOL_PAIN,
   MS_HPISTOL_INFIGHT,
   MS_HPISTOL_FLEE,
   MS_HPISTOL_COURAGE,
   MS_HPISTOL_DEAD
	},
};

craftable_t craftinfo[NUMCRAFTABLES] = {
	{
   
	},
};

item_t iteminfo[NUMITEMS] = {
	{
   "Backpack LVL. 1",
   
	},
	{
	},
};