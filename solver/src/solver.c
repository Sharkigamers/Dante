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
    do {
        if (map.finish == 0) {
            map.stock = NULL;
            map.finish = 1;
        }
        resolving_algo(&map);
        if (map.stock == NULL) {
            printf("%s", "no solution found");
            return (84);
        }
    }
    while (map.pos_i != map.finish_i || map.pos_j != map.finish_j);
    print(&map);
    free_all(&map);
    return (0);
}
