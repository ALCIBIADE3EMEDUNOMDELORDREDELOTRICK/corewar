/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int add(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding_byte = read_bytes_arena(war->arena, proc->new_pc, 1);
    bool tests = false;

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[0] = 4;
    proc->todo[1] = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->todo[2] = read_bytes_arena(war->arena, proc->new_pc + 1, 1);
    proc->todo[3] = read_bytes_arena(war->arena, proc->new_pc + 2, 1);
    proc->cycle = 10;
    error(&tests, coding_byte, proc);
    if (tests == true) {
        proc->cycle = 0;
        reinit(proc);
        proc->pc = start_pc;
    }
    return SUCCESS_EXIT;
}

int do_add(corewar_t *war, robot_t *robot, processus_t *proc)
{
    proc->reg[proc->todo[3] - 1] = proc->reg[proc->todo[1] - 1]
        + proc->reg[proc->todo[2] - 1];
    reinit(proc);
    proc->pc = proc->new_pc;
    return SUCCESS_EXIT;
}
