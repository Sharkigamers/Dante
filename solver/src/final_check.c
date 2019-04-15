/*
** EPITECH PROJECT, 2019
** dante
** File description:
** final_check
*/

#include "my.h"

char *my_strstartdup(char *src, int i)
{
    char *str = malloc(strlen(src) + 1);
    int k;

    for (k = 0; src[i] != '\0'; i++, k++) {
        src[i] == 'P' ? src[i] = 'o' : 0;
        src[i] == 'H' ? src[i] = '*' : 0;
        str[k] = src[i];
    }
    str[k] = '\0';
    return (str);
}

void print(map_t *map)
{
    char *final_write;

    map->map[map->finish_i][map->finish_j] = 'o';
    map->map[map->finish_i][map->finish_j + 1] == '\n' ?
        map->map[map->finish_i][map->finish_j + 1] = '\0' : 0;
    for (int i = 1; map->map[i + 1] != NULL; i++) {
        final_write = my_strstartdup(map->map[i], 1);
        write(1, final_write, strlen(final_write));
        free(final_write);
    }
}
