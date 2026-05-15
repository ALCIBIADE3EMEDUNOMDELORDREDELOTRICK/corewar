/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** tools
*/

#include "../../include/header.h"

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
