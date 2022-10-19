#ifndef _G_MOB_
#define _G_MOB_

#include "n_shared.h"
#include "g_entity.h"

#define MOB_SPEED_STD		1

enum
{
	MS_NULL,
	MS_SPAWN,
	MS_WANDER,
	MS_CHASEPLAYR,
	MS_IDLE,
	MS_ENGAGE,
	MS_FIGHT,
	MS_PAIN,
	MS_INFIGHT,
	MS_FLEE,
	MS_COURAGE,
	MS_DEAD,
	
	NUMBASEMOBSTATES
};

enum
{
	/* Zurguts */
	// Zurgut Hulk
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
	MS_ZHULK_DEAD,
	
	// Zurgut Ravager, these guys are the commanders
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
	MS_ZRAVAGER_FALLEN,
	
	// Zurgut Grunt, the cannon fodder
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
	MS_ZGRUNT_DEAD,
	
	/* Humans */
	// Pistol Guy
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
	MS_HPISTOL_DEAD,
	
	// Heavy Gunner Dude
	MS_HGUNNER_NULL,
	MS_HGUNNER_SPAWN,
	MS_HGUNNER_WANDER,
	MS_HGUNNER_CHASEPLAYR,
	MS_HGUNNER_IDLE,
	MS_HGUNNER_ENGAGE,
	MS_HGUNNER_FIGHT,
	MS_HGUNNER_PAIN,
	MS_HGUNNER_INFIGHT,
	MS_HGUNNER_FLEE,
	MS_HGUNNER_COURAGE,
	MS_HGUNNER_DEAD,
	
	// Shotty Dude
	MS_HSHOTTY_NULL,
	MS_HSHOTTY_SPAWN,
	MS_HSHOTTY_WANDER,
	MS_HSHOTTY_CHASEPLAYR,
	MS_HSHOTTY_IDLE,
	MS_HSHOTTY_ENGAGE,
	MS_HSHOTTY_FIGHT,
	MS_HSHOTTY_PAIN,
	MS_HSHOTTY_INFIGHT,
	MS_HSHOTTY_FLEE,
	MS_HSHOTTY_COURAGE,
	MS_HSHOTTY_DEAD,
	
	// Rocket Launcher Dude
	MS_HROCKET_NULL,
	MS_HROCKET_SPAWN,
	MS_HROCKET_WANDER,
	MS_HROCKET_CHASEPLAYR,
	MS_HROCKET_IDLE,
	MS_HROCKET_ENGAGE,
	MS_HROCKET_FIGHT,
	MS_HROCKET_PAIN,
	MS_HROCKET_INFIGHT,
	MS_HROCKET_FLEE,
	MS_HROCKET_COURAGE,
	MS_HROCKET_DEAD,
	
	// Mercenary
	MS_HMERC_NULL,
	MS_HMERC_SPAWN,
	MS_HMERC_WANDER,
	MS_HMERC_CHASEPLAYR,
	MS_HMERC_IDLE,
	MS_HMERC_ENGAGE,
	MS_HMERC_FIGHT,
	MS_HMERC_PAIN,
	MS_HMERC_INFIGHT,
	MS_HMERC_FLEE,
	MS_HMERC_COURAGE,
	MS_HMERC_DEAD,
	
	// Nomad
	MS_HNOMAD_NULL,
	MS_HNOMAD_SPAWN,
	MS_HNOMAD_WANDER,
	MS_HNOMAD_CHASEPLAYR,
	MS_HNOMAD_IDLE,
	MS_HNOMAD_ENGAGE,
	MS_HNOMAD_FIGHT,
	MS_HNOMAD_PAIN,
	MS_HNOMAD_INFIGHT,
	MS_HNOMAD_FLEE,
	MS_HNOMAD_COURAGE,
	MS_HNOMAD_DEAD,
	
	NUMMOBSTATES
};

// use these when locating a specific mob's state
enum
{
	ZHULK = MS_ZHULK_NULL,
	ZRAVAGER = MS_ZRAVAGER_NULL,
	ZGRUNT = MS_ZGRUNT_NULL,
	
	HPISTOL = MS_HPISTOL_NULL,
	HGUNNER = MS_HGUNNER_NULL,
	HSHOTTY = MS_HSHOTTY_NULL,
	HROCKET = MS_HROCKET_NULL,
	HMERC = MS_HMERC_NULL,
	HNOMAD = MS_HNOMAD_NULL,
	
	NUMMOBS = 9
};

enum
{
	M_NAME,
	M_HP,
	M_SPEED,
	M_PAINCHANCE,
	M_SNDAREA,
	M_SNDTOL,
	M_AC,
	M_SNULL,
	M_SSPAWN,
	M_SWANDER,
	M_SCHASEPLAYR,
	M_SIDLE,
	M_SENGAGE,
	M_SFIGHT,
	M_SPAIN,
	M_SINFIGHT,
	M_SFLEE,
	M_SHIDE,
	M_SCOURAGE,
	M_SDEAD
};

typedef struct
{
	entity_base_t* entity;
	
	const char* name;
	char sprite
	short health;
	short speed;
	short painchance;
	short armor;
	short sound_area; // mob's hearing reach
	short sound_tol; // the lvl of sound the mob'll hear before investigating
	short smell_area;
	short smell_tol;
	
	short s_null;
	short s_spawn;
	short s_wandering;
	short s_chaseplayr; // chasing a random target
	short s_idle;
	short s_engage;
	short s_fight;
	short s_pain;
	short s_infight;
	short s_flee;
	short s_hide;
	short s_courage; // only can happen if there's a commander of the specific unit around
	short s_dead;
	
	short a_melee;
	short a_melee_damage;
	short a_melee_range;
	
	short a_hitscan;
	short a_hitscan_damage;
	short a_hitscan_range;
	
	short a_projectile;
	short a_projectile_damage;
	short a_projectile_range;
} mobj_t;

extern mobj_t mobinfo[NUMMOBS];

void M_AngryAttack1(mobj_t* mob, short id); // slap
void M_AngryAttack2(mobj_t* mob, short id); // clap, aoe
void M_AngryAttack3(mobj_t* mob, short id); // ram
void M_AngryRageMode(mobj_t* mob, short id);
void M_AngryCalmDown(mobj_t* mob, short id);
void M_BossyAttack1(mobj_t* mob, short id); // 
void M_BossyAttack2(mobj_t* mob, short id);
void M_BossyAttack3(mobj_t* mob, short id);


#endif