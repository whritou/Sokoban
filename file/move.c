/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** move
*/

#include "my.h"
#include <ncurses.h>

void haut(game_t *soko, int x, int y)
{
    if ((soko->map[y - 1][x] == 'X' && soko->map[y - 2][x] == 'O') ||
    (soko->map[y - 1][x] == 'X' && soko->map[y - 2][x] == ' ') &&
    soko->map[soko->y - 1][soko->x] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y - 1][x] = 'P';
        soko->map[y - 2][x] = 'X';
        soko->y--;
    } else if (soko->map[y - 1][x] == ' ' || soko->map[y - 1][x] == 'O' &&
    soko->map[soko->y - 1][soko->x] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y - 1][x] = 'P';
        soko->y--;
    }
}

void bas(game_t *soko, int x, int y)
{
    if ((soko->map[y + 1][x] == 'X' && soko->map[y + 2][x] == 'O') ||
    (soko->map[y + 1][x] == 'X' && soko->map[y + 2][x] == ' ') &&
    soko->map[soko->y + 1][soko->x] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y + 1][x] = 'P';
        soko->map[y + 2][x] = 'X';
        soko->y++;
    } else if (soko->map[y + 1][x] == ' ' || soko->map[y + 1][x] == 'O' &&
    soko->map[soko->y + 1][soko->x] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y + 1][x] = 'P';
        soko->y++;
    }
}

void droite(game_t *soko, int x, int y)
{
    if ((soko->map[y][x + 1] == 'X' && soko->map[y][x + 2] == 'O') ||
    (soko->map[y][x + 1] == 'X' && soko->map[y][x + 2] == ' ') &&
    soko->map[soko->y][soko->x + 1] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y][x + 1] = 'P';
        soko->map[y][x + 2] = 'X';
        soko->x++;
    } else if (soko->map[y][x + 1] == ' ' || soko->map[y][x + 1] == 'O' &&
    soko->map[soko->y][soko->x + 1] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y][x + 1] = 'P';
        soko->x++;
    }
}

void gauche(game_t *soko, int x, int y)
{
    if ((soko->map[y][x - 1] == 'X' && soko->map[y][x - 2] == 'O') ||
    (soko->map[y][x - 1] == 'X' && soko->map[y][x - 2] == ' ') &&
    soko->map[soko->y][soko->x - 1] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y][x - 1] = 'P';
        soko->map[y][x - 2] = 'X';
        soko->x--;
    } else if (soko->map[y][x - 1] == ' ' || soko->map[y][x - 1] == 'O' &&
    soko->map[soko->y][soko->x - 1] != '#') {
        soko->map[y][x] = soko->map_ori[y][x];
        soko->map[y][x - 1] = 'P';
        soko->x--;
    }
}

int deplacement(game_t *soko, int touche)
{
    if (touche == KEY_UP)
        haut(soko, soko->x, soko->y);
    if (touche == KEY_DOWN)
        bas(soko, soko->x, soko->y);
    if (touche == KEY_RIGHT)
        droite(soko, soko->x, soko->y);
    if (touche == KEY_LEFT)
        gauche(soko, soko->x, soko->y);
    if (touche == ' ') {
        reset(soko);
        return (1);
    }
    return (0);
}
