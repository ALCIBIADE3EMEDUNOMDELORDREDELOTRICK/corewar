/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_nbrlen_base
*/

#include "../include/fct_flags.h"

int my_nbrlen_base(unsigned long long n,
    char const *base, struct info_flag *flag)
{
    int count = 0;
    int acc = flag->accuracy;
    int type = 0;

    if (acc == -1)
        acc = 0;
    if (get_flag('#', flag) && flag->display == 'o' && acc == 0)
        type += 1;
    if (get_flag('#', flag) && flag->display != 'o')
        type += 2;
    if (n == 0)
        count++;
    while (n > 0) {
        count++;
        n = n / my_strlen(base);
    }
    if (acc == 0 || acc - count < 0)
        return count + type;
    return count + ((acc + type) - count);
}
