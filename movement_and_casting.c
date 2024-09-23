#include "project.h"
/**
 * move_turn_player - function for player movement
 */
void move_turn_player(void)
{
    int lineNumber;
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
            case 11:
                posy += posdy;
                posx += posdx;
                break;
            case 82:
                if (check_wall_front())
                {
                    posy += posdy;
                    posx += posdx;
                }
                break;
            case 81:
                if (check_wall_back())
                {
                    posy -= posdy;
                    posx -= posdx;
                }
                break;
            case 80:
                p_angle -= 5;
                if (p_angle < 0)
                    p_angle += 360;
                posdx = cos(p_angle * DEG) * (10 * sqrt(2));
                posdy = sin(p_angle * DEG) * (10 * sqrt(2));
                break;
            case 79:
                p_angle += 5;
                if (p_angle >= 360)
                    p_angle -= 360;
                posdx = cos(p_angle * DEG) * (10 * sqrt(2));
                posdy = sin(p_angle * DEG) * (10 * sqrt(2));
                break;
            case 41:
                state = 0;
                break;
            case 89:
                lineNumber = 1;
                parse_map(lineNumber);
                break;
            case 90:
                lineNumber = 2;
                parse_map(lineNumber);
                break;
            case 91:
                lineNumber = 3;
                parse_map(lineNumber);
                break;
            case 92:
                lineNumber = 4;
                parse_map(lineNumber);
                break;
            case 93:
                lineNumber = 5;
                parse_map(lineNumber);
                break;
            }
        }
    }
}

/**
 * check_wall_front: checks the front block if it is a wall
 * return: int regarding the block being a wall or not
 */
int check_wall_front(void)
{
    int r_no, checks, right = -1, up = -1, mx, my;
    double rayx, rayy, xd, yd, vrayx, vrayy,
        p2_angle = p_angle;
    double *ret = malloc(sizeof(double) * 2);
    double *ret2 = malloc(sizeof(double) * 2);

    calculate_for_hor(&p2_angle, &rayx, &rayy, &yd, &xd, &checks, &up);
    while (checks < 22)
    {
        mx = (int)rayx / BLOCK_SIZE;
        my = 0;

        if (up)
            my = ((int)rayy / BLOCK_SIZE) - 1;
        if (!up)
            my = ((int)rayy / BLOCK_SIZE);
        mx = abs(mx);
        my = abs(my);
        if ((mx <= mapHeight && my <= mapWidth) && (worldMap[my][mx] == 0))
        {
            rayy += yd;
            rayx += xd;
            checks += 1;
        }
        else
            break;
    }
    calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
    while (checks < 22)
    {
        my = (int)vrayy / BLOCK_SIZE;
        mx;
        if (right)
            mx = ((int)vrayx / BLOCK_SIZE);
        if (!right)
            mx = ((int)vrayx / BLOCK_SIZE) - 1;
        mx = abs(mx);
        my = abs(my);

        if ((mx > mapWidth || my > mapHeight) || (worldMap[my][mx] == 0))
        {
            vrayy += yd;
            vrayx += xd;
            checks += 1;
        }
        else
            break;
    }
    ret[0] = rayx;
    ret[1] = rayy;
    ret2[0] = vrayx;
    ret2[1] = vrayy;
    double *sh = shorter(ret, ret2);
    float distance = dist(sh);

    free(sh);
    if (distance > 20)
        return 1;
    return 0;
}

/**
 * check_wall_front: checks the front block if it is a wall
 * return: int regarding the block being a wall or not
 */
int check_wall_back(void)
{
    int r_no, checks, right = -1, up = -1, mx, my;
    double rayx, rayy, xd, yd, vrayx, vrayy,
        p2_angle = p_angle;
    double *ret = malloc(sizeof(double) * 2);
    double *ret2 = malloc(sizeof(double) * 2);

    if (p2_angle >= 180)
        p2_angle -= 180;
    if (p2_angle < 180)
        p2_angle += 180;
    calculate_for_hor(&p2_angle, &rayx, &rayy, &yd, &xd, &checks, &up);
    while (checks < 22)
    {
        mx = (int)rayx / BLOCK_SIZE;
        my = 0;

        if (up)
            my = ((int)rayy / BLOCK_SIZE) - 1;
        if (!up)
            my = ((int)rayy / BLOCK_SIZE);
        mx = abs(mx);
        my = abs(my);
        if ((mx <= mapHeight && my <= mapWidth) && (worldMap[my][mx] == 0))
        {
            rayy += yd;
            rayx += xd;
            checks += 1;
        }
        else
            break;
    }
    calculate_for_ver(&p2_angle, &vrayx, &vrayy, &yd, &xd, &checks, &right);
    while (checks < 22)
    {
        my = (int)vrayy / BLOCK_SIZE;
        mx;
        if (right)
            mx = ((int)vrayx / BLOCK_SIZE);
        if (!right)
            mx = ((int)vrayx / BLOCK_SIZE) - 1;
        mx = abs(mx);
        my = abs(my);

        if ((mx > mapWidth || my > mapHeight) || (worldMap[my][mx] == 0))
        {
            vrayy += yd;
            vrayx += xd;
            checks += 1;
        }
        else
            break;
    }
    ret[0] = rayx;
    ret[1] = rayy;
    ret2[0] = vrayx;
    ret2[1] = vrayy;
    double *sh = shorter(ret, ret2);
    float distance = dist(sh);

    free(sh);
    if (distance > 20)
        return 1;
    return 0;
}