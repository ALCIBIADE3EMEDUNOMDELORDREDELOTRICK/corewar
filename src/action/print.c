/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int print(corewar_t *war,
    robot_t *robot, processus_t *proc, int start_pc)
{
    int coding = war->arena[proc->new_pc];
    int args = 0;

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[0] = 16;
    if (get_arg_type(coding, 0) != 1)
        return SUCCESS_EXIT;
    args = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (args <= 0 || args > REG_NUMBER)
        return SUCCESS_EXIT;
    proc->todo[1] = args;
    proc->cycle = 2;
    return SUCCESS_EXIT;
}

int do_print(corewar_t *war, robot_t *robot, processus_t *proc)
{
    char c = proc->reg[proc->todo[1] - 1] % 256;

    write(1, &c, 1);
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
