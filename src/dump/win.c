/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** win
*/

#include "../../include/header.h"

int print_win(corewar_t *war)
{
    if (len_node(war->robot) == 0) {
        my_printf("No player has won.\n");
        return 0;
    }
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        my_printf("The player %d(%s)has won.\n",
            ((robot_t *)tmp->data)->id, ((robot_t *)tmp->data)->name);
    return SUCCESS_EXIT;
}
