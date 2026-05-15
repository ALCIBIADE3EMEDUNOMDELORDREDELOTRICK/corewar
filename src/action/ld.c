/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

static int direct(processus_t *proc, corewar_t *war, int start_pc)
{
    int args1 = read_bytes_arena(war->arena, proc->pc, 4);
    int args2 = 0;

    proc->pc = (proc->pc + 4) % MEM_SIZE;
    args2 = read_bytes_arena(war->arena, proc->pc, 1);
    proc->pc = (proc->pc + 1) % MEM_SIZE;
    proc->reg[args2 - 1] = args1;
    proc->carry = (proc->reg[args2 - 1] == 0);
    return SUCCESS_EXIT;
}

static int indirect(processus_t *proc, corewar_t *war, int start_pc)
{
    int args1 = read_bytes_arena(war->arena, proc->pc, 2);
    int args2 = 0;

    proc->pc = (proc->pc + 2) % MEM_SIZE;
    args2 = read_bytes_arena(war->arena, proc->pc, 1);
    proc->pc = (proc->pc + 1) % MEM_SIZE;
    proc->reg[args2 - 1] =
        read_bytes_arena(war->arena, start_pc + (args1 % IDX_MOD), 4);
    proc->carry = (proc->reg[args2 - 1] == 0);
    return SUCCESS_EXIT;
}

int my_ld(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding = war->arena[proc->pc];

    proc->pc = (proc->pc + 1) % MEM_SIZE;
    if (get_arg_type(coding, 0) == 2)
        return direct(proc, war, start_pc);
    return indirect(proc, war, start_pc);
}
