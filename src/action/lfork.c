/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int lfork(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int args = read_bytes_arena(war->arena, proc->new_pc, 2);

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    proc->todo[1] = args;
    proc->todo[0] = 15;
    proc->cycle = 999;
    return SUCCESS_EXIT;
}

int do_lfork(corewar_t *war, robot_t *robot, processus_t *proc)
{
    processus_t *new = create_processus(robot->id);

    if (!new)
        return FAILURE;
    new->carry = proc->carry;
    new->pc = (proc->pc + proc->todo[1] + MEM_SIZE) % MEM_SIZE;
    new->next = robot->processus;
    robot->processus = new;
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
