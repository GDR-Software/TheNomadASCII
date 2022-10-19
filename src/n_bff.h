#ifndef _N_BFF_
#define _N_BFF_

#include "n_shared.h"

#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

#define bff_file				25000
#define GS_MAX_SIZE				10000
	// 10kb is max size for a game screen

#define MAX_BFF_NAME_CHARS		30

const char* GS_elementtypes[] = {
	": GS_MAPFIELD",
	": GS_TEXTAREA",
	": GS_MINIMAP",
	": GS_CMDPROMPT",
};

const char* BFF_colors[] = {
	"@ GREEN",
	"@ RED",
	"@ BLUE",
	"@ YELLOW",
	"@ ORANGE",
	"@ BROWN",
	"@ BLACK",
	"@ PURPLE",
	"@ GREY",
	"@ PINK",
};

void I_writeBFF(const char* filename, char* data[1080]);
char** I_readBFF(const char* filename);

typedef struct
{
	char* contents[1080];
} bff_t;

#ifdef __cplusplus
}
#endif

#endif
