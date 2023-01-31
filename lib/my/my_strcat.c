/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** copie un string au bout d'un string
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int plus = 0;
    char *desti = malloc(sizeof(*desti) *
    (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i]) {
        desti[i] = dest[i];
        i++;
    }
    while (src[plus]) {
        desti[plus + i] = src[plus];
        plus++;
    }
    desti[plus + i] = '\0';
    return (desti);
}
