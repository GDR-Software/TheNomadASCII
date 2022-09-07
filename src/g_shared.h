// this file simply contains all the random functions

#ifndef _SHARED_H_
#define _SHARED_H_

#ifdef _WIN32
	#pragma once
#endif

#ifndef _G_MATH
#define _G_MATH

float Q_rsqrt(float number);
float distanceBetweenOBJ(float x1, float y1, float x2, float y2);
float Q_quadForm(float a, float b, float c);
float Q_parabola(float a, float b, float c);
float Q_root(float x);
float Q_bulletDrop(int rng, int ptype); // this function operates on a different thread entirely
float Q_ordrng(int rng, int fuse); // also operates on a separate thread just for this function

#endif

#endif