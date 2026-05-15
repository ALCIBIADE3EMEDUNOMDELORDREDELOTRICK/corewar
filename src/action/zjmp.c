/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int zjmp(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int value = read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    if (proc->pc == 0) {
        reinit(proc);
        proc->pc = proc->new_pc;
        return SUCCESS_EXIT;
    }
    proc->todo[0] = 9;
    proc->todo[1] = value;
    proc->cycle = 20;
    return SUCCESS_EXIT;
}

int do_zjmp(corewar_t *war, robot_t *robot, processus_t *proc)
{
    proc->pc += proc->todo[1];
    reinit(proc);
    return SUCCESS_EXIT;
}
