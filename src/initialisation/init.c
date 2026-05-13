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
    (*war)->robot = NULL;
    (*war)->cycle = -1;
    (*war)->load = -1;
    return SUCCESS_EXIT;
}
