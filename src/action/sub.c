/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
*/

#include "../../include/header.h"

void error(bool *error, int coding_byte, processus_t *proc)
{
    int type = 0;

    for (int i = 0; i != 3; i++) {
        type = get_arg_type(coding_byte, i);
        if (type != 1)
            *error = true;
        if (type == 1)
            proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
        if (type == 2)
            proc->new_pc = (proc->new_pc + DIR_SIZE) % MEM_SIZE;
        if (type == 3)
            proc->new_pc = (proc->new_pc + IND_SIZE) % MEM_SIZE;
    }
    for (int i = 1; i != 4; i++)
        if (proc->todo[i] < 1 || proc->todo[i] > REG_NUMBER)
            *error = true;
}

int sub(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc)
{
    int coding_byte = read_bytes_arena(war->arena, proc->new_pc, 1);
    bool tests = false;

    proc->new_pc = (proc->new_pc + 1) % MEM_SIZE;
    proc->todo[0] = 5;
    proc->todo[1] = read_bytes_arena(war->arena, proc->new_pc, 1);
    proc->todo[2] = read_bytes_arena(war->arena, proc->new_pc + 1, 1);
    proc->todo[3] = read_bytes_arena(war->arena, proc->new_pc + 2, 1);
    proc->cycle = 10;
    error(&tests, coding_byte, proc);
    if (tests == true) {
        proc->cycle = 0;
        reinit(proc);
        proc->pc = proc->new_pc;
    }
    return SUCCESS_EXIT;
}

int do_sub(corewar_t *war, robot_t *robot, processus_t *proc)
{
    proc->reg[proc->todo[3] - 1] = proc->reg[proc->todo[1] - 1]
        - proc->reg[proc->todo[2] - 1];
    proc->carry = (proc->reg[proc->todo[3] - 1] == 0);
    reinit(proc);
    proc->pc = proc->new_pc;
    return SUCCESS_EXIT;
}
