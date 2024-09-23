#include "project.h"

/**
 * move_forward - Moves the player forward if no wall is in front.
 */
void move_forward(void)
{
	if (check_wall_front())
	{
		posy += posdy;
		posx += posdx;
	}
}

/**
 * move_backward - Moves the player backward if no wall is behind.
 */
void move_backward(void)
{
	if (check_wall_back())
	{
		posy -= posdy;
		posx -= posdx;
	}
}

/**
 * turn_right - Rotates the player right by 5 degrees.
 */
void turn_right(void)
{
	p_angle += 5;
	if (p_angle >= 360)
		p_angle -= 360;
	posdx = cos(p_angle * DEG) * (10 * sqrt(2));
	posdy = sin(p_angle * DEG) * (10 * sqrt(2));
}
/**
 * turn_left - Rotates the player left by 5 degrees.
 */
void turn_left(void)
{
	p_angle -= 5;
	if (p_angle < 0)
		p_angle += 360;
	posdx = cos(p_angle * DEG) * (10 * sqrt(2));
	posdy = sin(p_angle * DEG) * (10 * sqrt(2));
}
