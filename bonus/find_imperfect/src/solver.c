/*
** EPITECH PROJECT, 2019
** dante
** File description:
** solver
*/

#include "my.h"

int solver(char **av)
{
    map_t map;

    if (fill_map(av, &map) == 84)
        return (84);
    map.error = 0;
    do {
        if (map.finish == 0) {
            map.stock = NULL;
            map.finish = 1;
        }
        resolving_algo(&map);
    }
    while (map.stock != NULL);
    for (int i = 0; map.map[i] != NULL; i++)
        printf("%s", map.map[i]);
    printf("ERROR : %d\n", map.error);
    if (map.error > 0)
        printf("La map est imparfaite\n");
    free_all(&map);
    return (0);
}
