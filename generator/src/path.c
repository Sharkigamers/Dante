/*
** EPITECH PROJECT, 2019
** dante
** File description:
** path
*/

#include "my.h"

int check_more(map_t *map, int i, int j)
{
    int check = 0;

    map->map[i][j + 1] == '*' ? check++ : 0;
    map->map[i][j - 1] == '*' ? check++ : 0;
    map->map[i + 1][j] == '*' ? check++ : 0;
    map->map[i - 1][j] == '*' ? check++ : 0;
    if (check <= 1) {
        map->pos_i = i;
        map->pos_j = j;
    } else
        map->map[i][j] = 'X';
    return (check);
}

int check_around_next(map_t *map, int ac, char **av)
{
    if (ac == 4) {
        if (map->map[map->pos_i][map->pos_j + 1] == 'P')
            return (check_more(map, map->pos_i, map->pos_j + 1));
        if (map->map[map->pos_i][map->pos_j - 1] == 'P')
            return (check_more(map, map->pos_i, map->pos_j - 1));
        if (map->map[map->pos_i + 1][map->pos_j] == 'P')
            return (check_more(map, map->pos_i + 1, map->pos_j));
        if (map->map[map->pos_i - 1][map->pos_j] == 'P')
            return (check_more(map, map->pos_i - 1, map->pos_j));
    }
    if (ac == 3)
        return (check_arout_next_imperfect(map, av));
    return (5);
}

int check_around(map_t *map, int ac, char **av)
{
    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    int pos4 = 0;
    int tot = 0;
    int res = 5;

    map->map[map->pos_i][map->pos_j + 1] == '0' ? pos1 = tot += 1 : 0;
    map->map[map->pos_i][map->pos_j - 1] == '0' ? pos2 = tot += 1 : 0;
    map->map[map->pos_i + 1][map->pos_j] == '0' ? pos3 = tot += 1 : 0;
    map->map[map->pos_i - 1][map->pos_j] == '0' ? pos4 = tot += 1 : 0;
    tot != 0 ? res = rand() % tot + 1 : 0;
    res == pos1 ? map->map[map->pos_i][map->pos_j + 1] = 'P' : 0;
    res == pos2 ? map->map[map->pos_i][map->pos_j - 1] = 'P' : 0;
    res == pos3 ? map->map[map->pos_i + 1][map->pos_j] = 'P' : 0;
    res == pos4 ? map->map[map->pos_i - 1][map->pos_j] = 'P' : 0;
    if ((res = check_around_next(map, ac, av)) > 1 || res == 5)
        return (res);
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

int create_path(map_t *map, int ac, char **av)
{
    int return_value = 0;
    stock_t *save_node;

    if (fill_stock(map, &map->stock) == 84)
        return (84);
    map->map[map->pos_i][map->pos_j] = '*';
    for (int i = 0; (return_value = check_around(map, ac, av)) != 0; i++) {
        if (return_value == 5) {
            save_node = map->stock;
            map->stock = map->stock->prev;
            free(save_node->pos);
            free(save_node);
            if (map->stock == NULL)
                break;
            map->pos_i = map->stock->pos[0];
            map->pos_j = map->stock->pos[1];
        }
    }
    return (0);
}
