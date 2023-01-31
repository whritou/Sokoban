/*
** EPITECH PROJECT, 2022
** my_strcpy2
** File description:
** copy string
*/

char **my_strcpy2 (char **dest, char **src)
{
    int x;
    int y = 0;
    for (x = 0; src[x][y] != '\0'; x++)
        dest[x][y] = src[x][y];
        if (src[x][y] == '\0')
            y++;
    dest[x][y] = '\0';
    return (dest);
}
