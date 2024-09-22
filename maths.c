#include "project.h"
/**
 * shorter - returns the coordinates of the
 * @h: coordinates of the horizontal intersection
 * @v: coordinates of the vertical intersection
 * Return: returns coordinates of the shorter point
 */
double *shorter(double *h, double *v)
{
	float dh = sqrt(pow(h[0] - posx, 2) + pow(h[1] - posy, 2));
	float dv = sqrt(pow(v[0] - posx, 2) + pow(v[1] - posy, 2));

	if (dh < dv)
	{
		free(v);
		ver_or_hor(1);
		return (h);
	}
	else
	{
		free(h);
		ver_or_hor(0);
		return (v);
	}
}

/**
 * ver_or_hor - returns the coordinates of the
 * @s: coordinates of the horizontal intersection
 */
void ver_or_hor(int s)
{
	side = s;
}

/**
 * dist - returns the coordinates of the
 * @shorter: coordinates of the horizontal intersection
 * Return: returns coordinates of the shorter point
 */
float dist(double *shorter)
{
	float dh = sqrt(pow(shorter[0] - posx, 2) + pow(shorter[1] - posy, 2));

	return (dh);
}
