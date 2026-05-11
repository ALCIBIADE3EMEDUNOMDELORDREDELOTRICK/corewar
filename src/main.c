/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main
*/

#include "../include/header.h"

int free_all(corewar_t *war)
{
    nodes_t *next;

    for (nodes_t *curr = war->robot; curr; curr = next) {
        next = curr->next;
        free(curr->data);
        free(curr);
    }
    free(war);
    return SUCCESS_EXIT;
}

int main(int ac, char **av)
{
    corewar_t *war = NULL;
    robot_t *rob = NULL;

    if (init(&war, av) != SUCCESS_EXIT || check_flag(war, ac, av) == -1)
        return FAILURE;
    for (nodes_t *curr = war->robot; curr; curr = curr->next) {
        rob = (robot_t *)curr->data;
        printf("%d\n", rob->id);
    }
    free_all(war);
    return SUCCESS_EXIT;
}
