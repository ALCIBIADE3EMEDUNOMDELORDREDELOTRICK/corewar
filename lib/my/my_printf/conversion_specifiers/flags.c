/*
** EPITECH PROJECT, 2025
** miniprintf
** File description:
** flags
*/

#include "../include/fct_flags.h"
#include <stdarg.h>

int flag_percent(va_list args, struct info_flag *flag)
{
    return my_putchar('%');
}

int no_flag(va_list args, struct info_flag *flag)
{
    return 0;
}
