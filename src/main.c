/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main
*/

#include "../include/header.h"

int free_all(corewar_t *war)
{
    free(war);
    return SUCCESS_EXIT;
}

int main(int ac, char **av)
{
    corewar_t *war = NULL;

    if (check_flag(ac, av) == -1)
        return 84;
    if (init(&war, av) != SUCCESS_EXIT)
        return FAILURE;
    free_all(war);
    return SUCCESS_EXIT;
    return 0;
}
