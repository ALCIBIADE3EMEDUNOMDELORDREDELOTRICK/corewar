/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** main_loop
*/

#include "../../include/header.h"

int loop(corewar_t *war)
{
    for (int i = 0; i != war->cycle; i++) {
        if (do_action(war) == FAILURE_EXIT)
            return FAILURE_EXIT;
        if (len_node(war->robot) <= 1 || war->cycle_to_die <= 0)
            break;
        war->current_cycle++;
        war->cycles_since_check++;
        if (war->cycles_since_check >= war->cycle_to_die)
            die(war);
    }
    if (war->cycle != -1)
        dump(war);
    print_win(war);
    free_all(war);
    return SUCCESS_EXIT;
}
