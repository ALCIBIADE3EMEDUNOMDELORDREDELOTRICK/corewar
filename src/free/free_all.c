/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** free_all
*/

#include "../../include/header.h"

void free_node(nodes_t *head, void func(void *data))
{
    nodes_t *next;

    for (nodes_t *curr = head; curr; curr = next) {
        next = curr->next;
        func(curr->data);
        free(curr);
    }
}

void free_proc(processus_t *head)
{
    processus_t *next;

    for (processus_t *curr = head; curr; curr = next) {
        next = curr->next;
        free(curr);
    }
}

void free_robot(void *data)
{
    robot_t *robot = data;

    free(robot->name);
    free(robot->code);
    free_proc(robot->processus);
    free(robot);
}

int free_all(corewar_t *war)
{
    free_node(war->robot, free_robot);
    free(war);
    return SUCCESS_EXIT;
}
