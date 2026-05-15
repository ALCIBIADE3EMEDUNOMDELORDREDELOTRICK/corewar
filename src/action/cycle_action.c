/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** cycle_action
*/

#include "../../include/header.h"

int detect_command(processus_t *proc, corewar_t *war, robot_t *robot, int stat)
{
    int action[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int (*func[])(corewar_t *, robot_t *, processus_t *, int) =
    {live, my_ld, my_st, add, sub, my_and, my_or, my_xor, zjmp, ldi,
        sti, my_fork, lld, lldi, lfork, print};

    for (int i = 0; i != 16; i++) {
        if (action[i] == war->arena[proc->pc]) {
            proc->new_pc = (proc->pc + 1) % MEM_SIZE;
            return func[i](war, robot, proc, proc->pc - 1);
        }
    }
    if (stat != 1)
        proc->pc = (proc->pc + 1) % MEM_SIZE;
    return SUCCESS_EXIT;
}

int do_command(processus_t *proc, corewar_t *war, robot_t *robot)
{
    int action[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int (*func[])(corewar_t *, robot_t *, processus_t *) =
    {do_live, do_ld, do_st, do_add, do_sub, do_and, do_or, do_xor, do_zjmp,
        do_ldi, NULL, do_fork, do_lld, do_lldi, do_lfork, do_print};

    for (int i = 0; i != 16; i++) {
        if (action[i] == proc->todo[0]) {
            func[i](war, robot, proc);
            return ALTERNATE;
        }
    }
    return SUCCESS_EXIT;
}

int choose_action(corewar_t *war, robot_t *robot)
{
    int status = 0;

    for (processus_t *tmp = robot->processus; tmp; tmp = tmp->next) {
        if (tmp->cycle > 0)
            tmp->cycle--;
        if (tmp->cycle == 0) {
            status = do_command(tmp, war, robot);
            detect_command(tmp, war, robot, status);
        }
    }
    return SUCCESS_EXIT;
}

int do_action(corewar_t *war)
{
    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next)
        choose_action(war, tmp->data);
    return SUCCESS_EXIT;
}
