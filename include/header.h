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
    FAILURE = 84,
} exit_t;

typedef int (*fct_t)(int ac, char **av);
typedef struct flag_s {
    char *name;
    fct_t fct;
} flag_t;

typedef struct robot {
    bool life;
    int *reg;
    char *name;
    int id;
    nodes_t *list;
} robot_t;

typedef struct arena {
    char ***square;
    char **memory;
    char **instruction;
} arena_t;

typedef struct corewar {
    nodes_t *robot;
    arena_t *arena;
} corewar_t;

int print_help(int ac, char **av);
int init(corewar_t **war, char **av);
int check_flag(int ac, char **av);
int parsing(robot_t *robot, char *av);
#endif
