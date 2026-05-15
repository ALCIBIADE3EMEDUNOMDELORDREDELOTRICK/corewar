/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

static int direct(processus_t *proc, corewar_t *war, int start_pc)
{
    int args1 = read_bytes_arena(war->arena, proc->new_pc, 4);
    int args2 = 0;

    proc->new_pc = (proc->new_pc + 4) % MEM_SIZE;
    args2 = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[1] = args1;
    proc->todo[2] = args2;
    proc->type[1] = 2;
    if (args2 - 1 > REG_NUMBER || args2 - 1 <= 0) {
        reinit(proc);
        return SUCCESS_EXIT;
    }
    proc->carry = (proc->reg[args2 - 1] == 0);
    proc->cycle = 5;
    return SUCCESS_EXIT;
}

static int indirect(processus_t *proc, corewar_t *war, int start_pc)
{
    int args1 = read_bytes_arena(war->arena, proc->new_pc, 2);
    int args2 = 0;

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    args2 = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[1] = args1;
    proc->todo[2] = args2;
    proc->type[1] = 3;
    if (args2 - 1 > REG_NUMBER || args2 - 1 <= 0) {
        reinit(proc);
        return SUCCESS_EXIT;
    }
    proc->carry = (proc->reg[args2 - 1] == 0);
    proc->cycle = 5;
    return SUCCESS_EXIT;
}

int my_ld(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding = war->arena[proc->new_pc];

    proc->todo[0] = 2;
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (get_arg_type(coding, 0) == 2)
        return direct(proc, war, start_pc);
    if (get_arg_type(coding, 0) == 3)
        return indirect(proc, war, start_pc);
    if (get_arg_type(coding, 0) == 1)
        proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    reinit(proc);
    proc->pc = (proc->new_pc + 1) % MEM_SIZE;
    return SUCCESS_EXIT;
}

int do_ld(corewar_t *war, robot_t *robot, processus_t *proc)
{
    if (proc->type[1] == 2)
        proc->reg[proc->todo[2] - 1] = proc->todo[1];
    if (proc->type[1] == 3)
        proc->reg[proc->todo[2] - 1] = read_bytes_arena(war->arena,
            (proc->pc + proc->todo[1]) % IDX_MOD, REG_SIZE);
    reinit(proc);
    proc->pc = proc->new_pc;
    return SUCCESS_EXIT;
}
