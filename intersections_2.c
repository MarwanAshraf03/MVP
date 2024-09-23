#include "project.h"

/**
 * calculate_for_hor - returns the coordinates of the
 * @p2_angle: hello world
 * @rayx: hello world
 * @rayy: hello world
 * @yd: hello world
 * @xd: hello world
 * @checks: hello world
 * @up: hello world
 * Return: returns coordinates of the shorter point
 */
void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
					   double *yd, double *xd, int *checks, int *up)
{
	double angle_tan = -1 / tan(*p2_angle * DEG);

	*checks = 0;
	if (*p2_angle <= 360 && *p2_angle > 180)
	{
		*up = 1;
		*rayy = ((int)posy / BLOCK_SIZE) * BLOCK_SIZE;
		*rayx = (posy - *rayy) * angle_tan + posx;
		*yd = -BLOCK_SIZE;
		*xd = -(*yd) * angle_tan;
	}
	else if (*p2_angle > 0 && *p2_angle < 180)
	{
		*up = 0;
		*rayy = ((int)posy / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
		*rayx = (posy - *rayy) * angle_tan + posx;
		*yd = BLOCK_SIZE;
		*xd = -(*yd) * angle_tan;
	}
}

int iterate_for_hor(int *mx, int *my, int *up, int *checks,
					double *rayx, double *rayy, double *yd, double *xd)
{
	*mx = (int)*rayx / BLOCK_SIZE;
	*my = 0;

	if (*up)
		*my = ((int)*rayy / BLOCK_SIZE) - 1;
	if (!*up)
		*my = ((int)*rayy / BLOCK_SIZE);
	*mx = abs(*mx);
	*my = abs(*my);
	if ((*mx <= mapHeight && *my <= mapWidth) && (worldMap[*my][*mx] == 0))
	{
		*rayy += *yd;
		*rayx += *xd;
		*checks += 1;
		return (1);
	}
	else
		return (0);
}

/**
 * calculate_for_ver - returns the coordinates of the
 * @p2_angle: hello world
 * @vrayx: hello world
 * @vrayy: hello world
 * @yd: hello world
 * @xd: hello world
 * @checks: hello world
 * @right: hello world
 * Return: returns coordinates of the shorter point
 */
void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
					   double *yd, double *xd, int *checks, int *right)
{
	*checks = 0;

	double nangle_tan = -tan(*p2_angle * DEG);

	if ((*p2_angle > 270 && *p2_angle < 360) ||
		(*p2_angle >= 0 && *p2_angle < 90))
	{
		*right = 1;
		*vrayx = (int)((posx + BLOCK_SIZE) / BLOCK_SIZE) * BLOCK_SIZE;
		*vrayy = (posx - *vrayx) * nangle_tan + posy;
		*xd = BLOCK_SIZE;
		*yd = -(*xd) * nangle_tan;
	}
	else if (*p2_angle < 270 && *p2_angle > 90)
	{

		*right = 0;
		*vrayx = ((int)posx / BLOCK_SIZE) * BLOCK_SIZE;
		*vrayy = (posx - *vrayx) * nangle_tan + posy;
		*xd = -BLOCK_SIZE;
		*yd = -(*xd) * nangle_tan;
	}
}

int iterate_for_ver(int *mx, int *my, int *right, int *checks,
					double *vrayx, double *vrayy, double *yd, double *xd)
{
	*my = (int)*vrayy / BLOCK_SIZE;
	*mx;
	if (*right)
		*mx = ((int)*vrayx / BLOCK_SIZE);
	if (!*right)
		*mx = ((int)*vrayx / BLOCK_SIZE) - 1;
	if ((*mx > mapWidth || *my > mapHeight) || (worldMap[*my][*mx] == 0))
	{
		*vrayy += *yd;
		*vrayx += *xd;
		*checks += 1;
		return (1);
	}
	else
		return (0);
}

/**
 * adjust_angle - makes the angle between 0 and 360 degrees
 * @p2_angle: the angle to be adjusted
 */
void adjust_angle(double *p2_angle)
{
	if (*p2_angle < 0)
		*p2_angle += 360;
	if (*p2_angle >= 360)
		*p2_angle -= 360;
}
