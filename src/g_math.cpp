#include <cmath>
#include <ctime>

#include "g_shared.h"

// almost all functions are given the Q_ in honour of the Q3 fast inverse sqrt

float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5f;
	
	x2 = number * 0.5f;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	return y;
}

float disBetweenOBJ(float y1, float x1, float y2, float x2)
{
	float d = 0.0f;
	if (y1 == y2) { // horizontal
		if (x1 > x2) {
			return d = x1 - x2;
		}
		else if (x1 < x2) {
			return d = x2 - x1;
		}
		else {
			return d;
		}
	}
	else if (x1 == x2) { // vertical
		if (y1 > y2) {
			return d = y1 - y2;
		}
		else if (y1 < y2) {
			return d = y2 - y1;
		}
		else {
			return d;
		}
	}
	else { // diagonal
		float d = pow(pow((x1 - x2), 2) + pow((y1 - y2), 2), 0.5);
	}
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
	float y = pow((a * x), 2) + (b * x) + c;
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
    const float threehalfs = 1.5f;
    
    // trick c/c++, bit hack
    i = *(long *)&r_sqrt;					// yes, I know, undefined behaviour, who gives a fuck?
    i = 0x5f375a86 - (i >> 1);				// weird magic base-16 nums
    r_sqrt = *(float *) &i;
    
    r_sqrt *= (threehalfs - (x_half * r_sqrt * r_sqrt)); // 1st Newton iteration
    r_sqrt *= (threehalfs - (x_half * r_sqrt * r_sqrt)); // 2nd Newton iteration
    
    return x * r_sqrt; // x * (1/sqrt(x)) := sqrt(x)
}