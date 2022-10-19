#include "../n_shared.h"
#include "../n_debug.h"

#include "c_campaign.h"
#include "g_rng.h"

const unsigned short RNG[256] = {
	  0,   24, 87,   1, 54, 98,  4, 14,  88,  42, 10, 59,
	 17,  167, 62,  89, 53, 27, 13, 34,  21,  74,  3, 92,
	 40,   12, 98,  45, 37, 12, 80, 14,  36, 249, 19, 71,
	212,  164,  8, 190,
};

unsigned int randint(void)
{
	SEED;
	unsigned int i = rand() % 0xff;
	return SCRAMBLE(i);
}

uint32_t rnd_index = 0;

int P_random(void) // for true rng
{
	rnd_index=(rnd_index+1)&0xff;
	return RNG[rnd_index];
}

int getRNG(game_t* dif) // for difficulty-based rng
{
	SEED;
	uint32_t r = rand() % 0xff;
	switch (dif->gamedifficulty) {
	case DIF_NOOB:
		return (RNG[r] & 50) + 5;
		break;
	case DIF_RECRUIT:
		return (RNG[r] & 100) + 10;
		break;
	case DIF_MERCENARY:
		return (RNG[r] & 200) + 25;
		break;
	case DIF_NOMAD:
		return RNG[r] + 25;
		break;
	case DIF_BLACKDEATH:
		return (RNG[r] & 290) + 50;
		break;
	case DIF_MINORINCONVENIENCE:
		return (RNG[r] & 310) + 75; // why would you even play on this mode?
		break;
#ifdef _N_DEBUG_
	default:
		gameError(INVALID_DIFFICULTY);
		break;
#endif
	};
}