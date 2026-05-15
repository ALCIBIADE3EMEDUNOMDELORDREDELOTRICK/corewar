/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

static int get_value(corewar_t *war, processus_t *proc, int type)
{
    int value = 0;

    if (type == 1) {
        value = read_bytes_arena(war->arena, proc->new_pc, 1);
        proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
        return proc->reg[value - 1];
    }
    if (type == 2) {
        value = read_bytes_arena(war->arena, proc->new_pc, DIR_SIZE);
        proc->new_pc = (proc->new_pc + DIR_SIZE) % MEM_SIZE;
        return value;
    }
    value = read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);
    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    return value;
}

int sti(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding = read_bytes_arena(war->arena, proc->new_pc, 1);

    proc->todo[0] = 11;
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[1] = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[2] = get_value(war, proc, get_arg_type(coding, 1));
    proc->todo[3] = get_value(war, proc, get_arg_type(coding, 2));
    proc->cycle = 25;
    return SUCCESS_EXIT;
}

int do_sti(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int addr = proc->pc + ((proc->todo[2] + proc->todo[3]) % IDX_MOD);

    reg_to_arena(war, proc, proc->todo[1] - 1, addr);
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
