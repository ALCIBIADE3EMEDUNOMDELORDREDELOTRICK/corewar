/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** prog_a
*/

#include "../../include/header.h"

int prog_a(corewar_t *core, int id, char **av, int *index)
{
    int load = av[*index + 1] ? my_getnbr(av[*index + 1]) : -1;

    if (load < 0 || load > MEM_SIZE || !av[*index + 2])
        return -1;
    *index += 2;
    core->load = load;
    if (my_strcmp(av[*index], "-n") == 0)
        return prog_nb(core, id, av, index);
    return get_robot(core, av[*index], id);
}
