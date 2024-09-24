#include "project.h"

double posx = 276.365627, posy = 292.160488, posdx = 0, posdy = 0, state = 1;
double p_angle;
int side = -1, map_on = 1;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Window *window2;
SDL_Renderer *renderer2;
int worldMap[mapWidth][mapHeight];

/**
 * main - entery point to the program
 * Return: returns state of end
 */
int main(void)
{
	parse_map(1);
	posdx = 0;
	posdy = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);
	window2 = SDL_CreateWindow("The Maze Project", 0, 0,
							   screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer2 = SDL_CreateRenderer(window2, -1,
								   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	while (state)
	{
		SDL_SetRenderDrawColor(renderer2, 0, 0, 255, 255);
		SDL_RenderDrawLine(renderer2, screenWidth / 2, 0,
						   screenWidth / 2, screenHeight);
		move_turn_player();
		intersections_combined();
		if (map_on)
			draw_world_on_viewport();
		SDL_RenderPresent(renderer2);
	}
	SDL_DestroyRenderer(renderer2);
	SDL_DestroyWindow(window);
	SDL_DestroyWindow(window2);
	SDL_Quit();
	return (0);
}
