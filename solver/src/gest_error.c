/*
** EPITECH PROJECT, 2019
** dante
** File description:
** gest_error
*/

#include "my.h"

int cond_error(int line, int first_loop, int max_line)
{
    first_loop == 0 ? max_line = line : 0;
    if (first_loop != 0 && line != max_line) {
        return (84);
    }
    first_loop++;
    line = 0;
    return (0);
}

int gest_error(char *buf)
{
    int line = 0;
    int max_line = 0;
    int first_loop = 0;
    int i;

    for (i = 0; buf[i] != '\0'; i++) {
        line++;
        if (buf[i] == '\n' && cond_error(line, first_loop, max_line))
            return (84);
        if (buf[i] != '*' && buf[i] != 'X' && buf[i] != '\n')
            return (84);
    }
    if (buf[i - 1] == '\n')
        return (84);
    return (0);
}
