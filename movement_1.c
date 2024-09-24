#include "project.h"
/**
 * move_turn_player - function for player movement
 */
void move_turn_player(void)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			state = 0;
			break;
		case SDL_KEYDOWN:
			switch_for_movement(ev);
		}
	}
}

/**
 * switch_for_movement - function for player movement
 * @ev: the event to be determined
 */
void switch_for_movement(SDL_Event ev)
{
	switch (ev.key.keysym.scancode)
	{
	case 82:
		move_forward();
		break;
	case 81:
		move_backward();
		break;
	case 80:
		turn_left();
		break;
	case 79:
		turn_right();
		break;
	case 41:
		state = 0;
		break;
	case 89:
		parse_map(1);
		break;
	case 90:
		parse_map(2);
		break;
	case 91:
		parse_map(3);
		break;
	case 92:
		parse_map(4);
		break;
	case 93:
		parse_map(5);
		break;
	default:
		break;
	}
}

/**
 * check_wall_front - checks the front block if it is a wall
 * Return: int regarding the block being a wall or not
 */
int check_wall_front(void)
{
	int checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd,
		yd, vrayx, vrayy, p2_angle = p_angle, *sh,
						  *ret = malloc(sizeof(double) * 2), *ret2 = malloc(sizeof(double) * 2);

	calculate_for_hor(&p2_angle, &rayx, &rayy, &yd, &xd, &checks, &up);
	while (checks < 22)
		if (!iterate_for_hor(&mx, &my, &up, &checks, &rayx, &rayy, &yd, &xd))
			break;
	calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
	while (checks < 22)
		if (!iterate_for_ver(&mx, &my, &right, &checks, &vrayx, &vrayy, &yd, &xd))
			break;
	ret[0] = rayx;
	ret[1] = rayy;
	ret2[0] = vrayx;
	ret2[1] = vrayy;
	sh = shorter(ret, ret2);
	float distance = dist(sh);

	free(sh);
	if (distance > 20)
		return (1);
	return (0);
}

/**
 * check_wall_back - checks the front block if it is a wall
 * Return: int regarding the block being a wall or not
 */
int check_wall_back(void)
{
	int checks, right = -1, up = -1, mx, my;
	double rayx, rayy, xd,
		yd, vrayx, vrayy, p2_angle = p_angle, *sh,
						  *ret = malloc(sizeof(double) * 2), *ret2 = malloc(sizeof(double) * 2);

	if (p2_angle > 180)
		p2_angle -= 180;
	else if (p2_angle < 180)
		p2_angle += 180;
	else if (p2_angle == 180)
		p2_angle = 0;
	calculate_for_hor(&p2_angle, &rayx, &rayy, &yd, &xd, &checks, &up);
	while (checks < 22)
		if (!iterate_for_hor(&mx, &my, &up, &checks, &rayx, &rayy, &yd, &xd))
			break;
	calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
	while (checks < 22)
		if (!iterate_for_ver(&mx, &my, &right, &checks, &vrayx, &vrayy, &yd, &xd))
			break;
	ret[0] = rayx;
	ret[1] = rayy;
	ret2[0] = vrayx;
	ret2[1] = vrayy;
	sh = shorter(ret, ret2);
	float distance = dist(sh);

	free(sh);
	if (distance > 20)
		return (1);
	return (0);
}
