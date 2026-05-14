/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** live
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

int live(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int id = read_bytes_arena(war->arena, proc->pc, 4);

    proc->cycle = 10;
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        if (((robot_t *)tmp->data)->id == id)
            my_printf("The player %d(%s)is alive.\n",
                ((robot_t *)tmp->data)->id, ((robot_t *)tmp->data)->name);
    robot->life = true;
    proc->pc += 4;
    return SUCCESS_EXIT;
}
