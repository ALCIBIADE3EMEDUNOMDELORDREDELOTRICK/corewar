/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** notation_e
*/

#include <stdarg.h>
#include "../include/fct_flags.h"


static int my_decimal(int power, char e, char sign)
{
    int count = 0;

    my_putchar(e);
    my_putchar(sign);
    if (power < 10)
        count += my_putchar('0');
    count += my_put_nbr(power);
    return count + 2;
}

int show_e(double nb, char e, struct info_flag *flag)
{
    int count = nb;
    int power = 0;

    if (count == 0 && nb != 0) {
        while (count == 0) {
            nb = nb * 10;
            count = nb;
            power++;
        }
        count = my_put_float(nb, flag);
        count += my_decimal(power, e, '-');
    } else {
        for (int i = 0; nb >= 10 || nb <= -10; i++) {
            power++;
            nb = nb / 10;
        }
        count = my_put_float(nb, flag);
        count += my_decimal(power, e, '+');
    }
    return count;
}

int flag_e(va_list args, struct info_flag *flag)
{
    if (flag->accuracy == -1)
        flag->accuracy = 6;
    return show_e(va_arg(args, double), 'e', flag);
}

int flag_bige(va_list args, struct info_flag *flag)
{
    if (flag->accuracy == -1)
        flag->accuracy = 6;
    return show_e(va_arg(args, double), 'E', flag);
}
