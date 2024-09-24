#include "project.h"

double posx = 276.365627, posy = 292.160488, posdx = 0, posdy = 0, state = 1;
double p_angle;
int side = -1;
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
	window = SDL_CreateWindow("Ray Caster", 0, 0,
							  704, 704, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1,
								  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	window2 = SDL_CreateWindow("The 3D drawing", screenWidth, 0,
							   screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	renderer2 = SDL_CreateRenderer(window2, -1,
								   SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	while (state)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer2, 0, 0, 0, 255);
		SDL_RenderClear(renderer2);
		SDL_SetRenderDrawColor(renderer2, 0, 0, 255, 255);
		SDL_RenderDrawLine(renderer2, screenWidth / 2, 0,
						   screenWidth / 2, screenHeight);
		draw_world();
		move_turn_player();
		draw_player();
		SDL_RenderPresent(renderer);
		SDL_RenderPresent(renderer2);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyRenderer(renderer2);
	SDL_DestroyWindow(window);
	SDL_DestroyWindow(window2);
	SDL_Quit();
	return (0);
}
