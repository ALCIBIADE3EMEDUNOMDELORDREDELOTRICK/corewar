/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** dump
*/

#include "../include/header.h"
#include "../bonus/bonus.h"


static int count_processes(robot_t *r)
{
    int count = 0;

    for (processus_t *p = r->processus; p; p = p->next)
        count++;
    return count;
}
