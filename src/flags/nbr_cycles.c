/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../../include/header.h"

int nbr_cycle(corewar_t *core, int ac, char **av, int *index)
{
    int cycle = av[*index + 1] ? my_getnbr(av[*index + 1]) : -1;

    if (cycle <= 0)
        return -1;
    core->cycle = cycle;
    *index += 1;
    return 0;
}
