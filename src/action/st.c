/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int regist(int reg, processus_t *proc, corewar_t *war)
{
    int reg2 = read_bytes_arena(war->arena, proc->new_pc, 1);

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (reg2 < 1 || reg2 > REG_NUMBER || reg < 1 || reg > REG_NUMBER) {
        reinit(proc);
        proc->pc = proc->new_pc;
        return SUCCESS_EXIT;
    }
    proc->todo[1] = reg;
    proc->todo[2] = reg2;
    proc->type[1] = 1;
    proc->cycle = 5;
    return SUCCESS_EXIT;
}

int indirect(int reg, processus_t *proc, corewar_t *war)
{
    int agrs2 = (int16_t)read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    proc->todo[1] = reg;
    proc->todo[2] = agrs2;
    proc->type[1] = 3;
    proc->cycle = 5;
    return SUCCESS_EXIT;
}

int my_st(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding_byte = read_bytes_arena(war->arena, proc->new_pc, 1);
    int reg = 0;

    proc->todo[0] = 3;
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    reg = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (get_arg_type(coding_byte, 1) == 1)
        return regist(reg, proc, war);
    if (get_arg_type(coding_byte, 1) == 3)
        return indirect(reg, proc, war);
    if (get_arg_type(coding_byte, 1) == 2)
        proc->new_pc = (proc->new_pc + DIR_SIZE) % MEM_SIZE;
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}

int do_st(corewar_t *war, robot_t *robot, processus_t *proc)
{
    if (proc->type[1] == 1)
        proc->reg[proc->todo[2] - 1] = proc->reg[proc->todo[1] - 1];
    if (proc->type[1] == 3)
        reg_to_arena(war, proc, proc->todo[1] - 1,
            proc->pc + proc->todo[2] % IDX_MOD);
    reinit(proc);
    proc->pc = proc->new_pc;
    return SUCCESS_EXIT;
}
