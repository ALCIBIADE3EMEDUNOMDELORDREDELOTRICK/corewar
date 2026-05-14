/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** win
*/

#include "../../include/header.h"

int print_win(corewar_t *war)
{
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        my_printf("The player %d(%s)has won.\n",
            ((robot_t *)tmp->data)->id, ((robot_t *)tmp->data)->name);
    return SUCCESS_EXIT;
}
