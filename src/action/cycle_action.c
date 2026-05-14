/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** cycle_action
*/

#include "../../include/header.h"

int detect_command(processus_t *proc, corewar_t *war, robot_t *robot)
{
    int action[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int (*func[])(corewar_t *war, robot_t *robot, processus_t *proc) = {live};

    for (int i = 0; action[i] != 0; i++) {
        if (action[i] == war->arena[proc->pc])
            return func[i](war, robot, proc);
    }
    return SUCCESS_EXIT;
}

int choose_action(corewar_t *war, robot_t *robot)
{
    for (processus_t *tmp = robot->processus; tmp; tmp = tmp->next) {
        if (detect_command(tmp, war, robot) == FAILURE_EXIT)
            return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}

int do_action(corewar_t *war)
{
    int status = SUCCESS_EXIT;

    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        if (((robot_t *)tmp->data)->cycle != 0)
            ((robot_t *)tmp->data)->cycle--;
        if (((robot_t *)tmp->data)->cycle == 0)
            status = choose_action(war, tmp->data);
        if (status == FAILURE_EXIT)
            return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
