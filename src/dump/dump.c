/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** dump
*/

#include "../../include/header.h"

int print_reg(robot_t *robot, processus_t *reg)
{
    my_printf("  %s(%d): alive\n", robot->name, robot->id);
    for (int i = 1; i <= REG_NUMBER; i++) {
        if (i < 10)
            my_printf("    r%d : %08X", i, reg->reg[i - 1]);
        if (i >= 10)
            my_printf("    r%d: %08X", i, reg->reg[i - 1]);
        if (i % 6 == 0 && i != 0)
            my_printf("\n");
    }
    my_printf("\n");
    my_printf("    PC : %08x    carry: %d", reg->pc, reg->carry);
    my_printf("\n");
    return SUCCESS_EXIT;
}

int dump_robot(corewar_t *war)
{
    my_printf("Cycle: %d\n", war->cycle);
    my_printf("Registers:\n");
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        for (processus_t *reg =
                ((robot_t *)tmp->data)->processus; reg; reg = reg->next)
            print_reg(tmp->data, reg);
    my_printf("\n");
    return SUCCESS_EXIT;
}

int dump(corewar_t *war)
{
    dump_robot(war);
    my_printf("Memory:  ");
    for (int i = 0; i < 32; i++)
        my_printf(" %02X", i);
    my_printf("\n          -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- "
        "-- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n");
    my_printf("%08X: ", 0);
    for (int i = 0; i < MEM_SIZE; i++) {
        my_printf("%02X ", war->arena[i]);
        if (i + 1 == MEM_SIZE)
            my_printf("\n");
        if (i != 0 && (i + 1) % 32 == 0 && i + 1 != MEM_SIZE)
            my_printf("\n%08X: ", i + 1);
    }
    return SUCCESS_EXIT;
}
