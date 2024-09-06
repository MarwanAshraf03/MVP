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

	if (p_angle == 0 || p_angle == 180)
		return (v);
	if (p_angle == 90 || p_angle == 270)
		return (h);
	if (dh < dv)
	{
		free(v);
		return (h);
	}
	else
	{
		free(h);
		return (v);
	}
}
