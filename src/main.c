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
    int tmp_adress = 0;

    if (len == 0)
        return FAILURE_EXIT;
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        tmp_adress = load_address;
        load_address = ((robot_t *)tmp->data)->load != -1 ?
            ((robot_t *)tmp->data)->load : load_address;
        for (int i = 0; i < ((robot_t *)tmp->data)->size; i++)
            war->arena[(load_address + i) % MEM_SIZE]
        = ((robot_t *)tmp->data)->code[i];
        ((robot_t *)tmp->data)->processus->pc = load_address;
        load_address = tmp_adress;
        load_address += MEM_SIZE / len;
    }
    return SUCCESS_EXIT;
}

int main(int ac, char **av)
{
    corewar_t *war = NULL;

    if (init(&war, av) != SUCCESS_EXIT || check_flag(war, ac, av) == -1)
        return FAILURE_EXIT;
    war->robot = my_sort_id_r(war->robot);
    placement_in_arena(war);
    return loop(war);
}
