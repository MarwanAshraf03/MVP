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

/* draw.c */
void draw_world(void);
void draw_player(void);

/* movement_and_casting.c */
void move_turn_player(void);
void switch_for_movement(SDL_Event ev);
int check_wall_front(void);
int check_wall_back(void);

/* maths.c */
double *shorter(double *h, double *v);
void ver_or_hor(int s);
float dist(double *shorter);

/* intersections_1.c */
double *intersections_combined(void);
void draw_3d(double *sh, int r_no);

/* intersections_2.c */
void calculate_for_hor(double *p2_angle, double *rayx, double *rayy,
					   double *yd, double *xd, int *checks, int *up);
int iterate_for_hor(int *mx, int *my, int *up, int *checks, double *rayx,
					double *rayy, double *yd, double *xd);
void calculate_for_ver(double *p2_angle, double *vrayx, double *vrayy,
					   double *yd, double *xd, int *checks, int *right);
int iterate_for_ver(int *mx, int *my, int *right, int *checks, double *vrayx,
					double *vrayy, double *yd, double *xd);
void adjust_angle(double *p2_angle);

/* parser.c */
void parse_map(int lineNumber);

void move_forward(void);
void move_backward(void);
void turn_left(void);
void turn_right(void);

#endif
