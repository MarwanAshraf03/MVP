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

/**
 * intersections_combined - returns the coordinates of the
 * Return: returns coordinates of the shorter point
 */
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
		while (checks < 22)
		{
			mx = (int)rayx / BLOCK_SIZE;
			my = 0;

			if (up)
				my = ((int)rayy / BLOCK_SIZE) - 1;
			if (!up)
				my = ((int)rayy / BLOCK_SIZE);
			mx = abs(mx);
			my = abs(my);
			if ((mx <= mapHeight && my <= mapWidth) && (worldMap[my][mx] == 0))
			{
				rayy += yd;
				rayx += xd;
				checks += 1;
			}
			else
				break;
		}
		calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
		while (checks < 22)
		{
			my = (int)vrayy / BLOCK_SIZE;
			mx;
			if (right)
				mx = ((int)vrayx / BLOCK_SIZE);
			if (!right)
				mx = ((int)vrayx / BLOCK_SIZE) - 1;
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
		draw_3d(sh, r_no);
		free(sh);
	}
}

/**
 * draw_3d - returns the coordinates of the
 * @sh: coordinates of the horizontal intersection
 * @r_no: coordinates of the horizontal intersection
 */
void draw_3d(double *sh, int r_no)
{
	float distance = dist(sh);
	float line_height = (BLOCK_SIZE * screenHeight) / distance;

	if (line_height > screenHeight)
		line_height = screenHeight;
	if (side)
		SDL_SetRenderDrawColor(renderer2, 255, 0, 0, 255);
	else
		SDL_SetRenderDrawColor(renderer2, 0, 255, 0, 255);
	SDL_Rect rect;

	rect.h = line_height;
	rect.w = 12;
	rect.x = ((double)r_no / 60.0) * screenWidth;
	rect.y = (screenHeight / 2) - (line_height / 2);
	SDL_RenderFillRect(renderer2, &rect);
}
