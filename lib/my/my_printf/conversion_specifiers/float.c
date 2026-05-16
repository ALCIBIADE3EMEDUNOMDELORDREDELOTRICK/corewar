/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** float
*/

#include "../include/fct_flags.h"
#include <stdarg.h>

static long long int my_power(long long int nb, int p)
{
    if (p == 0){
        return (1);
    } else {
        nb = nb * my_power(nb, p - 1);
    }
    return (nb);
}

static int my_put_dec(long long int prt, struct info_flag *flag,
    long long int round)
{
    int count = 0;
    int power = 0;

    if (round >= 5)
        prt++;
    if (flag->accuracy != 0)
        count += my_putchar('.');
    for (; flag->accuracy != 0; flag->accuracy--) {
        count++;
        power = my_power(10, flag->accuracy - 1);
        my_put_nbr(prt / power);
        prt -= (prt / power) * power;
    }
    return count;
}

int my_put_float(double nb, struct info_flag *flag)
{
    long long int prt = nb;
    int count = 0;
    long long int round = 0;

    if (prt == 0 && nb < 0)
        count += my_putchar('-');
    if (get_flag('+', flag) && nb >= 0)
        count += my_putchar('+');
    else if (get_flag(' ', flag) && nb >= 0)
        count += my_putchar(' ');
    nb = nb - prt;
    if (nb < 0)
        nb = nb * -1;
    count += my_put_nbr(prt);
    nb = (nb + (0.1 / my_power(10, flag->accuracy)))
        * my_power(10, flag->accuracy);
    prt = nb;
    round = (nb - prt) * 10;
    count += my_put_dec(prt, flag, round);
    return count;
}

int flag_f(va_list args, struct info_flag *flag)
{
    if (flag->accuracy == -1)
        flag->accuracy = 6;
    return my_put_float(va_arg(args, double), flag);
}

int flag_bigf(va_list args, struct info_flag *flag)
{
    if (flag->accuracy == -1)
        flag->accuracy = 6;
    return my_put_float(va_arg(args, double), flag);
}
