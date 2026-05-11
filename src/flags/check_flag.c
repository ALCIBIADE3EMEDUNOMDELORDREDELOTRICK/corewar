/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../../include/header.h"

const flag_t flag[] = {
    {"-h", print_help},
    {NULL, NULL}
};

int check_flag(int ac, char **av)
{
    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], flag->name) != 0)
            continue;
        if (flag->fct(ac, av) == -1)
            return -1;
    }
    return 0;
}
