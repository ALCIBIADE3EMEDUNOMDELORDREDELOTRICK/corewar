/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** init_robot
*/

#include "../../include/header.h"

static int read_comment(int fd)
{
    unsigned char buf[COMMENT_LENGTH];

    if (read(fd, buf, COMMENT_LENGTH) != COMMENT_LENGTH)
        return FAILURE;
    return SUCCESS_EXIT;
}

static int read_pad(int fd)
{
    unsigned char buf[4];

    if (read(fd, buf, 4) != 4)
        return FAILURE;
    return SUCCESS_EXIT;
}

int read_be_int(int fd)
{
    unsigned char buf[4];

    if (read(fd, buf, 4) != 4)
        return -1;
    return ((buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3]);
}

static char *get_name_str(int fd)
{
    unsigned char buf[PROG_NAME_LENGTH];
    char *name = NULL;
    int len = 0;

    if (read(fd, buf, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
        return NULL;
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        if (buf[i] != 0)
            len++;
    name = malloc(sizeof(char) * len + 1);
    if (!name)
        return NULL;
    name[len] = '\0';
    for (int i = 0; i < len; i++)
        name[i] = buf[i];
    return name;
}

static int get_header(int fd, robot_t *robot)
{
    if (read_be_int(fd) != COREWAR_EXEC_MAGIC)
        return FAILURE;
    robot->name = get_name_str(fd);
    if (!robot->name)
        return FAILURE;
    if (read_pad(fd) != SUCCESS_EXIT) {
        free(robot->name);
        return FAILURE;
    }
    robot->size = read_be_int(fd);
    if (robot->size == -1 || robot->size > CHAMP_MAX_SIZE
        || read_comment(fd) != SUCCESS_EXIT || read_pad(fd) != SUCCESS_EXIT) {
        free(robot->name);
        return FAILURE;
    }
    return SUCCESS_EXIT;
}

processus_t *create_processus(int id)
{
    processus_t *process = malloc(sizeof(processus_t));

    if (!process)
        return NULL;
    process->cycle = 0;
    process->carry = 0;
    process->pc = 0;
    process->life = false;
    process->next = NULL;
    for (int i = 0; i != REG_NUMBER; i++)
        process->reg[i] = 0;
    process->reg[0] = id;
    process->id = id;
    return process;
}

static int get_action(corewar_t *war, int fd, robot_t *robot, int id)
{
    processus_t *proc = NULL;

    robot->code = malloc(sizeof(unsigned char) * robot->size);
    if (!robot->code)
        return FAILURE;
    if (read(fd, robot->code, robot->size) != robot->size)
        return FAILURE;
    if (war->load != -1) {
        robot->load = war->load;
        war->load = -1;
    }
    proc = create_processus(id);
    if (!proc)
        return FAILURE;
    proc->next = robot->processus;
    robot->processus = proc;
    return SUCCESS_EXIT;
}

void *push_robot(corewar_t *war, char *path, int id, int fd)
{
    robot_t *robot = malloc(sizeof(robot_t));

    if (!robot)
        return NULL;
    robot->size = 0;
    robot->id = id;
    robot->load = -1;
    robot->name = NULL;
    robot->code = NULL;
    robot->processus = NULL;
    if (get_header(fd, robot) != SUCCESS_EXIT) {
        free(robot);
        return NULL;
    }
    if (get_action(war, fd, robot, id) != SUCCESS_EXIT) {
        free(robot);
        return NULL;
    }
    return robot;
}

int get_robot(corewar_t *war, char *path, int id)
{
    int fd = open(path, O_RDONLY);
    nodes_t *robot = NULL;

    if (fd < 0)
        return FAILURE;
    robot = malloc(sizeof(nodes_t));
    if (!robot) {
        close(fd);
        return FAILURE;
    }
    robot->data = push_robot(war, path, id, fd);
    if (robot->data == NULL) {
        close(fd);
        free(robot);
        return FAILURE;
    }
    push_back(&war->robot, robot);
    close(fd);
    return SUCCESS_EXIT;
}
