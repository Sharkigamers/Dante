/*
** EPITECH PROJECT, 2019
** dante
** File description:
** my
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef GEN_
#define GEN_

typedef struct stock_elements
{
    struct stock_elements *next;
    struct stock_elements *prev;
    int *pos;
} stock_t;

typedef struct map
{
    char **map;
    stock_t *stock;
    int pos_i;
    int pos_j;
    int finish;
} map_t;

/* main */
int generator(char **av, int ac);

/* initialisation */
int initialize(char **av, map_t *map);
void init_var(map_t *map);

/* free */
void free_all(map_t *map);

/* path */
int create_path(map_t *map, int ac, char **av);

/* final check */
int final_check(map_t *map, char **av);

/* imperfect */
int check_arout_next_imperfect(map_t *map, char **av);

#endif
