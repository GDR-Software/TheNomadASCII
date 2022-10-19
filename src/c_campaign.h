#ifndef _C_CAMPAIGN_
#define _C_CAMPAIGN_

#include "../n_shared.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DIF_NOOB										0
#define DIF_RECRUIT										1
#define DIF_MERCENARY									2
#define DIF_NOMAD										3
#define DIF_BLACKDEATH									4
#define DIF_MINORINCONVENIENCE							5

/*
typedef struct
{

} guild_t;
*/
typedef struct
{
	bool godmode = false;
	bool fastmobs = false;
} soloplayr_t;

#ifdef __cplusplus
}
#endif

#endif