#ifndef PROJECT_H
#define PROJECT_H
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#define mapWidth 22
#define mapHeight 22
#define screenWidth 704
#define screenHeight 704
#define BLOCK_SIZE 32
#define PI 3.14159
#define DEG 0.0174533

extern double posx, posy, posdx, posdy, state;
extern int side;
extern double p_angle;
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Window *window2;
extern SDL_Renderer *renderer2;
extern int worldMap[mapHeight][mapWidth];

void draw_world(void);
void draw_player(void);
void move_turn_player(void);
double *shorter(double *h, double *v);
double *intersections_combined(void);
void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
                       double *yd, double *xd, int *checks, int *up);
void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
                       double *yd, double *xd, int *checks, int *right);
void ver_or_hor(int s);
float dist(double *shorter);
void draw_3d(double *sh, int r_no);
int check_wall_front(void);
int check_wall_back(void);
void parse_map(int lineNumber);

#endif
