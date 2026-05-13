/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_put_add
*/

#include <stdarg.h>
#include "../include/fct_flags.h"


int pointer(void *P, char const *base, struct info_flag *flag)
{
    long unsigned pointeur = (long unsigned)P;
    int count = 0;

    count += my_putstr("0x");
    count += my_put_nbr_base(pointeur, base, flag);
    return count;
}

int flag_p(va_list args, struct info_flag *flag)
{
    return pointer(args, "0123456789abcdef", flag);
}
