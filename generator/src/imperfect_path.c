/*
** EPITECH PROJECT, 2019
** dante
** File description:
** imperfect_path
*/

#include "my.h"

void rand_path(map_t *map, int i, int j, char **av)
{
    int random_chose = rand() % ((atoi(av[1]) + atoi(av[2])) / 2) + 1;

    if (random_chose == 1)
        map->map[i][j] = '*';
    else {
        map->map[i][j] = '0';
        map->map[i][j + 1] == '*' ? map->map[i][j] = 'X' : 0;
        map->map[i][j - 1] == '*' ? map->map[i][j] = 'X' : 0;
        map->map[i + 1][j] == '*' ? map->map[i][j] = 'X' : 0;
        map->map[i - 1][j] == '*' ? map->map[i][j] = 'X' : 0;
    }
}

int check_more_imp(map_t *map, int i, int j, char **av)
{
    int check = 0;

    map->map[i][j + 1] == '*' ? check++ : 0;
    map->map[i][j - 1] == '*' ? check++ : 0;
    map->map[i + 1][j] == '*' ? check++ : 0;
    map->map[i - 1][j] == '*' ? check++ : 0;
    if (check <= 1) {
        map->pos_i = i;
        map->pos_j = j;
    } else {
        rand_path(map, i, j, av);
    }
    return (check);
}

int check_arout_next_imperfect(map_t *map, char **av)
{
    if (map->map[map->pos_i][map->pos_j + 1] == 'P')
        return (check_more_imp(map, map->pos_i, map->pos_j + 1, av));
    if (map->map[map->pos_i][map->pos_j - 1] == 'P')
        return (check_more_imp(map, map->pos_i, map->pos_j - 1, av));
    if (map->map[map->pos_i + 1][map->pos_j] == 'P')
        return (check_more_imp(map, map->pos_i + 1, map->pos_j, av));
    if (map->map[map->pos_i - 1][map->pos_j] == 'P')
        return (check_more_imp(map, map->pos_i - 1, map->pos_j, av));
    return (5);
}
