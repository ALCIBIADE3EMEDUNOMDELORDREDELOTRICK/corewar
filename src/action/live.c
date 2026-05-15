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

    proc->todo[0] = 1;
    proc->todo[1] = id;
    proc->new_pc = (proc->new_pc + 4) % MEM_SIZE;
    proc->cycle = 10;
    return SUCCESS_EXIT;
}

int do_live(corewar_t *war, robot_t *robot, processus_t *proc)
{
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        if (((robot_t *)tmp->data)->id == proc->todo[1])
            my_printf("The player %d(%s)is alive.\n",
                ((robot_t *)tmp->data)->id, ((robot_t *)tmp->data)->name);
    reinit(proc);
    proc->life = true;
    proc->since_last_live = war->current_cycle;
    proc->pc = proc->new_pc;
    war->nbr_live++;
    return SUCCESS_EXIT;
}
