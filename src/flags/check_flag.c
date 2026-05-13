/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../../include/header.h"

const flag_t flag[] = {
    {"-h", print_help},
    {"-n", prog_nb},
    {"-a", prog_a},
    {"-dump", nbr_cycle},
    {NULL, NULL}
};

int check_flag_fct(corewar_t *core, int id, char **av, int *index)
{
    int status = 0;

    for (int i = 0; flag[i].name; i++) {
        if (my_strcmp(av[*index], flag[i].name) == 0)
            status = flag[i].fct(core, id, av, index);
        if (status == -1)
            return -1;
        if (status != 0)
            return status;
    }
    if (get_robot(core, av[*index], id) != SUCCESS_EXIT)
        return -1;
    return 0;
}

int check_flag(corewar_t *core, int ac, char **av)
{
    int status = 0;
    int id = 1;

    for (int i = 1; av[i]; i++) {
        status = check_flag_fct(core, id, av, &i);
        if (status == 1)
            continue;
        if (status == -1)
            return -1;
        id++;
    }
    return 0;
}
