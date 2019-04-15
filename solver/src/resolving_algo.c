/*
** EPITECH PROJECT, 2019
** dante
** File description:
** resolving_algo
*/

#include "my.h"

int check_around(map_t *map)
{
    if (map->map[map->pos_i][map->pos_j + 1] == '*') {
        map->pos_j += 1;
        return (1);
    }
    if (map->map[map->pos_i + 1][map->pos_j] == '*') {
        map->pos_i += 1;
        return (1);
    }
    if (map->map[map->pos_i][map->pos_j - 1] == '*') {
        map->pos_j -= 1;
        return (1);
    }
    if (map->map[map->pos_i - 1][map->pos_j] == '*') {
        map->pos_i -= 1;
        return (1);
    }
    return (0);
}

int fill_stock(map_t *map, stock_t **stock)
{
    int *elem;
    stock_t *node;
    stock_t *last_node = (*stock);

    if ((elem = malloc(sizeof(int) * 2)) == NULL ||
        (node = malloc(sizeof(stock_t))) == NULL)
        return (84);
    elem[0] = map->pos_i;
    elem[1] = map->pos_j;
    node->pos = elem;
    node->next = (*stock);
    (*stock) = node;
    (*stock)->prev = last_node;
    return (0);
}

int resolving_algo(map_t *map)
{
    int return_value = 0;
    stock_t *save_node;

    if (fill_stock(map, &map->stock) == 84)
        return (84);
    map->map[map->pos_i][map->pos_j] = 'P';
    for (int i = 0; (return_value = check_around(map)) != 1; i++) {
        if (return_value == 0) {
            save_node = map->stock;
            map->stock = map->stock->prev;
            free(save_node->pos);
            free(save_node);
            if (map->stock == NULL)
                break;
            map->map[map->pos_i][map->pos_j] = 'H';
            map->pos_i = map->stock->pos[0];
            map->pos_j = map->stock->pos[1];
        }
    }
    return (0);
}
