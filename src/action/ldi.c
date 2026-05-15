/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

static int get_reg(corewar_t *war, processus_t *proc, int *index)
{
    int reg = read_bytes_arena(war->arena, proc->new_pc, 1);

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (reg < 1 || reg > 16)
        return -1;
    for (int i = 1; index[i] != -1; i++)
        if (index[i] == 1)
            return -1;
    if (index[0] == 3)
        proc->todo[index[0]] = reg;
    else
        proc->todo[index[0]] = proc->reg[reg - 1];
    return SUCCESS_EXIT;
}

static int get_dir(corewar_t *war, processus_t *proc, int *index)
{
    int dir = read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    for (int i = 1; index[i] != -1; i++)
        if (index[i] == 2)
            return -1;
    proc->todo[index[0]] = dir;
    return SUCCESS_EXIT;
}

static int get_indir(corewar_t *war, processus_t *proc, int *index)
{
    int indir = read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    for (int i = 1; index[i] != -1; i++)
        if (index[i] == 3)
            return -1;
    proc->todo[index[0]] = read_bytes_arena(war->arena,
        proc->pc + indir % IDX_MOD, IND_SIZE);
    return SUCCESS_EXIT;
}

int take_argument(corewar_t *war, processus_t *proc,
    int coding_code, int *index)
{
    int type = 0;

    type = get_arg_type(coding_code, index[0] - 1);
    if (type == 1)
        return get_reg(war, proc, index);
    if (type == 2)
        return get_dir(war, proc, index);
    if (type == 3)
        return get_indir(war, proc, index);
    return -1;
}

int ldi(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding_byte = read_bytes_arena(war->arena, proc->new_pc, 1);
    bool test = false;

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->cycle = 25;
    proc->todo[0] = 10;
    if (take_argument(war, proc, coding_byte, (int[]){1, -1}) == -1)
        test = true;
    if (take_argument(war, proc, coding_byte, (int[]){2, 3, -1}) == -1)
        test = true;
    if (take_argument(war, proc, coding_byte, (int[]){3, 2, 3, -1}) == -1)
        test = true;
    if (test == true) {
        reinit(proc);
        proc->cycle = 0;
        proc->pc = proc->new_pc;
        return SUCCESS_EXIT;
    }
    return SUCCESS_EXIT;
}

int do_ldi(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int value = read_bytes_arena(war->arena,
        proc->pc + (proc->todo[1] + proc->todo[2]) % IDX_MOD, REG_SIZE);

    proc->reg[proc->todo[3] - 1] = value;
    proc->carry = (proc->reg[proc->todo[3] - 1] == 0);
    reinit(proc);
    proc->pc = proc->new_pc;
    return SUCCESS_EXIT;
}
