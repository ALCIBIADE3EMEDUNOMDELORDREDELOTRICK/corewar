/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** corewar
*/

#include "../../include/header.h"

int print_help(int ac, char **av)
{
    if (ac > 2)
        return -1;
    write(1, "USAGE\n./corewar [-dump nbr_cycle] ", 34);
    write(1, "[[-n prog_number] [-a load_address] prog_name] ...\n", 51);
    write(1, "DESCRIPTION\n", 12);
    write(1, "-dump nbr_cycle dumps the state of the ", 39);
    write(1, "the virtual machine after the nbr_cycle execution\n", 50);
    write(1, "-n prog_number sets the next program's number. ", 47);
    write(1, "By default, the first free number in the parameter order", 56);
    write(1, "-a load_address sets the next program's loading address. ", 57);
    write(1, "When no address is specified, optimize the ", 43);
    write(1, "addresses so that the processes are as far away from ", 44);
    write(1, "each other as possible. The addresses are MEM_SIZE modulo.", 59);
    return 0;
}
