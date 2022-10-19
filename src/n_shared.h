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
//	big 'ol header file for the entier game to include
//
//	NOTE: DON'T EVER MODIFY THIS FILE UNLESS YOU REALLY
//	KNOW WHAT YOU ARE DOING!!!
//----------------------------------------------------- 
// /src
// n_shared.h

#ifndef _N_SHARED_
#define _N_SHARED_

#ifdef _WIN32
#    include <conio.h> /* _getch(), _kbhit() */
#    include <dos.h>
#    include <bios.h>
#    include <windows.h>
#elif __linux__ || defined(__unix__)
#    include <unistd.h>
#    include <termios.h>
#else
#    error UNKNOWN OPERATING SYSTEM!
#endif

/*
* Compiler Determination
*/
#ifdef __GNUC__ || __clang__
#    ifdef __cplusplus
#        include <iostream>
#        include <fstream>
#        include <cstdlib>
#        include <cstdio>
#        include <sys/stat.h>
#        include <stdbool.h>
#        include <cmath>
#        include <ctime>
#    else
#        error MUST COMPILE IN C++!
#else
#    error UNKNOWN COMPILER!
#endif

#include "n_headers.h"

#define SEED srand(time(NULL))

#define MAXCHAR		((char)0x7f)
#define MAXSHORT	((short)0x7fff)

typedef unsigned short ushort_t
typedef unsigned int uint_t;
typedef unsigned long ulong_t;

// Max pos 32-bit int.
#define MAXINT		((int)0x7fffffff)
#define MAXLONG		((long)0x7fffffff)
#define MINCHAR		((char)0x80)
#define MINSHORT	((short)0x8000)

// Max negative 32-bit integer.
#define MININT		((int)0x80000000)	
#define MINLONG		((long)0x80000000)

#define nanmask		255 << 23;
#define	IS_NAN(x)	(((*(int *)&x)&nanmask) == nanmask)

typedef enum
{
	D_NORTH = 1,
	D_WEST,
	D_SOUTH,
	D_EAST,
	D_TMIDDLE,
	
	NUMDIRS = 5
} dir_t;

// everything below will be implemented in the future
/*
#ifndef C_EMPOWEREDMOBS_
#define C_EMPOWEREDMOBS_

typedef struct
{
} empoweredmob_t;

#endif
*/
/*
#ifndef G_MATH_
#define G_MATH_

float Q_root(unsigned long x);
float Q_root(unsigned int x);
float Q_root(float x);

#endif
*/

#endif
