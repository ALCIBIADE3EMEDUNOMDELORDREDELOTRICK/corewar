/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int my_fork(corewar_t *war, robot_t *robot,
    processus_t *proc, int start_pc)
{
    int offset = 0;

    offset = (int16_t)read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);
    proc->todo[0] = 12;
    proc->todo[1] = offset;
    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    proc->cycle = 800;
    return SUCCESS_EXIT;
}

int do_fork(corewar_t *war, robot_t *robot, processus_t *proc)
{
    processus_t *new = NULL;

    new = create_processus(robot->id);
    if (!new)
        return FAILURE;
    new->carry = proc->carry;
    new->life = proc->life;
    new->since_last_live = war->current_cycle;
    for (int i = 0; i < REG_NUMBER; i++)
        new->reg[i] = proc->reg[i];
    new->pc = (proc->pc +
        (proc->todo[1] % IDX_MOD) +
        MEM_SIZE) % MEM_SIZE;
    new->new_pc = new->pc;
    append_processus(&robot->processus, new);
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
