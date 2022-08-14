#ifndef _NOMADDEF_H_
#define _NOMADDEF_H_

// standard ranges, doesn't apply to everything
#define RNG_CLOSE			10
#define RNG_MID				30
#define RNG_LONG				45
#define RNG_ULTRA			60

#define WMAP_NORTHWEST		1
#define WMAP_MIDWEST		2
#define WMAP_SOUTHWEST		3
#define WMAP_MIDSOUTH		4
#define WMAP_SOUTHEAST		5
#define WMAP_MIDEAST		6
#define WMAP_NORTHEAST		7
#define WMAP_MIDNORTH		8
#define WMAP_MIDDLE			9

// multipliers for the game, stuff like mob spawns, hp, and also dividers for ammo spawns and buffs
// the regular, easiest, and most kid-friendly difficulty
#define DIF_NOOB				0
// some teen content, more mature, harder
#define DIF_RECRUIT			1
// call of duty kind of content, as difficult as doom eternal
#define DIF_MERCENARY		2
// most dark content from the book is cut, but the difficulty is matched with the book
#define DIF_NOMAD			3
// everything bad *cancer, basically dark souls difficulty. No story cuts, hardest fucking thing ever, a scary mode.
#define DIF_BLACKDEATH		4

// stationary nomadic tribe
#define NOMAD_TRIBE_S		'%'
// wandering nomadic tribe
#define NOMAD_TRIBE_W		'*'

#define MOUNTAIN				'∆'
#define HILL					'^'
#define MINERAL_DEPO		'π'
#define TEMPLE				'Ω'

typedef enum
{
	noob = 1.3, // can ya shoot straight lad? or are ya fuckin' blind?
	recruit = 3.7, // baby steps
	mercenary = 6.19, // medium shit
	nomad = 10.5, // game's pretty hard
	blackdeath = 20.12, // they're asking for it
} defaultmults_t;

#endif