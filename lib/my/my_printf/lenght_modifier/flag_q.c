/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** flag_q
*/

#include <stdarg.h>
#include "../include/fct_flags.h"


static int flag_nbr_long_long(va_list args, struct info_flag *flag)
{
    return my_put_nbr_acc(va_arg(args, long long), flag);
}

static int get_flag_fct(struct info_flag *flag, int *get_flag)
{
    char flags[8] = "diuoxXb";
    int i = 0;

    for (i = 0; flags[i] != '\0'; i++) {
        if (flag->display == flags[i]) {
            *get_flag = 1;
            break;
        }
    }
    return i;
}

int flag_q(va_list args, struct info_flag *flag)
{
    int (*tab_flags[7])(va_list, struct info_flag *) = {
        &flag_nbr_long_long, &flag_nbr_long_long, &flag_u_long_long,
        &flag_o_long_long, &flag_x_long_long, &flag_bigx_long_long,
        &flag_b_long_long
    };
    int get_flag = 0;
    int i = 0;

    i = get_flag_fct(flag, &get_flag);
    if (get_flag) {
        return tab_flags[i](args, flag);
    }
    return 0;
}
