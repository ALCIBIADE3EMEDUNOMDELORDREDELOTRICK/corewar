/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int zjmp(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int value = 0;

    value = (int16_t)read_bytes_arena(
        war->arena,
        proc->new_pc,
        IND_SIZE
    );
    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    proc->todo[0] = 9;
    proc->todo[1] = value;
    proc->cycle = 20;
    return SUCCESS_EXIT;
}

int do_zjmp(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int offset = 0;

    if (proc->carry == 1) {
        offset = proc->todo[1] % IDX_MOD;
        proc->pc = (proc->pc + offset + MEM_SIZE) % MEM_SIZE;
    } else
        proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
