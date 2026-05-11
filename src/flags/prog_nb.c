/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../../include/header.h"

int prog_nb(corewar_t *core, int ac, char **av, int *index)
{
    int id = av[*index + 1] ? my_getnbr(av[*index + 1]) : -1;

    if (id <= 0 || !av[*index + 2] ||
        !create_champion(core, av[*index + 2], id))
        return -1;
    *index += 2;
    return 0;
}
