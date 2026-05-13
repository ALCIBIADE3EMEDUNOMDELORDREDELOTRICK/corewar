/*
** EPITECH PROJECT, 2025
** my_putchar.c
** File description:
** Put a character c
*/

#include <unistd.h>
#include <stdarg.h>
#include "../include/fct_flags.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int flag_char(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    char arg = va_arg(args, int);

    if (get_flag('-', flag)) {
        count = my_putchar(arg);
        print = 1;
    }
    for (index = 0; index < flag->width - 1; index++)
        my_putchar(' ');
    if (!print)
        return my_putchar(arg) + index;
    return count + index;
}
