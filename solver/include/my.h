/*
** EPITECH PROJECT, 2019
** dante
** File description:
** my
*/

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#ifndef MY_
#define MY_

typedef struct stock_elements
{
    struct stock_elements *next;
    struct stock_elements *prev;
    int *pos;
} stock_t;

typedef struct my_map
{
    char **map;
    stock_t *stock;
    int pos_i;
    int pos_j;
    int finish;
    int finish_i;
    int finish_j;
} map_t;

int solver(char **av);
int fill_map(char **av, map_t *map);
int resolving_algo(map_t *map);
void print(map_t *map);
void free_all(map_t *map);
int gest_error(char *buf);

#endif
