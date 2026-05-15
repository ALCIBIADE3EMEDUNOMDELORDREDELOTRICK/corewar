/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** die_cycle
*/

#include "../../include/header.h"

static int check_all_processus(corewar_t *war, processus_t **begin)
{
    processus_t *last = *begin;
    processus_t *now = last->next;

    while (now != NULL) {
        if (war->current_cycle - now->since_last_live >= war->cycle_to_die) {
            last->next = now->next;
            free(now);
            now = last->next;
            continue;
        }
        now = now->next;
        last = last->next;
    }
    return 1;
}

static int delete_processus(corewar_t *war, processus_t **begin)
{
    processus_t *last = *begin;

    if (!*begin)
        return 1;
    while (*begin && war->current_cycle -
        (*begin)->since_last_live >= war->cycle_to_die) {
        if (war->current_cycle -
            (*begin)->since_last_live >= war->cycle_to_die) {
            *begin = last->next;
            free(last);
            last = *begin;
        }
    }
    return check_all_processus(war, begin);
}

static int check_all(nodes_t **begin)
{
    nodes_t *last = *begin;
    nodes_t *now = last->next;

    while (now != NULL) {
        if (((robot_t *)(now)->data)->processus == NULL) {
            last->next = now->next;
            free_robot(now->data);
            free(now);
            now = last->next;
            continue;
        }
        now = now->next;
        last = last->next;
    }
    return 1;
}

static int delete_in_list(nodes_t **begin)
{
    nodes_t *last = *begin;

    if (!*begin)
        return 1;
    while (*begin && ((robot_t *)(*begin)->data)->processus == NULL) {
        if (((robot_t *)(*begin)->data)->processus == NULL) {
            *begin = last->next;
            free_robot(last->data);
            free(last);
            last = *begin;
        }
    }
    if (*begin == NULL)
        return 0;
    return check_all(begin);
}

int die(corewar_t *war)
{
    if (war->nbr_live >= NBR_LIVE || war->check >= MAX_CHECK) {
        war->cycle_to_die -= CYCLE_DELTA;
        war->check = 0;
    } else
        war->check++;
    war->nbr_live = 0;
    war->cycles_since_check = 0;
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        delete_processus(war, &((robot_t *)(tmp->data))->processus);
    delete_in_list(&war->robot);
    return SUCCESS_EXIT;
}
