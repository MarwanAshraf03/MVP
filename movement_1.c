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
 * handle_map_parsing - helper function for the switch_for_movement function
 * @scancode: the button pressed
 */
void handle_map_parsing(int scancode)
{
	if (scancode >= 89 && scancode <= 94)
		parse_map(scancode - 88);
}

/**
 * switch_for_movement - function for player movement
 * @ev: the event to be determined
 */
void switch_for_movement(SDL_Event ev)
{
	int scancode = ev.key.keysym.scancode;

	switch (scancode)
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
	case 16:
		map_on ^= 1;
		break;
	default:
		handle_map_parsing(scancode);
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
