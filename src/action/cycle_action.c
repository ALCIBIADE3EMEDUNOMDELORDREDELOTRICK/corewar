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
    int (*func[])(corewar_t *, robot_t *, processus_t *, int) =
    {live, my_ld, my_st, add, sub, my_and, my_or, my_xor, zjmp, ldi,
        sti, my_fork, lld, lldi, lfork, print};

    for (int i = 0; i != 16; i++) {
        if (action[i] == war->arena[proc->pc]) {
            proc->pc = (proc->pc + 1) % MEM_SIZE;
            return func[i](war, robot, proc, proc->pc - 1);
        }
    }
    proc->pc = (proc->pc + 1) % MEM_SIZE;
    return SUCCESS_EXIT;
}

int choose_action(corewar_t *war, robot_t *robot)
{
    int status = -1;

    for (processus_t *tmp = robot->processus; tmp; tmp = tmp->next) {
        if (tmp->cycle > 0)
            tmp->cycle--;
        if (tmp->cycle == 0)
            status = detect_command(tmp, war, robot);
        if (status == FAILURE_EXIT)
            return status;
    }
    return SUCCESS_EXIT;
}

int do_action(corewar_t *war)
{
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        if (choose_action(war, tmp->data) == FAILURE_EXIT)
            return FAILURE_EXIT;
    }
    return SUCCESS_EXIT;
}
