/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_putnbr_base
*/

#include "../include/fct_flags.h"
#include <stdarg.h>

static void count_nmb(unsigned long long n, int *count, char const *base)
{
    if (n != 0){
        *count = *count + 1;
        count_nmb(n / my_strlen(base), count, base);
    }
}

static void return_nmb(unsigned long long n, int *count, char const *base)
{
    if (n != 0){
        *count = *count + 1;
        return_nmb(n / my_strlen(base), count, base);
        my_putchar(base[n % my_strlen(base)]);
    }
}

int my_put_nbr_base(unsigned long long n, char const *base,
    struct info_flag *flag)
{
    int count = 0;
    int acc = flag->accuracy;

    acc = (get_flag('0', flag) && acc == -1) ? flag_0(flag) : acc;
    if (get_flag('#', flag) && flag->display == 'o')
        acc--;
    count_nmb(n, &count, base);
    count = n == 0 ? 1 : count;
    acc = acc == -1 ? 0 : acc;
    if (count > 0) {
        acc -= count;
        count = 0;
    }
    for (int i = 0; i < acc; i++)
        count += my_putchar(48);
    if (n == 0)
        count += my_putchar(48);
    if (n > 0)
        return_nmb(n, &count, base);
    return count;
}

int flag_o(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned int arg = va_arg(args, unsigned int);

    if (get_flag('-', flag)) {
        if (get_flag('#', flag) && arg != 0)
            count += my_put_nbr(0);
        count += my_put_nbr_base(arg, "01234567", flag);
        print = 1;
    }
    for (index = 0; index < flag->width - my_nbrlen_base(arg,
            "01234567", flag) && !(!print && get_flag('0', flag)); index++)
        my_putchar(' ');
    if (!print) {
        if (get_flag('#', flag) && arg != 0)
            count += my_put_nbr(0);
        return count + my_put_nbr_base(arg, "01234567", flag) + index;
    }
    return count + index;
}

int flag_x(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned int arg = va_arg(args, unsigned int);

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

int flag_bigx(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned int arg = va_arg(args, unsigned int);

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

int flag_b(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    unsigned int arg = va_arg(args, unsigned int);

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
