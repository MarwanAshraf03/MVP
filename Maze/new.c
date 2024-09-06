#include "project.h"

void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
					   double *yd, double *xd, int *checks, int *up)
{
	double angle_tan = -1 / tan(*p2_angle * DEG);

	*checks = 0;
	if (*p2_angle <= 360 && *p2_angle > 180)
	{
		printf("hor not not else\n");
		*up = 1;
		*rayy = ((int)posy / 64) * 64;
		*rayx = (posy - *rayy) * angle_tan + posx;
		*yd = -64;
		*xd = -(*yd) * angle_tan;
	}
	else if (*p2_angle > 0 && *p2_angle < 180)
	{
		printf("hor not else\n");
		*up = 0;
		*rayy = ((int)posy / 64) * 64 + 64;
		*rayx = (posy - *rayy) * angle_tan + posx;
		*yd = 64;
		*xd = -(*yd) * angle_tan;
	}
	else
	{
		printf("hor else\n");
		*rayx = posx;
		*rayy = posy;
		*checks = 8;
	}
}

void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
					   double *yd, double *xd, int *checks, int *right)
{
	*checks = 0;

	double nangle_tan = -tan(*p2_angle * DEG);

	if ((*p2_angle > 270 && *p2_angle < 360) ||
		(*p2_angle >= 0 && *p2_angle < 90))
	{
		printf("not not else\n");
		*right = 1;
		*vrayx = (int)((posx + 64) / 64) * 64;
		*vrayy = (posx - *vrayx) * nangle_tan + posy;
		*xd = 64;
		*yd = -(*xd) * nangle_tan;
	}
	else if (*p2_angle < 270 && *p2_angle > 90)
	{

		printf("not else\n");
		*right = 0;
		*vrayx = ((int)posx / 64) * 64;
		*vrayy = (posx - *vrayx) * nangle_tan + posy;
		*xd = -64;
		*yd = -(*xd) * nangle_tan;
	}
	else
	{
		printf("else\n");
		*vrayx = posx;
		*vrayy = posy;
		*checks = 8;
	}
}

double *intersections_combined(void)
{
	int r_no, checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd, yd, vrayx, vrayy,
		p2_angle = p_angle;

	p2_angle = p_angle - 30;
	if (p2_angle < 0)
		p2_angle += 360;
	if (p2_angle >= 360)
		p2_angle -= 360;

	for (r_no = 0; r_no < 60; r_no++)
	{
		double *ret = malloc(sizeof(double) * 2);
		double *ret2 = malloc(sizeof(double) * 2);

		calculate_for_hor(&p2_angle, &rayx, &rayy, &yd, &xd, &checks, &up);
		while (checks < 8)
		{
			mx = (int)rayx / 64;
			my = 0;

			if (up)
				my = ((int)rayy / 64) - 1;
			if (!up)
				my = ((int)rayy / 64);
			if ((worldMap[my][mx] == 0))
			{
				rayy += yd;
				rayx += xd;
				checks += 1;
			}
			else
				break;
		}
		calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
		while (checks < 8)
		{
			my = (int)vrayy / 64;
			mx;
			if (right)
				mx = ((int)vrayx / 64);
			if (!right)
				mx = ((int)vrayx / 64) - 1;
			if ((mx > mapWidth || my > mapHeight) || (worldMap[my][mx] == 0))
			{
				vrayy += yd;
				vrayx += xd;
				checks += 1;
			}
			else
				break;
		}
		p2_angle += 1;
		if (p2_angle < 0)
			p2_angle += 360;
		if (p2_angle >= 360)
			p2_angle -= 360;
		ret[0] = rayx;
		ret[1] = rayy;
		ret2[0] = vrayx;
		ret2[1] = vrayy;
		double *sh = shorter(ret, ret2);

		SDL_RenderDrawLine(renderer, posx + 5, posy + 5, sh[0], sh[1]);
		free(sh);
	}
}

void draw_3d(void)
{
}