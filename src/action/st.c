/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

int indirect(corewar_t *war, processus_t *proc, int start_pc, int reg)
{
    int value = read_bytes_arena(war->arena, proc->pc, IND_SIZE);

    proc->pc = (proc->pc + IND_SIZE) % MEM_SIZE;
    if (reg - 1 >= REG_NUMBER)
        return SUCCESS_EXIT;
    proc->cycle = 5;
    reg_to_arena(war, proc, reg, (start_pc + value) % IDX_MOD);
    return SUCCESS_EXIT;
}

int regist(corewar_t *war, processus_t *proc, int reg)
{
    int reg2 = read_bytes_arena(war->arena, proc->pc, 1);

    proc->pc = (proc->pc + 1) % MEM_SIZE;
    if (reg2 - 1 >= REG_NUMBER || reg - 1 >= REG_NUMBER)
        return SUCCESS_EXIT;
    proc->cycle = 5;
    proc->reg[reg2 - 1] = proc->reg[reg - 1];
    return SUCCESS_EXIT;
}

int my_st(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding_byte = read_bytes_arena(war->arena, proc->pc, 1);
    int reg = 0;

    proc->pc = (proc->pc + 1) % MEM_SIZE;
    reg = read_bytes_arena(war->arena, proc->pc, 1);
    proc->pc = (proc->pc + 1) % MEM_SIZE;
    if (get_arg_type(coding_byte, 1) == 1)
        return regist(war, proc, reg);
    if (get_arg_type(coding_byte, 1) == 3)
        return indirect(war, proc, start_pc, reg);
    return SUCCESS_EXIT;
}
