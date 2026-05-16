/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** flag_l
*/

#include <stdarg.h>
#include "../include/fct_flags.h"

static int flag_nbr_short(va_list args, struct info_flag *flag)
{
    return my_put_nbr_acc((short)va_arg(args, int), flag);
}

static int flag_nbr_short_short(va_list args, struct info_flag *flag)
{
    return my_put_nbr_acc((char)va_arg(args, int), flag);
}

static int get_flag_fct(struct info_flag *flag, int *is_double,
    int *get_flag)
{
    char flags[8] = "diuoxXb";
    int i = 0;

    if (flag->lenght[1] == 'h') {
        *is_double = 1;
    }
    for (i = 0; flags[i] != '\0'; i++) {
        if (flag->display == flags[i]) {
            *get_flag = 1;
            break;
        }
    }
    return i;
}

int flag_h(va_list args, struct info_flag *flag)
{
    int (*tab_flags[14])(va_list, struct info_flag *) = {
        &flag_nbr_short, &flag_nbr_short, &flag_u_short, &flag_o_short,
        &flag_x_short, &flag_bigx_short, &flag_b_short, &flag_nbr_short_short,
        &flag_nbr_short_short, &flag_u_short_short, &flag_o_short_short,
        &flag_x_short_short, &flag_bigx_short_short, &flag_b_short_short
    };
    int is_double = 0;
    int get_flag = 0;
    int i = 0;

    i = get_flag_fct(flag, &is_double, &get_flag);
    if (get_flag) {
        if (is_double)
            return tab_flags[7 + i](args, flag);;
        return tab_flags[i](args, flag);
    }
    return 0;
}
