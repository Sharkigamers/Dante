/*
** EPITECH PROJECT, 2019
** dante
** File description:
** generator
*/

#include "my.h"

int perfect_maze(map_t *map, char **av, int ac)
{
    if (initialize(av, map) == 84)
        return (84);
    init_var(map);
    do {
        if (map->finish == 0) {
            map->stock = NULL;
            map->finish = 1;
        }
        if (create_path(map, ac, av) == 84)
            return (84);
    }
    while (map->stock != NULL);
    if (final_check(map, av) == 84)
        return (84);
    free(map->stock);
    free_all(map);
    return (0);
}

int generator(char **av, int ac)
{
    map_t map;

    if (perfect_maze(&map, av, ac) == 84)
        return (84);
    return (0);
}
