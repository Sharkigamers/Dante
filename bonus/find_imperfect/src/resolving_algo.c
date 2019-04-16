/*
** EPITECH PROJECT, 2019
** dante
** File description:
** resolving_algo
*/

#include "my.h"

int check_failed(map_t *map, int i, int j)
{
    int check = 0;

    map->map[i][j + 1] == 'P' || map->map[i][j + 1] == 'H' ? check++ : 0;
    map->map[i][j - 1] == 'P' || map->map[i][j - 1] == 'H' ? check++ : 0;
    map->map[i + 1][j] == 'P' || map->map[i + 1][j] == 'H' ? check++ : 0;
    map->map[i - 1][j] == 'P' || map->map[i - 1][j] == 'H' ? check++ : 0;
    if (check <= 1) {
        map->pos_i = i;
        map->pos_j = j;
    } else {
        map->error++;
        printf("%d   %d\n", i, j);
    }
    return (check);
}

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

void annex_linked_list(map_t *map, stock_t *save_node)
{
    save_node = map->stock;
    map->stock = map->stock->prev;
    free(save_node->pos);
    free(save_node);
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
            annex_linked_list(map, save_node);
            if (map->stock == NULL)
                break;
            map->map[map->pos_i][map->pos_j] = 'H';
            map->pos_i = map->stock->pos[0];
            map->pos_j = map->stock->pos[1];
        }
    }
    if (return_value != 0) {
        check_failed(map, map->pos_i, map->pos_j);
    }
    return (0);
}
