/*
** EPITECH PROJECT, 2025
** bsminiprintf
** File description:
** bsprintf
*/

#ifndef MY_PRINTF_PRINTF_H
    #define MY_PRINTF_PRINTF_H
    #include <stdarg.h>
    #include "fct_flags.h"

typedef int (*tab_t[127])(va_list, struct info_flag *);

int flag_percent(va_list args, struct info_flag *flag);

int no_flag(va_list args, struct info_flag *flag);

int flag_str(va_list args, struct info_flag *flag);

int flag_nbr(va_list args, struct info_flag *flag);

int flag_char(va_list args, struct info_flag *flag);

int flag_u(va_list args, struct info_flag *flag);

int flag_o(va_list args, struct info_flag *flag);

int flag_x(va_list args, struct info_flag *flag);

int flag_bigx(va_list args, struct info_flag *flag);

int flag_l(va_list args, struct info_flag *flag);

int flag_b(va_list args, struct info_flag *flag);

int flag_h(va_list args, struct info_flag *flag);

int flag_f(va_list args, struct info_flag *flag);

int flag_q(va_list args, struct info_flag *flag);

int flag_bigf(va_list args, struct info_flag *flag);

int flag_p(va_list args, struct info_flag *flag);

int flag_e(va_list args, struct info_flag *flag);

int flag_bige(va_list args, struct info_flag *flag);

int flag_bigs(va_list args, struct info_flag *flag);

const tab_t tab = {
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &flag_percent,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &flag_b,
    &no_flag,
    &no_flag,
    &flag_bige,
    &flag_bigf,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &flag_bigs,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &flag_bigx,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &flag_b,
    &flag_char,
    &flag_nbr,
    &flag_e,
    &flag_f,
    &no_flag,
    &flag_h,
    &flag_nbr,
    &no_flag,
    &no_flag,
    &flag_l,
    &no_flag,
    &no_flag,
    &flag_o,
    &flag_p,
    &flag_q,
    &no_flag,
    &flag_str,
    &no_flag,
    &flag_u,
    &no_flag,
    &no_flag,
    &flag_x,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag,
    &no_flag
};
#endif //MY_PRINTF_PRINTF_H
