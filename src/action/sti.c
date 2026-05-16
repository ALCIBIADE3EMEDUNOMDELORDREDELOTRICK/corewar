/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** sti
*/

#include "../../include/header.h"

static int get_value(corewar_t *war, processus_t *proc,
    int type, int start_pc)
{
    int value = 0;

    if (type == 1) {
        value = read_bytes_arena(war->arena, proc->new_pc, 1);
        proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
        if (value < 1 || value > REG_NUMBER)
            return 0;
        return proc->reg[value - 1];
    }
    if (type == 2) {
        value = (int16_t)read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);
        proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
        return value;
    }
    value = (int16_t)read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);
    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    return (int16_t)read_bytes_arena(war->arena,
        (start_pc + (value % IDX_MOD)) % MEM_SIZE, IND_SIZE);
}

int sti(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding = read_bytes_arena(war->arena, proc->new_pc, 1);
    int reg = 0;

    if (get_arg_type(coding, 0) != 1)
        return SUCCESS_EXIT;
    if (get_arg_type(coding, 1) == 0 || get_arg_type(coding, 2) == 0)
        return SUCCESS_EXIT;
    proc->todo[0] = 11;
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    reg = read_bytes_arena(war->arena, proc->new_pc, 1);
    if (reg < 1 || reg > REG_NUMBER)
        return SUCCESS_EXIT;
    proc->todo[1] = reg;
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[2] = get_value(war, proc,
        get_arg_type(coding, 1), start_pc);
    proc->todo[3] = get_value(war, proc,
        get_arg_type(coding, 2), start_pc);
    proc->cycle = 25;
    return SUCCESS_EXIT;
}

int do_sti(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int addr = 0;

    addr = (proc->pc + ((proc->todo[2] + proc->todo[3]) % IDX_MOD)) % MEM_SIZE;
    reg_to_arena(war, proc, proc->todo[1] - 1, addr);
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
