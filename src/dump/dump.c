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
    my_printf("    PC : %08X    carry: %d", reg->pc, reg->carry);
    my_printf("\n");
    return SUCCESS_EXIT;
}

static processus_t *get_processus_at(robot_t *robot, int index)
{
    processus_t *proc = robot->processus;

    for (int i = 0; proc && i < index; i++)
        proc = proc->next;
    return proc;
}

static int dump_rank(corewar_t *war, int rank)
{
    processus_t *proc = NULL;
    int found = 0;

    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        proc = get_processus_at(tmp->data, rank);
        if (proc) {
            print_reg(tmp->data, proc);
            found = 1;
        }
    }
    return found;
}

int dump_robot(corewar_t *war)
{
    int cycle = war->cycle;

    if (war->current_cycle < war->cycle)
        cycle = war->current_cycle;
    if (cycle == 0 && war->cycle > 0)
        cycle = 1;
    my_printf("Cycle: %d\n", cycle);
    my_printf("Registers:\n");
    for (int rank = 0; dump_rank(war, rank); rank++);
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
        my_printf("%02X", war->arena[i]);
        if (i + 1 == MEM_SIZE)
            my_printf("\n");
        if ((i + 1) % 32 != 0)
            my_printf(" ");
        if (i != 0 && (i + 1) % 32 == 0 && i + 1 != MEM_SIZE)
            my_printf("\n%08X: ", i + 1);
    }
    return SUCCESS_EXIT;
}
