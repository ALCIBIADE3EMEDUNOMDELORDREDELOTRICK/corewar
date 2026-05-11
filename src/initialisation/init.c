/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** init
*/

#include "../../include/header.h"

nodes_t *new_node(void *data)
{
    nodes_t *node = malloc(sizeof(nodes_t));

    if (!node)
        return NULL;
    node->next = NULL;
    node->data = data;
    return node;
}

nodes_t *new_robot(char *av, int id)
{
    robot_t *robot = malloc(sizeof(robot_t));

    if (!robot)
        return NULL;
    robot->id = id;
    robot->life = false;
    if (parsing(robot, av) != SUCCESS_EXIT) {
        free(robot);
        return NULL;
    }
    return new_node(robot);
}

int init_robot(char **av, corewar_t *war)
{
    int id = 0;
    nodes_t *node = NULL;

    war->robot = NULL;
    for (int i = 0; av[i] != NULL; i++) {
        if (av[i][0] == '-') {
            i += 2;
            continue;
        }
        node = new_robot(av[i], id);
        if (!node)
            return FAILURE;
        push_back(&war->robot, node);
        id++;
    }
    return SUCCESS_EXIT;
}

int init(corewar_t **war, char **av)
{
    *war = malloc(sizeof(corewar_t));
    if (!*war)
        return FAILURE;
    if (init_robot(av, *war) != SUCCESS_EXIT)
        return FAILURE;
    return SUCCESS_EXIT;
}
