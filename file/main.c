/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>

int reset(game_t *soko)
{
    if (structure(soko, soko->file) == 84) {
        free_mem(soko);
        return (84);
    }
    return (0);
}

void free_mem(game_t *soko)
{
    int i;
    for (int i = 0;soko->map_ori[i]; i++) {
        free(soko->map[i]);
        free(soko->map_ori[i]);
    }
    free(soko->map);
    free(soko->map_ori);
    free(soko->size);
}

int check_error(game_t *soko)
{
    for (int i = 0; soko->size[i] != '\0'; i++)
        if (soko->size[i] != ' ' && soko->size[i] != '#' &&
        soko->size[i] != 'P' && soko->size[i] != 'O' && soko->size[i] != 'X' &&
        soko->size[i] != '\n')
            return (84);
    return (0);
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map, containing");
    my_putstr(" '#' for walls,\n");
    my_putstr("         'P' for the players 'X' for boxes and 'O' for ");
    my_putstr("storage locations.\n");
}

int	main(int argc, char **argv)
{
    game_t soko;
    soko.file = argv[1];
    if (argc != 2)
        return (84);
    else if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        help();
        return (0);
    } else {
        if (structure(&soko, argv[1]) == 84) {
            free_mem(&soko);
            return (84);
        }
    }
    return (0);
}
