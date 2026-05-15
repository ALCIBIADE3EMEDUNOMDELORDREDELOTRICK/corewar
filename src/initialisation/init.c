/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** init
*/

#include "../../include/header.h"

int init(corewar_t **war, char **av)
{
    *war = malloc(sizeof(corewar_t));
    if (!*war)
        return FAILURE;
    for (int i = 0; i != MEM_SIZE; i++)
        (*war)->arena[i] = 0;
    (*war)->robot = NULL;
    (*war)->cycle = -1;
    (*war)->load = -1;
    (*war)->cycle_to_die = CYCLE_TO_DIE;
    (*war)->current_cycle = 0;
    (*war)->nbr_live = 0;
    (*war)->check = 0;
    return SUCCESS_EXIT;
}
