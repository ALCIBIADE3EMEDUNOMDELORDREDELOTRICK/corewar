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

int check_flag_fct(int ac, char **av, int index)
{
    for (int i = 0; flag[i].name; i++) {
        if (my_strcmp(av[index], flag[i].name) != 0)
            continue;
        if (flag[i].fct(ac, av) == -1)
            return -1;
        return 1;
    }
    return 0;
}

int check_flag(int ac, char **av)
{
    int status = 0;
    int id = 1;

    for (int i = 1; av[i]; i++) {
        status = check_flag_fct(ac, av, i);
        if (status == 1)
            continue;
        if (status == -1 || !create_champion(NULL, av[i], id))
            return -1;
        id++;
    }
    return 0;
}
