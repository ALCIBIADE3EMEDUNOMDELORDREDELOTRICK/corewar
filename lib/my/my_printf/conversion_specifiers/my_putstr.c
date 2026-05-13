/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** Put a str
*/

#include "../include/fct_flags.h"
#include <stdarg.h>

static int all_len(char const *str, struct info_flag *flag)
{
    if (my_strlen(str) < flag->accuracy || flag->accuracy == -1)
        return my_strlen(str);
    return flag->accuracy;
}

int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != 0; i++) {
        my_putchar(str[i]);
    }
    return (i);
}

static int my_putstr_acc(char const *str, struct info_flag *flag)
{
    int i = 0;
    int all = all_len(str, flag);

    for (; i < all; i++) {
        my_putchar(str[i]);
    }
    return (i);
}

int flag_str(va_list args, struct info_flag *flag)
{
    int index = 0;
    int print = 0;
    int count = 0;
    char *arg = va_arg(args, char *);

    if (get_flag('-', flag)) {
        count = my_putstr_acc(arg, flag);
        print = 1;
    }
    for (index = 0; index < flag->width - all_len(arg, flag); index++)
        my_putchar(' ');
    if (!print)
        return my_putstr_acc(arg, flag) + index;
    return count + index;
}

static int my_show_word_array(char const **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != 0; i++){
        count += my_putstr(tab[i]);
        count += my_putchar('\n');
    }
    return count;
}

int flag_bigs(va_list args, struct info_flag *flag)
{
    return my_show_word_array(va_arg(args, const char **));
}
