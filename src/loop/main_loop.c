/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** main_loop
*/

#include "../../include/header.h"

static int active_robot_count(corewar_t *war)
{
    int count = 0;

    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        if (((robot_t *)tmp->data)->processus)
            count++;
    return count;
}

static int should_stop(corewar_t *war, int executed)
{
    if (war->cycle_to_die <= 0)
        return 1;
    if (war->cycle != -2 && active_robot_count(war) <= 1 && executed > 0)
        return 1;
    return 0;
}

int loop(corewar_t *war)
{
    int executed = 0;

    for (int i = -1; i != war->cycle; i++) {
        executed = do_action(war);
        if (executed == FAILURE_EXIT)
            return FAILURE_EXIT;
        if (should_stop(war, executed))
            break;
        war->current_cycle++;
        war->cycles_since_check++;
        if (war->cycles_since_check >= war->cycle_to_die)
            die(war);
    }
    if (war->cycle != -2)
        dump(war);
    print_win(war);
    free_all(war);
    return SUCCESS_EXIT;
}
