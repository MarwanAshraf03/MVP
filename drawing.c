#include "project.h"

/**
 * draw_world - draws the worldMap
 */
void draw_world(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			SDL_Rect rect = {j * BLOCK_SIZE,
							 i * BLOCK_SIZE,
							 BLOCK_SIZE,
							 BLOCK_SIZE};
			if (worldMap[i][j] == 1)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderFillRect(renderer, &rect);
			}
			SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
			SDL_RenderDrawRect(renderer, &rect);
		}
	}
}

/**
 * draw_player - draws the player
 */
void draw_player(void)
{
	SDL_Rect rect;
	float center;

	rect.h = rect.w = 8;
	rect.x = posx, rect.y = posy;
	center = ((float)rect.w / 2.0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	intersections_combined();
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderDrawLine(renderer, posx + center, posy + center,
					   (posdx + (posx + center)), (posdy + (posy + center)));
}
