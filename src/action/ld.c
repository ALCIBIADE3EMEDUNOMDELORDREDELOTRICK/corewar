/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** ld
*/

#include "../../include/header.h"

static int direct(corewar_t *war, processus_t *proc)
{
    int value = 0;

    value = (int32_t)read_bytes_arena(war->arena,
        proc->new_pc, 4);
    proc->new_pc = (proc->new_pc + 4) % MEM_SIZE;
    proc->todo[1] = value;
    proc->type[1] = 2;
    return SUCCESS_EXIT;
}

static int indirect(corewar_t *war, processus_t *proc, int start_pc)
{
    int offset = 0;
    int addr = 0;
    int value = 0;

    offset = (int16_t)read_bytes_arena(war->arena, proc->new_pc, 2);
    proc->new_pc = (proc->new_pc + 2) % MEM_SIZE;
    addr = (start_pc + (offset % IDX_MOD) + MEM_SIZE) % MEM_SIZE;
    value = read_bytes_arena(war->arena, addr, 4);
    proc->todo[1] = value;
    proc->type[1] = 3;
    return SUCCESS_EXIT;
}

static int get_register(corewar_t *war, processus_t *proc)
{
    int reg = 0;

    reg = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (reg < 1 || reg > REG_NUMBER)
        return SUCCESS_EXIT;
    proc->todo[2] = reg;
    return SUCCESS_EXIT;
}

int my_ld(corewar_t *war, robot_t *robot,
    processus_t *proc, int start_pc)
{
    int coding = 0;
    int type = 0;

    coding = war->arena[proc->new_pc];
    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[0] = 2;
    type = get_arg_type(coding, 0);
    if (type == 2)
        direct(war, proc);
    else if (type == 3)
        indirect(war, proc, start_pc);
    get_register(war, proc);
    proc->cycle = 5;
    return SUCCESS_EXIT;
}

int do_ld(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int value = 0;
    int reg = proc->todo[2] - 1;

    value = proc->todo[1];
    proc->reg[reg] = value;
    proc->carry = (value == 0);
    proc->pc = proc->new_pc;
    reinit(proc);
    return SUCCESS_EXIT;
}
