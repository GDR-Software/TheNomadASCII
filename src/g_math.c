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
//	random math functions that operate all around the
//	game
//----------------------------------------------------- 
// /src
// g_math.c

#include <math.h>

#include "n_shared.h"

float disBetweenOBJ(float y1, float x1, float y2, float x2)
{
	if (y1 == y2) { // horizontal
		if (x1 > x2) {
			return x1 - x2;
		}
		else if (x1 < x2) {
			return x2 - x1;
		}
		else {
			return 0.0f;
		}
	}
	else if (x1 == x2) { // vertical
		if (y1 > y2) {
			return y1 - y2;
		}
		else if (y1 < y2) {
			return y2 - y1;
		}
		else {
			return 0.0f;
		}
	else { // diagonal
		//return d = pow(pow((x1 - x2), 2) - pow((y1 - y2), 2), 0.5);
		return Q_pythagoris(x1, x2, y1, y2);
	}
}

float Q_pythagoris(float x1, float x2, float y1, float y2)
{
	return Q_root((SQUARE((x1-x2))+SQUARE((y1-y2))));
}

float Q_quadForm(float a, float b, float c)
{
	float x = (b * b) - (4 * a * c);
	float b2 = b * -1;
	float r1 = (b2 + Q_root(x)) / (2 * a);
	float r2 = (b2 - Q_root(x)) / (2 * a);
	return r1 >= r2 ? r1 : r2;
}

float Q_parabola(float a, float b, float c)
{
	float x = (b * -1) / 2 * a;
	float y = (a * (SQUARE(x))) + (b * x) + c;
	float arr[2] = {x, y};
	return arr;
}

// inspired heavly from Q3 Fast Inverse Square Root algorithm
// quick square root, because normal sqrts are too slow for me
float Q_root(float x)
{
	long     i;								// The integer interpretation of x
	float    x_half = x * 0.5f;
	float    r_sqrt = x;

	// trick c/c++, bit hack
	i = *(long *)&r_sqrt;					// yes, I know, undefined behaviour, who gives a fuck?
	i = 0x5f375a86 - (i >> 1);				// weird magic base-16 nums
	r_sqrt = *(float *) &i;

	r_sqrt = r_sqrt * (threehalfs - (x_half * r_sqrt * r_sqrt)); // 1st Newton iteration
	r_sqrt = r_sqrt * (threehalfs - (x_half * r_sqrt * r_sqrt)); // 2nd Newton iteration

	return x * r_sqrt; // x * (1/sqrt(x)) := sqrt(x)
}

float Q_root(unsigned long x)
{
	long     i;
	float    x_half = x * 0.5f;
	float    r_sqrt = x;

	// trick c/c++, bit hack
	i = *(long *)&r_sqrt;					// yes, I know, undefined behaviour, who gives a fuck?
	i = 0x5f375a86 - (i >> 1);				// weird magic base-16 nums
	r_sqrt = *(float *) &i;

	r_sqrt = r_sqrt * (threehalfs - (x_half * r_sqrt * r_sqrt)); // 1st Newton iteration
	r_sqrt = r_sqrt * (threehalfs - (x_half * r_sqrt * r_sqrt)); // 2nd Newton iteration

	return x * r_sqrt; // x * (1/sqrt(x)) := sqrt(x)
}

float Q_root(unsigned int x)
{
	long     i;								// The integer interpretation of x
	float    x_half = x * 0.5f;
	float    r_sqrt = x;

	// trick c/c++, bit hack
	i = *(long *)&r_sqrt;					// yes, I know, undefined behaviour, who gives a fuck?
	i = 0x5f375a86 - (i >> 1);				// weird magic base-16 nums
	r_sqrt = *(float *) &i;

	r_sqrt = r_sqrt * (threehalfs - (x_half * r_sqrt * r_sqrt)); // 1st Newton iteration
	r_sqrt = r_sqrt * (threehalfs - (x_half * r_sqrt * r_sqrt)); // 2nd Newton iteration

	return x * r_sqrt; // x * (1/sqrt(x)) := sqrt(x)
}