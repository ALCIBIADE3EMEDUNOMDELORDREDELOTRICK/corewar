/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_putnbr_base
*/

#include "../include/fct_flags.h"
#include <stdarg.h>

int flag_u_long(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned long arg = va_arg(args, unsigned long);

    if (get_flag('-', flag)) {
        count = my_put_unsigned_dec(arg, flag);
        print = 1;
    }
    for (index = 0; index < flag->width - my_nbrlen_base(arg,
            "0123456789", flag) && !(!print && get_flag('0', flag)); index++)
        my_putchar(' ');
    if (!print)
        return my_put_unsigned_dec(arg, flag) + index;
    return count + index;
}

int flag_o_long(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned long arg = va_arg(args, unsigned long);

    if (get_flag('-', flag)) {
        if (get_flag('#', flag) && arg != 0)
            count += my_put_nbr(0);
        count += my_put_nbr_base(arg, "01234567", flag);
        print = 1;
    }
    for (index = 0; index < flag->width - my_nbrlen_base(arg,
            "01234567", flag) && !(!print && get_flag('0', flag)); index++)
        my_putchar(' ');
    if (get_flag('#', flag) && arg != 0 && !print)
        count += my_put_nbr(0);
    if (!print)
        return count + my_put_nbr_base(arg, "01234567", flag) + index;
    return count + index;
}

int flag_x_long(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned long arg = va_arg(args, unsigned long);

    if (get_flag('-', flag)) {
        if (get_flag('#', flag) && arg != 0)
            count += my_putstr("0x");
        count += my_put_nbr_base(arg, "0123456789abcdef", flag);
        print = 1;
    }
    for (index = 0; index < flag->width - my_nbrlen_base(arg,
            "0123456789abcdef", flag) && !(!print && get_flag('0', flag));
        index++)
        my_putchar(' ');
    if (get_flag('#', flag) && arg != 0 && !print)
        count += my_putstr("0x");
    if (!print)
        return count + my_put_nbr_base(arg, "0123456789abcdef", flag) + index;
    return count + index;
}

int flag_bigx_long(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned long arg = va_arg(args, unsigned long);

    if (get_flag('-', flag)) {
        if (get_flag('#', flag) && arg != 0)
            count += my_putstr("0X");
        count += my_put_nbr_base(arg, "0123456789ABCDEF", flag);
        print = 1;
    }
    for (index = 0; index < flag->width - my_nbrlen_base(arg,
            "0123456789ABCDEF", flag) && !(!print && get_flag('0', flag));
        index++)
        my_putchar(' ');
    if (get_flag('#', flag) && arg != 0 && !print)
        count += my_putstr("0X");
    if (!print)
        return count + my_put_nbr_base(arg, "0123456789ABCDEF", flag) + index;
    return count + index;
}

int flag_b_long(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned long arg = va_arg(args, unsigned long);

    if (get_flag('-', flag)) {
        count = my_put_nbr_base(arg, "01", flag);
        print = 1;
    }
    for (index = 0; index < flag->width - my_nbrlen_base(arg,
            "01", flag) && !(!print && get_flag('0', flag)); index++)
        my_putchar(' ');
    if (!print)
        return my_put_nbr_base(arg, "01", flag) + index;
    return count + index;
}
