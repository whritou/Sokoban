/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** structure
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int check_file(game_t *soko, char *name)
{
    char *size = 0;
    char *dest = "\n";
    size_t taille;
    if (fopen(name, "r") == NULL)
        exit(84);
    FILE *fichier = fopen(name, "r");
    while (getline(&size, &taille, fichier) != -1)
        dest = my_strcat(dest, size);
    soko->size = dest;
    soko->map_ori = my_strdelim(soko->size);
    soko->map = my_strdelim(soko->size);
    return (0);
}

int find_x(game_t *soko)
{
    soko->box = 0;
    for (int i = 0; soko->size[i]; i++)
        if (soko->size[i] == 'X')
            soko->box++;
    if (soko->box < soko->obj)
        return (84);
    return (0);
}

void find_o(game_t *soko)
{
    soko->obj = 0;
    for (int i = 0; soko->size[i]; i++)
        if (soko->size[i] == 'O')
            soko->obj++;
}

int find_p(game_t *soko)
{
    int p = 0;
    int x = 0;
    for (int y = 0; soko->map[y]; y++) {
        for (x = 0; soko->map[y][x] && soko->map[y][x] != 'P'; x++);
        if (soko->map[y][x] == 'P') {
            soko->y = y;
            soko->x = x;
        }
    }
    for (int i = 0; soko->size[i]; i++)
        if (soko->size[i] == 'P')
            p++;
    if (p != 1)
        return (84);
    return (0);
}

int structure(game_t *soko, char *file)
{
    if (check_file(soko, file) == 84)
        return (84);
    if (check_error(soko) == 84)
        return (84);
    find_o(soko);
    if (find_p(soko) == 84)
        return (84);
    if (find_x(soko) == 84)
        return (84);
    move_p(soko);
    game(soko);
    return (0);
}
