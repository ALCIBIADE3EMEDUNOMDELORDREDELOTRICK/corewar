/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_put_unsigned_dec
*/

#include "../include/fct_flags.h"
#include <stdarg.h>
#include <unistd.h>

int flag_0(struct info_flag *flag)
{
    if (get_flag('-', flag))
        return -1;
    if (get_flag('+', flag) && (flag->display == 'd' || flag->display == 'i'))
        return flag->width - 1;
    return flag->width;
}

static void my_put_rec_count(unsigned int n, int *nb_print)
{
    if (n != 0) {
        *nb_print = *nb_print + 1;
        my_put_rec_count(n / 10, nb_print);
    }
}

static int unsigned_count(unsigned int n)
{
    int nb_print = 0;

    if (n == 0) {
        nb_print = 1;
        return (nb_print);
    }
    my_put_rec_count(n, &nb_print);
    return (nb_print);
}

static void my_put_rec(unsigned int n, int *nb_print)
{
    if (n != 0) {
        *nb_print = *nb_print + 1;
        my_put_rec(n / 10, nb_print);
        my_putchar(n % 10 + 48);
    }
}

int my_put_unsigned_dec(unsigned int n, struct info_flag *flag)
{
    int nb_print = unsigned_count(n);
    int acc = flag->accuracy;

    acc = (get_flag('0', flag) && acc == -1) ? flag_0(flag) : acc;
    if (acc == -1)
        acc = 0;
    acc -= nb_print;
    nb_print = 0;
    for (; acc > 0; acc--) {
        nb_print++;
        my_putchar(48);
    }
    if (n == 0) {
        nb_print = 1;
        my_putchar(48);
        return (nb_print);
    }
    my_put_rec(n, &nb_print);
    return (nb_print);
}

int flag_u(va_list args, struct info_flag *flag)
{
    int print = 0;
    int count = 0;
    unsigned int arg = va_arg(args, unsigned int);
    int acc = (flag->accuracy == -1) ? (0) : (flag->accuracy);
    int width = flag->width;

    if (get_flag('-', flag)) {
        count = my_put_unsigned_dec(arg, flag);
        print = 1;
    }
    if (acc - unsigned_count(arg) < 0)
        width -= unsigned_count(arg);
    else
        width = (width - (acc - unsigned_count(arg))) - unsigned_count(arg);
    for (; width > 0 && !(!print && get_flag('0', flag)); width--)
        count += my_putchar(' ');
    if (!print)
        return my_put_unsigned_dec(arg, flag) + count;
    return count;
}
