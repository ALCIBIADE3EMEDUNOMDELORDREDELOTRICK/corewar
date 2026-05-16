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

void append_processus(processus_t **begin, processus_t *new)
{
    processus_t *last = *begin;

    if (!*begin) {
        *begin = new;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = new;
}

int read_bytes_arena(unsigned char arena[MEM_SIZE], int pc, int size)
{
    int value = 0;
    int addr = 0;

    for (int i = 0; i < size; i++) {
        addr = (pc + i) % MEM_SIZE;
        if (addr < 0)
            addr += MEM_SIZE;
        value <<= 8;
        value |= arena[addr];
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
    int real_addr = 0;

    for (int i = 0; i < REG_SIZE; i++) {
        real_addr = (addr + i) % MEM_SIZE;
        if (real_addr < 0)
            real_addr += MEM_SIZE;
        war->arena[real_addr] = (value >> (8 * (REG_SIZE - 1 - i))) & 0xFF;
    }
    return SUCCESS_EXIT;
}
