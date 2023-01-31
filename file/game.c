/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** game
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

int game_suite(game_t *soko, int touche)
{
    if (deplacement(soko, touche) == 1)
        return (15);
    refresh();
    if (win(soko) == 0) {
        free_mem(soko);
        return (15);
    }
    return (0);
}

int game(game_t *soko)
{
    int touche;
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    while (1) {
        for (int i = 0; soko->map[i]; i++)
            mvprintw(i, 0, "%s", soko->map[i]);
        touche = getch();
        if (game_suite(soko, touche) == 15) {
            endwin();
            return (0);
        }
    }
    endwin();
    free_mem(soko);
    return (0);
}

void move_p(game_t *soko)
{
    int y = 0;
    int x = 0;
    for (int y = 0; soko->map_ori[y]; y++)
        for (x = 0; soko->map_ori[y][x]; x++)
            (soko->map_ori[y][x] == 'X' || soko->map_ori[y][x] == 'P') ?
            soko->map_ori[y][x] = ' ' : 0;
}

int win(game_t *soko)
{
    int i = 0;
    if (soko->map_ori[soko->y][soko->x] == 'O')
        i++;
    for (int y = 0; soko->map_ori[y]; y++)
        for (int x = 0; soko->map_ori[y][x]; x++)
            soko->map[y][x] == 'O' ? i++ : 0;
    return (i);
}
