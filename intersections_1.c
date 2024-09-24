#include "project.h"

/**
 * intersections_combined - finds the walls of the map
 */
void intersections_combined(void)
{
	int r_no, checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd, yd, vrayx, vrayy, p2_angle, *sh;

	p2_angle = p_angle - 30;
	adjust_angle(&p2_angle);
	for (r_no = 0; r_no < 60; r_no++)
	{
		double *ret = malloc(sizeof(double) * 2), *ret2 = malloc(sizeof(double) * 2);

		calculate_for_hor(&p2_angle, &rayx, &rayy, &yd, &xd, &checks, &up);
		while (checks < 22)
			if (!iterate_for_hor(&mx, &my, &up, &checks, &rayx, &rayy, &yd, &xd))
				break;
		calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
		while (checks < 22)
			if (!iterate_for_ver(&mx, &my, &right, &checks, &vrayx, &vrayy, &yd, &xd))
				break;
		p2_angle += 1;
		adjust_angle(&p2_angle);
		ret[0] = rayx;
		ret[1] = rayy;
		ret2[0] = vrayx;
		ret2[1] = vrayy;
		sh = shorter(ret, ret2);
		draw_3d(sh, r_no);
		free(sh);
	}
}

/**
 * draw_3d - draws the 3d world
 * @sh: coordinates of the shorter ray either the
 * horizontal or the vertical intersection ray
 * @r_no: the ray number whcih helps in the placement of rays on the renderer
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
