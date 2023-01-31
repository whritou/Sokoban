/*
** EPITECH PROJECT, 2022
** plib
** File description:
** lib
*/

#pragma once

int my_putstr(char const *str);
void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
char **my_strdelim(char *arg);
int my_strlen (char const *str);

typedef struct soko {
    char *size;
    char *file;
    char **map;
    char **map_ori;
    int	x;
    int	y;
    int p;
    int obj;
    int box;
    int	savey;
    int	savex;
    int check;
}game_t;

int deplacement(game_t *soko, int touche);
int win(game_t *soko);
int game(game_t *soko);
int structure(game_t *soko, char *file);
int check_file(game_t *soko, char *name);
void move_p(game_t *soko);
int check_error(game_t *soko);
void free_mem(game_t *soko);
int reset(game_t *soko);
