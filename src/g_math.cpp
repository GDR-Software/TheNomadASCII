#include <cmath>
#include <ctime>

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

static float disBetweenOBJ(float y1, float x1, float y2, float x2)
{
	float d;
	if (y1 == y2) // if horizontal
	{
		if (x1 > x2)
		{
			return d = x1 - x2;
		}
		else if (x1 < x2)
		{
			return d = x2 - x1;
		}
		else {
			return d = 0.0f;
		}
	}
	else if (x1 == x2) // if vertical
	{
		if (y1 > y2)
		{
			return d = y1 - y2;
		}
		else if (y1 < y2)
		{
			return d = y2 - y1;
		}
		else {
			return d = 0.0f;
		}
	}
	else { // if diagonal
		float y = (y1 - y2) * y;
		float x = (x1 - x2) * x;
		return d = sqrt((x + y));
	}
}

bool inRange(float y1, float x1, float y2, float x2, int wrng)
{
	if (disBetweenOBJ(y1, x1, y2, x2) <= wrng)
	{
		
	}
}