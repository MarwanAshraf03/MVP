#include "project.h"
/*
 *double *print_hor_intersections(void)
 *{
 *	int r_no, i, checks, up = -1;
 *	double rayx, rayy, xd, yd;
 *	double p2_angle = p_angle;
 *	// double p2_angle = p_angle - 30;
 *	// if (p2_angle < 0)
 *	// 	p2_angle += 360;
 *	// if (p2_angle >= 360)
 *	// 	p2_angle -= 360;
 *
 *	for (r_no = 0; r_no < 1; r_no++)
 *	{
 *		checks = 0;
 *
 *		double angle_tan = -1 / tan(p2_angle * DEG);
 *
 *		if (p2_angle <= 360 && p2_angle > 180)
 *		{
 *			up = 1;
 *			rayy = ((int)posy / 64) * 64;
 *			rayx = (posy - rayy) * angle_tan + posx;
 *			yd = -64;
 *			xd = -yd * angle_tan;
 *		}
 *		else if (p2_angle > 0 && p2_angle < 180)
 *		{
 *			up = 0;
 *			rayy = ((int)posy / 64) * 64 + 64;
 *			rayx = (posy - rayy) * angle_tan + posx;
 *			yd = 64;
 *			xd = -yd * angle_tan;
 *		}
 *		else
 *		{
 *			rayx = posx;
 *			rayy = posy;
 *			checks = 8;
 *		}
 *		while (checks < 8)
 *		{
 *			int mx = (int)rayx / 64;
 *			int my = 0;
 *
 *			if (up)
 *				my = ((int)rayy / 64) - 1;
 *			if (!up)
 *				my = ((int)rayy / 64);
 *			if ((worldMap[my][mx] == 0))
 *			{
 *				rayy += yd;
 *				rayx += xd;
 *				checks += 1;
 *			}
 *			else
 *				break;
 *		}
 *		// p2_angle += 1;
 *		// if (p2_angle < 0)
 *		// 	p2_angle += 360;
 *		// if (p2_angle >= 360)
 *		// 	p2_angle -= 360;
 *		// SDL_RenderDrawLine(renderer, posx + 5, posy + 5, rayx, rayy);
 *	}
 *	double *ret = malloc(sizeof(double) * 2);
 *
 *	ret[0] = rayx;
 *	ret[1] = rayy;
 *	return (ret);
 *}
 *
 *double *print_ver_intersections(void)
 *{
 *	int r_no, i, checks, right = -1;
 *	double vrayx, vrayy, xd, yd;
 *	double p2_angle = p_angle;
 *
 *	for (r_no = 0; r_no < 1; r_no++)
 *	{
 *		checks = 0;
 *
 *		double nangle_tan = -tan(p2_angle * DEG);
 *
 *		if ((p2_angle > 270 && p2_angle < 360) || (p2_angle >= 0 && p2_angle < 90))
 *		{
 *			right = 1;
 *			vrayx = (int)((posx + 64) / 64) * 64;
 *			vrayy = (posx - vrayx) * nangle_tan + posy;
 *			xd = 64;
 *			yd = -xd * nangle_tan;
 *		}
 *		else if (p2_angle < 270 && p2_angle > 90)
 *		{
 *			right = 0;
 *			vrayx = ((int)posx / 64) * 64;
 *			vrayy = (posx - vrayx) * nangle_tan + posy;
 *			xd = -64;
 *			yd = -xd * nangle_tan;
 *		}
 *		else
 *		{
 *			vrayx = posx;
 *			vrayy = posy;
 *			checks = 8;
 *		}
 *		int my;
 *		int mx;
 *		while (checks < 8)
 *		{
 *			my = (int)vrayy / 64;
 *			mx;
 *			if (right)
 *				mx = ((int)vrayx / 64);
 *			if (!right)
 *				mx = ((int)vrayx / 64) - 1;
 *			if ((worldMap[my][mx] == 0))
 *			{
 *				vrayy += yd;
 *				vrayx += xd;
 *				checks += 1;
 *			}
 *			else
 *				break;
 *		}
 *	}
 *	double *ret = malloc(sizeof(double) * 2);
 *
 *	ret[0] = vrayx;
 *	ret[1] = vrayy;
 *	return (ret);
 *}
 */