#ifndef _N_HEADERS_
#define _N_HEADERS_

#ifdef NOMADMAIN
#    include "g_game.h"
#    include "c_campaign.h"
#    include "g_mob.h"
#    include "g_playr.h"
#    include "g_items.h"
#    include "g_entity.h"
#    include "g_scf.h"
#    include "g_keys.h"
#    include "nstrings.h"
#elif MAPMAKER
#    include "m_main.h"
#    include "m_keys.h"
#endif

#ifdef NDEBUG || defined(NTESTBUILD && NOMADMAIN)
#    include "n_debug.h"
#endif

#include "n_keycodes.h"
#include "n_bff.h"

#endif
