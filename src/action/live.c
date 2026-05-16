/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int live(corewar_t *war, robot_t *robot,
    processus_t *proc, int start_pc)
{
    int id = 0;

    id = read_bytes_arena(
        war->arena,
        proc->new_pc,
        4
    );
    proc->todo[0] = 1;
    proc->todo[1] = id;
    proc->new_pc = (proc->new_pc + 4) % MEM_SIZE;
    proc->cycle = 10;
    return SUCCESS_EXIT;
}

int do_live(corewar_t *war, robot_t *robot, processus_t *proc)
{
    robot_t *found = NULL;
    robot_t *r = NULL;

    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        r = tmp->data;
        if (r->id == proc->todo[1]) {
            found = r;
            my_printf("The player %d(%s)is alive.\n",
                r->id, r->name);
            break;
        }
    }
    proc->life = true;
    proc->since_last_live = war->current_cycle;
    if (found)
        found->since_last_live = war->current_cycle;
    proc->pc = proc->new_pc;
    reinit(proc);
    war->nbr_live++;
    return SUCCESS_EXIT;
}
