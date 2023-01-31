/*
** EPITECH PROJECT, 2022
** my_strncat.c
** File description:
** copie n carachtere d'une string dans une autre
*/

#include "my.h"
#include <stdlib.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int	plus = 0;
    int	i = my_strlen(dest);
    while (src[plus] && plus < nb) {
        dest[plus + i] = src[plus];
        plus++;
    }
    dest[plus + i] = '\0';
    return (dest);
}
