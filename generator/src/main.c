/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

int sec_gest_error_from_args(char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < '0' || av[1][i] > '9') {
            write(2, "Error: size should contain only number.\n", 40);
            return (84);
        }
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < '0' || av[2][i] > '9') {
            write(2, "Error: size should contain only number.\n", 40);
            return (84);
        }
    }
    return (0);
}

int gest_error_from_args(int ac, char **av)
{
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0) {
        write(2, "Error: incompatible size (>0).\n", 31);
        return (84);
    }
    if (ac == 4 && strcmp(av[3], "perfect") != 0) {
        write(2, "Error: only nothing or 'perfect' can be enter.\n", 47);
        return (84);
    }
    if (sec_gest_error_from_args(av) == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (84);
    if (gest_error_from_args(ac, av) == 84)
        return (84);
    generator(av, ac);
    return (0);
}
