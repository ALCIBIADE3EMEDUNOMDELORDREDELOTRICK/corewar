/*
** EPITECH PROJECT, 2025
** my_put_nbr.c
** File description:
** Print a int
*/

#include "../include/fct_flags.h"
#include <stdarg.h>

static void my_put_nbr_pos_count(long long int n, int *nb_print)
{
    if (n != 0) {
        *nb_print = *nb_print + 1;
        my_put_nbr_pos_count(n / 10, nb_print);
    }
}

static int my_put_nbr_count(long long int n)
{
    int nb_print = 0;

    if (n == 0)
        nb_print = 1;
    else
        my_put_nbr_pos_count(n, &nb_print);
    return (nb_print);
}

static void my_put_nbr_neg(long long int n, int *nb_print)
{
    if (n != 0) {
        *nb_print = *nb_print + 1;
        my_put_nbr_neg(n / 10, nb_print);
        my_putchar((n % 10 + 48) - (n % 10) * 2);
    }
}

static void my_put_nbr_pos(long long int n, int *nb_print)
{
    if (n != 0) {
        *nb_print = *nb_print + 1;
        my_put_nbr_pos(n / 10, nb_print);
        my_putchar(n % 10 + 48);
    }
}

int my_put_nbr(long long int n)
{
    int nb_print = 0;

    if (n == 0) {
        nb_print = 1;
        my_putchar(48);
    }
    if (n > 0){
        my_put_nbr_pos(n, &nb_print);
    }
    if (n < 0){
        my_putchar(45);
        nb_print = nb_print + 1;
        my_put_nbr_neg(n, &nb_print);
    }
    return (nb_print);
}

int my_put_nbr_acc(long long int n, struct info_flag *flag)
{
    int count = my_put_nbr_count(n);
    int acc = flag->accuracy;

    acc = (get_flag('0', flag) && acc == -1) ? flag_0(flag) : acc;
    if (acc == -1)
        acc = 0;
    acc -= count;
    count = 0;
    if (get_flag('+', flag) && n >= 0)
        count += my_putchar('+');
    else if (get_flag(' ', flag) && n >= 0)
        count += my_putchar(' ');
    if (n < 0) {
        count += my_putchar('-');
        n = n * - 1;
    }
    for (; acc > 0; acc--)
        count += my_putchar(48);
    count += my_put_nbr(n);
    return count;
}

static int my_nbrlen(long long int arg, struct info_flag *flag)
{
    int count = my_put_nbr_count(arg);
    int acc = flag->accuracy;

    if (acc == -1)
        acc = 0;
    acc -= count;
    if (arg < 0)
        count++;
    if (acc < 0)
        acc = 0;
    count = count + acc;
    if ((get_flag('+', flag) || get_flag(' ', flag)) && arg >= 0)
        count++;
    return count;
}

int flag_nbr(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    long long int arg = va_arg(args, int);
    int width = flag->width;

    if (get_flag('-', flag)) {
        count = my_put_nbr_acc(arg, flag);
        print = 1;
    }
    width -= my_nbrlen(arg, flag);
    for (index = 0; index < width && !(!print && get_flag('0', flag));
        index++)
        my_putchar(' ');
    if (!print)
        return my_put_nbr_acc(arg, flag) + index;
    return count + index;
}
