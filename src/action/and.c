/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

static int get_reg(corewar_t *war, processus_t *proc, int index, bool *error)
{
    int reg = read_bytes_arena(war->arena, proc->new_pc, 1);

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    if (reg < 1 || reg > 16) {
        *error = true;
        return SUCCESS_EXIT;
    }
    proc->todo[index] = proc->reg[reg - 1];
    return SUCCESS_EXIT;
}

static int get_dir(corewar_t *war, processus_t *proc, int index, bool *error)
{
    int dir = read_bytes_arena(war->arena, proc->new_pc, DIR_SIZE);

    proc->new_pc = (proc->new_pc + DIR_SIZE) % MEM_SIZE;
    proc->todo[index] = dir;
    return SUCCESS_EXIT;
}

static int get_indir(corewar_t *war, processus_t *proc, int index, bool *error)
{
    int indir = read_bytes_arena(war->arena, proc->new_pc, IND_SIZE);

    proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    proc->todo[index] = read_bytes_arena
        (war->arena, proc->pc + indir % IDX_MOD, IND_SIZE);
    return SUCCESS_EXIT;
}

static void take_argument(corewar_t *war, processus_t *proc,
    int coding_code, bool *error)
{
    int type = 0;

    for (int i = 1; i != 3; i++) {
        type = get_arg_type(coding_code, i - 1);
        if (type == 1) {
            get_reg(war, proc, i, error);
            continue;
        }
        if (type == 2) {
            get_dir(war, proc, i, error);
            continue;
        }
        if (type == 3) {
            get_indir(war, proc, i, error);
            continue;
        }
        *error = true;
    }
}

static void tests_reg(corewar_t *war, processus_t *proc,
    int coding_code, bool *error)
{
    int type = get_arg_type(coding_code, 2);

    if (type != 1)
        *error = true;
    if (type == 1) {
        proc->todo[3] = read_bytes_arena(war->arena, proc->new_pc, 1);
        proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
        return;
    }
    if (type == 2)
        proc->new_pc = (proc->new_pc + DIR_SIZE) % MEM_SIZE;
    if (type == 3)
        proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
}

int my_and(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding_code = read_bytes_arena(war->arena, proc->new_pc, 1);
    bool test = false;

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->cycle = 6;
    proc->todo[0] = 6;
    take_argument(war, proc, coding_code, &test);
    tests_reg(war, proc, coding_code, &test);
    if (test == true) {
        reinit(proc);
        proc->pc = proc->new_pc;
    }
    return SUCCESS_EXIT;
}

int do_and(corewar_t *war, robot_t *robot, processus_t *proc)
{
    proc->reg[proc->todo[3] - 1] = proc->todo[1] & proc->todo[2];
    proc->carry = (proc->reg[proc->todo[3] - 1] == 0);
    reinit(proc);
    proc->pc = proc->new_pc;
    return SUCCESS_EXIT;
}
