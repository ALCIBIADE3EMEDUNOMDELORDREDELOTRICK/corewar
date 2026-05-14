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
    int pc;
    int carry;
    int reg[REG_NUMBER];
    struct processus *next;
} processus_t;

typedef struct robot {
    bool life;
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
    int current_cycle;
    int cycle_to_die;
} corewar_t;

typedef int (*fct_t)(corewar_t *core, int ac, char **av, int *index);

typedef struct flag_s {
    char *name;
    fct_t fct;
} flag_t;

char *get_file(const char *filename);
robot_t *create_champion(corewar_t *core, char *filename, int id);
int prog_nb(corewar_t *core, int ac, char **av, int *index);
int print_help(corewar_t *core, int ac, char **av, int *index);
int nbr_cycle(corewar_t *core, int ac, char **av, int *index);
int init(corewar_t **war, char **av);
int init_robot(corewar_t *war, char **av);
int get_robot(corewar_t *war, char *path, int id);
int dump(corewar_t *war);
int print_win(corewar_t *war);
int prog_a(corewar_t *core, int id, char **av, int *index);
int check_flag(corewar_t *core, int ac, char **av);
int parsing(robot_t *robot, char *av);
#endif
