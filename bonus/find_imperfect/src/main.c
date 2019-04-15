/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (solver(av));
}
