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
        do_ldi, do_sti, do_fork, do_lld, do_lldi, do_lfork, do_print};

    for (int i = 0; i != 16; i++) {
        if (action[i] == proc->todo[0]) {
            func[i](war, robot, proc);
            return ALTERNATE;
        }
    }
    return SUCCESS_EXIT;
}

static int process_action(corewar_t *war, robot_t *robot, processus_t *proc)
{
    int status = 0;

    if (proc->cycle > 0)
        proc->cycle--;
    if (proc->cycle == 0) {
        status = do_command(proc, war, robot);
        detect_command(proc, war, robot, status);
    }
    return status == ALTERNATE;
}

static processus_t *get_processus_at(robot_t *robot, int index)
{
    processus_t *proc = robot->processus;

    for (int i = 0; proc && i < index; i++)
        proc = proc->next;
    return proc;
}

static int process_rank(corewar_t *war, int rank, int *executed)
{
    processus_t *proc = NULL;
    int found = 0;

    for (nodes_t *tmp = war->robot; tmp; tmp = tmp->next) {
        proc = get_processus_at(tmp->data, rank);
        if (proc) {
            *executed += process_action(war, tmp->data, proc);
            found = 1;
        }
    }
    return found;
}

int do_action(corewar_t *war)
{
    int executed = 0;

    for (int rank = 0; process_rank(war, rank, &executed); rank++);
    return executed;
}
