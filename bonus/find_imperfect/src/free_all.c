/*
** EPITECH PROJECT, 2019
** dante
** File description:
** free_all
*/

#include "my.h"

void free_all(map_t *map)
{
    stock_t *save_node;

    for (int i = 0; map->map[i] != NULL; i++)
        free(map->map[i]);
    free(map->map);
    while (map->stock != NULL) {
        save_node = map->stock;
        map->stock = map->stock->prev;
        free(save_node->pos);
        free(save_node);
    }
}
