// Language: C/C++20
//-----------------------------------------------------
// Copyright (C) 2022-2023, GDR Software
//
// This file is part of The Nomad (ASCII) source code,
// and you may only modify, redistribute it under the 
// terms of the SACE License.
//
// This source code is distributed freely with hopes that
// it could be useful/helpful for one of your own projects.
//
// All repos/files using the SACE engine are copyrighted
// by GDR Software.
//
// DESCRIPTION:
//	config file reader
//----------------------------------------------------- 
// /src
// g_scfread.h

#ifndef _G_SCFREAD_
#define _G_SCFREAD_

#include "n_shared.h"

#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

#include "g_keys.h"

const char* kb_scf[NUMBINDS] = {
	": A",
	": B",
	": C",
	": D",
};

// .scf file extension stands for "sace configuration file"

void I_writeSCF(const char* filename, char** data[1080]);
char** I_readSCF(const char* filename);

typedef struct
{
	char controls[];
	short snd_vol;
	short music_vol;
	short fov;
	bool cheats_on;
	
} config_t;

#ifdef __cplusplus
}
#endif

#endif