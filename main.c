#include "project.h"

double posx = 128, posy = 128, posdx = 0, posdy = 0, state = 1;
double p_angle = 10;
SDL_Window *window;
SDL_Renderer *renderer;
int worldMap[mapWidth][mapHeight] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}};
int main(void)
{
	posdx = 20;
	posdy = 20;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Error init: %s\n", SDL_GetError());
		return (1);
	}
	// window = SDL_CreateWindow("Ray Caster", 0, 0,
	// 						  screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	window = SDL_CreateWindow("Ray Caster", 0, 0,
							  512, 512, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1,
								  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	while (state)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		draw_world();
		move_turn_player();
		draw_player();
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyWindow(window);

	SDL_Quit();
	return (0);
}
