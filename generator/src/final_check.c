/*
** EPITECH PROJECT, 2019
** dante
** File description:
** final_check
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *my_strstartdup(char *src, int i)
{
    char *str = malloc(strlen(src) + 1);
    int k;

    for (k = 0; src[i] != '\0'; i++, k++) {
        src[i] == '0' ? src[i] = 'X' : 0;
        str[k] = src[i];
    }
    str[k] = '\0';
    return (str);
}

void print(map_t *map, char **av)
{
    char *final_write;
    int j = atoi(av[2]) + 1;
    int k = atoi(av[1]);

    for (int i = 1; map->map[i + 1] != NULL; i++) {
        map->map[i][j] = '\n';
        i == k && map->map[i][j] == '\n' ?
            map->map[i][j] = '\0' : 0;
        final_write = my_strstartdup(map->map[i], 1);
        write(1, final_write, strlen(final_write));
        free(final_write);
    }
}

void check_blocus(map_t *map, char **av)
{
    if (map->map[atoi(av[1])][atoi(av[2])] == '*' &&
        map->map[atoi(av[1]) - 1][atoi(av[2])] == '*' &&
        map->map[atoi(av[1])][atoi(av[2]) - 1] == '*' &&
        map->map[atoi(av[1]) - 1][atoi(av[2]) - 1] == '*')
        map->map[atoi(av[1]) - 1][atoi(av[2]) - 1] = 'X';
}

int final_check(map_t *map, char **av)
{
    if ((map->map[atoi(av[1])][atoi(av[2]) - 1] == 'X' ||
        map->map[atoi(av[1])][atoi(av[2]) - 1] == '0') &&
        (map->map[atoi(av[1]) - 1][atoi(av[2])] == 'X' ||
        map->map[atoi(av[1]) - 1][atoi(av[2])] == '0')) {
        for (int i = 1; (map->map[atoi(av[1])][atoi(av[2]) - i] == 'X' ||
            map->map[atoi(av[1])][atoi(av[2]) - i] == '0') && i > 0; i++)
            map->map[atoi(av[1])][atoi(av[2]) - i] = '*';
    }
    map->map[atoi(av[1])][atoi(av[2])] = '*';
    check_blocus(map, av);
    print(map, av);
    return (0);
}
