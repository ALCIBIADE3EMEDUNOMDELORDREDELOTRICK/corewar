/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** tools
*/

#include "../../include/header.h"

void reinit(processus_t *proc)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        proc->type[i] = 0;
        proc->todo[i] = 0;
    }
}

int read_bytes_arena(unsigned char arena[MEM_SIZE], int pc, int size)
{
    int value = 0;

    for (int i = 0; i < size; i++) {
        value <<= 8;
        value |= arena[(pc + i) % MEM_SIZE];
    }
    return value;
}

int get_arg_type(unsigned char cb, int arg_num)
{
    return (cb >> (6 - 2 * arg_num)) & 0b11;
}

int reg_to_arena(corewar_t *war, processus_t *proc, int reg_idx, int addr)
{
    int value = proc->reg[reg_idx];

    for (int i = 0; i < REG_SIZE; i++) {
        war->arena[(addr + i) % MEM_SIZE] =
            (value >> (8 * (REG_SIZE - 1 - i))) & 0xFF;
    }
    return SUCCESS_EXIT;
}

int get_arg(corewar_t *war, processus_t *proc, int type)
{
    int value;

    if (type == 1) {
        value = war->arena[proc->pc] - 1;
        proc->pc = (proc->pc + 1) % MEM_SIZE;
        return proc->reg[value];
    }
    if (type == 2) {
        value = read_bytes_arena(war->arena, proc->pc, 4);
        proc->pc = (proc->pc + 4) % MEM_SIZE;
        return value;
    }
    if (type == 3) {
        value = read_bytes_arena(war->arena, proc->pc, 2);
        proc->pc = (proc->pc + 2) % MEM_SIZE;
        return read_bytes_arena(war->arena,
            (proc->pc + (value % IDX_MOD)) % MEM_SIZE, 4);
    }
    return 0;
}
