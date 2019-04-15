/*
** EPITECH PROJECT, 2019
** dante
** File description:
** initialize
*/

#include "my.h"

void free_all(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++)
        free(map->map[i]);
    free(map->map);
}

int initialize(char **av, map_t *map)
{
    if ((map->map = malloc(sizeof(char *) * (atoi(av[1]) + 3))) == NULL)
        return (84);
    map->map[0] = malloc(atoi(av[2]) + 3);
    for (int j = 0; j <= atoi(av[2]) + 1; j++)
        map->map[0][j] = '1';
    map->map[0][atoi(av[2]) + 2] = '\0';
    for (int i = 1; i < atoi(av[1]) + 1; i++) {
        map->map[i] = malloc(atoi(av[2]) + 3);
        map->map[i][0] = '1';
        for (int j = 1; j <= atoi(av[2]); j++)
            map->map[i][j] = '0';
        map->map[i][atoi(av[2]) + 1] = '1';
        map->map[i][atoi(av[2]) + 2] = '\0';
    }
    map->map[atoi(av[1]) + 1] = malloc(atoi(av[2]) + 3);
    for (int j = 0; j <= atoi(av[2]) + 1; j++)
        map->map[atoi(av[1]) + 1][j] = '1';
    map->map[atoi(av[1]) + 1][atoi(av[2]) + 2] = '\0';
    map->map[atoi(av[1]) + 2] = NULL;
    return (0);
}

void init_var(map_t *map)
{
    srand(time(NULL));
    map->pos_i = 1;
    map->pos_j = 1;
    map->finish = 0;
}
