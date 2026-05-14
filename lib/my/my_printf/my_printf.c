/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** my_printf.c
*/

#include "include/fct_flags.h"
#include <stdarg.h>
#include <unistd.h>
#include "include/my_printf.h"

static int type_of_lenght(const char *format, int index, struct info_flag *flag)
{
    char length[8] = "lLhjztq";
    int count = 0;
    int i = 0;

    for (i = 0; length[i] != 0; i++) {
        if (length[i] == format[index]) {
            flag->lenght[0] = length[i];
            flag->lenght[1] = 0;
            count++;
            break;
        }
    }
    if (length[i] == format[index + 1] &&
        (length[i] == 'l' || length[i] == 'h')) {
        flag->lenght[1] = length[i];
        flag->lenght[2] = 0;
        count++;
    }
    return count;
}

static int nb_of_accuracy(const char *format, int index, struct info_flag *flag)
{
    int nb = 0;
    int count = 0;

    if (format[index] == '.') {
        count++;
        for (int i = index + 1; format[i] >= '0'
            && format[i] <= '9' && format[i] != '\0'; i++) {
            count++;
            nb = nb * 10;
            nb += format[i] - 48;
        }
        flag->accuracy = nb;
    }
    return count;
}

static int nb_of_width(const char *format, int index, struct info_flag *flag)
{
    int nb = 0;
    int count = 0;

    for (int i = index; format[i] >= '0'
        && format[i] <= '9' && format[i] != '\0'; i++) {
        count++;
        nb = nb * 10;
        nb += format[i] - 48;
    }
    flag->width = nb;
    return count;
}

static int type_of_flag(char format, struct info_flag *flag, int *index)
{
    char str[6] = "-+ #0";

    for (int i = 0; flag->flag[i] != 0; i++) {
        if (flag->flag[i] == format)
            return 1;
    }
    for (int i = 0; str[i] != 0; i++) {
        if (format == str[i]){
            flag->flag[*index] = format;
            flag->flag[*index + 1] = 0;
            *index += 1;
            return 1;
        }
    }
    return 0;
}

static int print_no_mod(struct info_flag *flag, int *nb)
{
    *nb += my_putchar('%');
    for (int i = 0; flag->flag[i] != 0; i++) {
        if (flag->flag[i] != ' ' && flag->flag[i] != '0')
            *nb += my_putchar(flag->flag[i]);
    }
    if (flag->width > 0)
        *nb += my_put_nbr(flag->width);
    if (flag->accuracy != -1) {
        *nb += my_putchar('.');
        *nb += my_put_nbr(flag->accuracy);
    }
    return 0;
}

static int type_of_mod(const char *format, int count,
    struct info_flag *flag, int *nb)
{
    char mod[24] = "diouxXeEfFgGaAcspnm%SbB";

    for (int i = 0; mod[i] != 0; i++) {
        if (format[count] == mod[i]) {
            flag->display = mod[i];
            return 1;
        }
    }
    flag->display = 0;
    if (format[count] == '-' || format[count] == 0) {
        *nb -= 1;
        return 0;
    }
    count = 0;
    *nb += print_no_mod(flag, nb);
    return count;
}

static int show_that_sh(struct info_flag *flag, va_list list)
{
    int count = 0;

    if (flag->display == 0)
        return 0;
    if (((flag->lenght[0]) != 0))
        count += (*tab[flag->lenght[0]])(list, flag);
    else
        count += (*tab[flag->display])(list, flag);
    return count;
}

static int show_flag(va_list list, const char *format, int *nb)
{
    struct info_flag flag = {0};
    int count = 0;
    int index = 0;

    flag.accuracy = -1;
    for (; type_of_flag(format[count], &flag, &index) == 1; count++);
    count += nb_of_width(format, count, &flag);
    count += nb_of_accuracy(format, count, &flag);
    count += type_of_lenght(format, count, &flag);
    count += type_of_mod(format, count, &flag, nb);
    *nb += show_that_sh(&flag, list);
    return count;
}

int get_flag(char c, struct info_flag *flag)
{
    int index = 0;

    for (index = 0; flag->flag[index] != 0; index++) {
        if (flag->flag[index] == c)
            return 1;
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int index = 0;
    int nb = 0;

    va_start(args, format);
    for (index = 0; index < my_strlen(format);) {
        if (format[index] == '%') {
            index++;
            index += show_flag(args, format + index, &nb);
            continue;
        }
        nb++;
        my_putchar(format[index]);
        index++;
    }
    return nb;
}
