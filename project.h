#ifndef PROJECT_H
#define PROJECT_H
#include <SDL2/SDL.h>
#include <math.h>
#define mapWidth 8
#define mapHeight 8
#define screenWidth 1024
#define screenHeight 512
#define PI 3.14159
#define DEG 0.0174533

extern double posx, posy, posdx, posdy, state;
extern double p_angle;
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int worldMap[mapHeight][mapWidth];

void draw_world(void);
void draw_player(void);
void move_turn_player(void);
double *print_hor_intersections(void);
double *print_ver_intersections(void);
double *shorter(double *h, double *v);
double *intersections_combined(void);
void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
					   double *yd, double *xd, int *checks, int *up);
void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
					   double *yd, double *xd, int *checks, int *right);

#endif
