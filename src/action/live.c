/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int live(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int id = read_bytes_arena(war->arena, proc->pc, 4);

    proc->cycle = 10;
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        if (((robot_t *)tmp->data)->id == id)
            my_printf("The player %d(%s)is alive.\n",
                ((robot_t *)tmp->data)->id, ((robot_t *)tmp->data)->name);
    proc->life = true;
    proc->since_last_live = war->current_cycle;
    war->nbr_live++;
    proc->pc = (proc->pc + 4) % MEM_SIZE;
    return SUCCESS_EXIT;
}
