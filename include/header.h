/*
** EPITECH PROJECT, 2026
** robot_factory
** File description:
** header
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "op.h"
#include "my.h"

#ifndef HEADER_H
    #define HEADER_H

typedef enum {
    SUCCESS_EXIT,
    ALTERNATE,
    FAILURE = -1,
    FAILURE_EXIT = 84
} exit_t;

typedef struct processus {
    bool life;
    int pc;
    int carry;
    int reg[REG_NUMBER];
    int id;
    int cycle;
    int todo[MAX_ARGS_NUMBER];
    int type[MAX_ARGS_NUMBER];
    int new_pc;
    int since_last_live;
    struct processus *next;
} processus_t;

typedef struct robot {
    char *name;
    int id;
    int size;
    unsigned char *code;
    int load;
    processus_t *processus;
} robot_t;

typedef struct corewar {
    nodes_t *robot;
    unsigned char arena[MEM_SIZE];
    int load;
    int cycle;
    int cycles_since_check;
    int current_cycle;
    int nbr_live;
    int cycle_to_die;
    int check;
} corewar_t;

typedef int (*fct_t)(corewar_t *core, int *id, char **av, int *index);

typedef struct flag_s {
    char *name;
    fct_t fct;
} flag_t;

int add(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int my_and(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
char *get_file(const char *filename);
int zjmp(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int sub(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int my_st(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int sti(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int print(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int my_or(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int lldi(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int my_xor(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int lld(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int my_ld(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int lfork(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int ldi(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int my_fork(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
robot_t *create_champion(corewar_t *core, char *filename, int id);
nodes_t *my_sort_id_r(nodes_t *head);
int prog_nb(corewar_t *core, int *id, char **av, int *index);
int print_help(corewar_t *core, int *id, char **av, int *index);
int nbr_cycle(corewar_t *core, int *id, char **av, int *index);
int get_arg_type(unsigned char cb, int arg_num);
int read_bytes_arena(unsigned char arena[MEM_SIZE], int pc, int size);
int do_live(corewar_t *war, robot_t *robot, processus_t *proc);
int init(corewar_t **war, char **av);
void reinit(processus_t *proc);
int init_robot(corewar_t *war, char **av);
int get_robot(corewar_t *war, char *path, int id);
int free_all(corewar_t *war);
int loop(corewar_t *war);
int reg_to_arena(corewar_t *war, processus_t *proc, int reg_idx, int addr);
int live(corewar_t *war, robot_t *robot, processus_t *proc, int start_pc);
int do_action(corewar_t *war);
int do_ld(corewar_t *war, robot_t *robot, processus_t *proc);
int do_print(corewar_t *war, robot_t *robot, processus_t *proc);
void free_robot(void *data);
int die(corewar_t *war);
int dump(corewar_t *war);
int print_win(corewar_t *war);
int prog_a(corewar_t *core, int *id, char **av, int *index);
int check_flag(corewar_t *core, int ac, char **av);
int parsing(robot_t *robot, char *av);
#endif
