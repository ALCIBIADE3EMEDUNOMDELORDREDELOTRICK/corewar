/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** fct_flags
*/

#ifndef TMP_MY_PRINTF_FCT_FLAGS_H
    #define TMP_MY_PRINTF_FCT_FLAGS_H
    #include <stdarg.h>

struct info_flag
{
    char flag[6];
    int width;
    int accuracy;
    char lenght[3];
    char display;
};

int my_put_nbr_acc(long long int n, struct info_flag *flag);
int my_put_nbr(long long n);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_unsigned_dec(unsigned int n, struct info_flag *flag);
int my_put_nbr_base(unsigned long long n, char const *base,
    struct info_flag *flag);
int my_nbrlen_base(unsigned long long n, char const *base,
    struct info_flag *flag);
int flag_u_short_short(va_list args, struct info_flag *flag);
int flag_o_short_short(va_list args, struct info_flag *flag);
int flag_x_short_short(va_list args, struct info_flag *flag);
int flag_bigx_short_short(va_list args, struct info_flag *flag);
int flag_b_short_short(va_list args, struct info_flag *flag);
int flag_u_short(va_list args, struct info_flag *flag);
int flag_o_short(va_list args, struct info_flag *flag);
int flag_x_short(va_list args, struct info_flag *flag);
int flag_bigx_short(va_list args, struct info_flag *flag);
int flag_b_short(va_list args, struct info_flag *flag);
int flag_u_long(va_list args, struct info_flag *flag);
int flag_o_long(va_list args, struct info_flag *flag);
int flag_x_long(va_list args, struct info_flag *flag);
int flag_bigx_long(va_list args, struct info_flag *flag);
int flag_b_long(va_list args, struct info_flag *flag);
int flag_u_long_long(va_list args, struct info_flag *flag);
int flag_o_long_long(va_list args, struct info_flag *flag);
int flag_x_long_long(va_list args, struct info_flag *flag);
int flag_bigx_long_long(va_list args, struct info_flag *flag);
int flag_b_long_long(va_list args, struct info_flag *flag);
int my_put_float(double nb, struct info_flag *flag);
int flag_bigs(va_list args, struct info_flag *flag);
int pointer(void *P, char const *base, struct info_flag *flag);
int show_e(double nb, char e, struct info_flag *flag);
int get_flag(char c, struct info_flag *flag);
int flag_0(struct info_flag *flag);
#endif //TMP_MY_PRINTF_FCT_FLAGS_H
