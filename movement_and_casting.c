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
			switch (ev.key.keysym.scancode)
			{
			case 82:
				posy += posdy;
				posx += posdx;
				break;
			case 81:
				posy -= posdy;
				posx -= posdx;
				break;
			case 80:
				p_angle -= 1;
				if (p_angle < 0)
					p_angle += 360;
				posdx = cos(p_angle * DEG) * (5 * sqrt(2));
				posdy = sin(p_angle * DEG) * (5 * sqrt(2));
				break;
			case 79:
				p_angle += 1;
				if (p_angle >= 360)
					p_angle -= 360;
				posdx = cos(p_angle * DEG) * (5 * sqrt(2));
				posdy = sin(p_angle * DEG) * (5 * sqrt(2));
				break;
			case 41:
				state = 0;
				break;
			}
		}
	}
}
