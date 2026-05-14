/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** die_cycle
*/

#include "../../include/header.h"

int check_all(nodes_t **begin)
{
    nodes_t *last = *begin;
    nodes_t *now = last->next;

    while (now != NULL) {
        if (((robot_t *)now->data)->life == false) {
            last->next = now->next;
            free_robot((*begin)->data);
            free(last);
            now = last->next;
            return 0;
        }
        ((robot_t *)now->data)->life = false;
        now = now->next;
        last = last->next;
    }
    return 1;
}

int delete_in_list(nodes_t **begin)
{
    nodes_t *last = *begin;

    if (!*begin)
        return 1;
    if (((robot_t *)(*begin)->data)->life == false) {
        *begin = last->next;
        free_robot((*begin)->data);
        free(last);
        return 0;
    }
    return check_all(begin);
}

int del(nodes_t *head)
{
    if (delete_in_list(&head) == 1)
        return 84;
    return 0;
}

int die(corewar_t *war)
{
    del(war->robot);
    war->cycle_to_die -= CYCLE_DELTA;
    war->current_cycle = 0;
    return SUCCESS_EXIT;
}
