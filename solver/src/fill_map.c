/*
** EPITECH PROJECT, 2019
** dante
** File description:
** fill_map
*/

#include "my.h"

int get_file_size(char **av)
{
    struct stat buf;

    stat(av[1], &buf);
    return (buf.st_size);
}

void last_cond(map_t *map, int column, int line)
{
    map->map[column + 1] = malloc(line + 3);
    for (int i = 0; i <= line; i++)
        map->map[column + 1][i] = '1';
    map->map[column + 1][line + 1] = '\n';
    map->map[column + 1][line + 2] = '\0';
    map->map[column + 2] = NULL;
    map->finish_i = column;
    map->finish_j = line;
}

void fill_in_map(map_t *map, char *buf, int column, int line)
{
    int k = 1;

    map->map = malloc(sizeof(char *) * (column + 3));
    map->map[0] = malloc(line + 30);
    for (int i = 0; i <= line; i++)
        map->map[0][i] = '1';
    map->map[0][line + 1] = '\n';
    map->map[0][line + 2] = '\0';
    for (int i = 0; buf[i] != '\0'; k++) {
        map->map[k] = malloc(line + 3);
        map->map[k][0] = '1';
        for (int j = 1; buf[i] != '\n' && buf[i] != '\0'; i++, j++)
            map->map[k][j] = buf[i];
        map->map[k][line + 1] = '\n';
        map->map[k][line + 2] = '\0';
        buf[i] != '\0' ? i++ : 0;
    }
    last_cond(map, column, line);
}

int annex_fill_map(char *buf, map_t *map)
{
    int column = 0;
    int line = 0;

    if (gest_error(buf) == 84)
        return (84);
    for (; buf[line] != '\n'; line++);
    for (int i = 0; buf[i] != '\0'; i++)
        buf[i] == '\n' ? column++ : 0;
    column++;
    fill_in_map(map, buf, column, line);
    map->finish = 0;
    map->pos_i = 1;
    map->pos_j = 1;
    return (0);
}

int fill_map(char **av, map_t *map)
{
    int fd = open(av[1], O_RDONLY);
    char *buf = NULL;
    int size;

    if (fd == -1)
        return (84);
    size = get_file_size(av);
    buf = malloc(size + 1);
    read(fd, buf, size);
    buf[size] = '\0';
    if (annex_fill_map(buf, map))
        return (84);
    if (map->map[1][1] == 'X') {
        printf("%s", "no solution found");
        return (84);
    }
    free(buf);
    return (0);
}
