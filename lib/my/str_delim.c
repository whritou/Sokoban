/*
** EPITECH PROJECT, 2022
** my_str_delim
** File description:
** str delim
*/

#include "my.h"
#include <stdlib.h>

char **my_strdelim(char *arg)
{
    char **dest;
    int nb;
    int y = 0;
    int x = 0;
    for (nb = 0; arg[nb] != '\0'; nb++);
    dest = malloc(sizeof(char*) * nb + 1);
    for (int i = 0; arg[i]; y++) {
        while (arg[i] == '\n' && arg[i])
            i++;
        dest[y] = malloc(sizeof(char) * (nb + 1));
        for (x = 0; arg[i] != '\n' && arg[i]; x++, i++)
            dest[y][x] = arg[i];
        dest[y][x] = '\0';
    }
    dest[y] = 0;
    return (dest);
}
