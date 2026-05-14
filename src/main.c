/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** main
*/

#include "../include/header.h"

int placement_in_arena(corewar_t *war)
{
    int len = len_node(war->robot);
    int load_address = 0;

    if (len == 0)
        return FAILURE_EXIT;
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        for (int i = 0; i < ((robot_t *)tmp->data)->size; i++)
            war->arena[(load_address + i) % MEM_SIZE]
        = ((robot_t *)tmp->data)->code[i];
        ((robot_t *)tmp->data)->processus->pc = load_address;
        load_address += MEM_SIZE / len;
    }
    return SUCCESS_EXIT;
}

int loop(corewar_t *war)
{
    for (int i = 0; i != war->cycle; i++) {
        if (len_node(war->robot) <= 1)
            break;
        war->current_cycle++;
    }
    if (war->cycle != -1)
        dump(war);
    print_win(war);
    free_all(war);
    return SUCCESS_EXIT;
}

int main(int ac, char **av)
{
    corewar_t *war = NULL;

    if (init(&war, av) != SUCCESS_EXIT || check_flag(war, ac, av) == -1)
        return FAILURE_EXIT;
    placement_in_arena(war);
    return loop(war);
}
