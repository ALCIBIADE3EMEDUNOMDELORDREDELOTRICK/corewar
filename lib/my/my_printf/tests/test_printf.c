/*
** EPITECH PROJECT, 2025
** units test for my_printf
** File description:
** test_printf
*/

#include "../include/fct_my_printf.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(printf, test_d, .init = redirect_all_std)
{
    int const nb = my_printf("%d", 56);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("56", "");
}

Test(printf, test_f, .init = redirect_all_std)
{
    int const nb = my_printf("%f", 56.5656545);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("56.565655", "");
}

Test(printf, test_lld, .init = redirect_all_std)
{
    int const nb = my_printf("%lld hehe", 152645);

    cr_assert_eq(nb, 11);
    cr_assert_stdout_eq_str("152645 hehe", "");
}

Test(printf, test_err, .init = redirect_all_std)
{
    int const nb = my_printf("%ll");

    cr_assert_eq(nb, -1);
    cr_assert_stdout_eq_str("", "");
}

Test(printf, test_erro, .init = redirect_all_std)
{
    int const nb = my_printf("%l");

    cr_assert_eq(nb, -1);
    cr_assert_stdout_eq_str("", "");
}

Test(printf, test_error, .init = redirect_all_std)
{
    int const nb = my_printf("%ll ");

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("% ", "");
}

Test(printf, test_error_1, .init = redirect_all_std)
{
    int const nb = my_printf("%56.56lly");

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str("%56.56y", "");
}

Test(printf, test_e, .init = redirect_all_std)
{
    int const nb = my_printf("%e", 56.645654);

    cr_assert_eq(nb, 12);
    cr_assert_stdout_eq_str("5.664565e+01", "");
}

Test(printf, test_b, .init = redirect_all_std)
{
    int const nb = my_printf("%b", 5654);

    cr_assert_eq(nb, 13);
    cr_assert_stdout_eq_str("1011000010110", "");
}

Test(printf, test_error_2, .init = redirect_all_std)
{
    int const nb = my_printf("%#.5#b", 5654);

    cr_assert_eq(nb, 6);
    cr_assert_stdout_eq_str("%#.5#b", "");
}

Test(printf, test_c, .init = redirect_all_std)
{
    int const nb = my_printf("%c", 'a');

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("a", "");
}

Test(printf, test_flag, .init = redirect_all_std)
{
    int const nb = my_printf("%####-+--++-c", 'a');

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("a", "");
}

Test(printf, test_percent, .init = redirect_all_std)
{
    int const nb = my_printf("%%");

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("%", "");
}

Test(printf, test_g, .init = redirect_all_std)
{
    int const nb = my_printf("%g");

    cr_assert_eq(nb, 0);
    cr_assert_stdout_eq_str("", "");
}

Test(printf, test_p)
{
    int nb = 15;
    int const nbr = my_printf("%p", &nb);
    int const nbr_test = printf("%p", &nb);

    cr_assert_eq(nbr, nbr_test);
}

Test(printf, test_bignegf, .init = redirect_all_std)
{
    int const nb = my_printf("%F", -56.5656545);

    cr_assert_eq(nb, 10);
    cr_assert_stdout_eq_str("-56.565655", "");
}

Test(printf, test_d0, .init = redirect_all_std)
{
    int const nb = my_printf("%d", 0);

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("0", "");
}

Test(printf, test_u, .init = redirect_all_std)
{
    int const nb = my_printf("%u", -58562621);

    cr_assert_eq(nb, 10);
    cr_assert_stdout_eq_str("4236404675", "");
}

Test(printf, test_u0, .init = redirect_all_std)
{
    int const nb = my_printf("%u", 0);

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("0", "");
}

Test(printf, test_o, .init = redirect_all_std)
{
    int const nb = my_printf("%o", 568);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("1070", "");
}

Test(printf, test_x, .init = redirect_all_std)
{
    int const nb = my_printf("%x", 0);

    cr_assert_eq(nb, 1);
    cr_assert_stdout_eq_str("0", "");
}

Test(printf, test_bigx, .init = redirect_all_std)
{
    int const nb = my_printf("%.4X", 68);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("0044", "");
}

Test(printf, test_s, .init = redirect_all_std)
{
    int const nb = my_printf("%s", "eric tu es super");

    cr_assert_eq(nb, 16);
    cr_assert_stdout_eq_str("eric tu es super", "");
}

Test(printf, test_bige, .init = redirect_all_std)
{
    int const nb = my_printf("%E", -58.5684569);

    cr_assert_eq(nb, 13);
    cr_assert_stdout_eq_str("-5.856846E+01", "");
}

Test(printf, test_hd, .init = redirect_all_std)
{
    int const nb = my_printf("%hd", 32800);

    cr_assert_eq(nb, 6);
    cr_assert_stdout_eq_str("-32736", "");
}

Test(printf, test_hhd, .init = redirect_all_std)
{
    int const nb = my_printf("%hhd", -128);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("-128", "");
}

Test(printf, test_qd, .init = redirect_all_std)
{
    int const nb = my_printf("%qd", 21212230000000);

    cr_assert_eq(nb, 14);
    cr_assert_stdout_eq_str("21212230000000", "");
}

Test(printf, test_hhb, .init = redirect_all_std)
{
    int const nb = my_printf("%hhb", 128);

    cr_assert_eq(nb, 8);
    cr_assert_stdout_eq_str("10000000", "");
}

Test(printf, test_hhu, .init = redirect_all_std)
{
    int const nb = my_printf("%hhu", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("128", "");
}

Test(printf, test_hho, .init = redirect_all_std)
{
    int const nb = my_printf("%hho", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("200", "");
}

Test(printf, test_hhx, .init = redirect_all_std)
{
    int const nb = my_printf("%hhx", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_hhX, .init = redirect_all_std)
{
    int const nb = my_printf("%hhX", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_hb, .init = redirect_all_std)
{
    int const nb = my_printf("%hb", 128);

    cr_assert_eq(nb, 8);
    cr_assert_stdout_eq_str("10000000", "");
}

Test(printf, test_hu, .init = redirect_all_std)
{
    int const nb = my_printf("%hu", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("128", "");
}

Test(printf, test_ho, .init = redirect_all_std)
{
    int const nb = my_printf("%ho", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("200", "");
}

Test(printf, test_hx, .init = redirect_all_std)
{
    int const nb = my_printf("%hx", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_hX, .init = redirect_all_std)
{
    int const nb = my_printf("%hX", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_lb, .init = redirect_all_std)
{
    int const nb = my_printf("%-10lb", 128);

    cr_assert_eq(nb, 10);
    cr_assert_stdout_eq_str("10000000  ", "");
}

Test(printf, test_lu, .init = redirect_all_std)
{
    int const nb = my_printf("%lu", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("128", "");
}

Test(printf, test_lo, .init = redirect_all_std)
{
    int const nb = my_printf("%lo", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("200", "");
}

Test(printf, test_lx, .init = redirect_all_std)
{
    int const nb = my_printf("%lx", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_lX, .init = redirect_all_std)
{
    int const nb = my_printf("%lX", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_llb, .init = redirect_all_std)
{
    int const nb = my_printf("%llb", 128);

    cr_assert_eq(nb, 8);
    cr_assert_stdout_eq_str("10000000", "");
}

Test(printf, test_llu, .init = redirect_all_std)
{
    int const nb = my_printf("%llu", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("128", "");
}

Test(printf, test_llo, .init = redirect_all_std)
{
    int const nb = my_printf("%llo", 128);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("200", "");
}

Test(printf, test_llx, .init = redirect_all_std)
{
    int const nb = my_printf("%llx", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_llX, .init = redirect_all_std)
{
    int const nb = my_printf("%llX", 128);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("80", "");
}

Test(printf, test_i, .init = redirect_all_std)
{
    int const nb = my_printf("%.4i", -56);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("-0056", "");
}

Test(printf, test_up, .init = redirect_all_std)
{
    int const nb = my_printf("%.4u", 56);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("0056", "");
}

Test(printf, test_e_1, .init = redirect_all_std)
{
    int const nb = my_printf("%e", -0.0069);

    cr_assert_eq(nb, 13);
    cr_assert_stdout_eq_str("-6.900000e-03", "");
}

Test(printf, test_f_2, .init = redirect_all_std)
{
    int const nb = my_printf("%f", -0.0069);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("-0.006900", "");
}

Test(printf, test_d_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5d", 56);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("56   ", "");
}

Test(printf, test_u_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5u", 56);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("56   ", "");
}

Test(printf, test_c_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5c", 'a');

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("a    ", "");
}

Test(printf, test_o_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5o", 568);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("1070 ", "");
}

Test(printf, test_x_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-2x", 0);

    cr_assert_eq(nb, 2);
    cr_assert_stdout_eq_str("0 ", "");
}

Test(printf, test_bigx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.4X", 68);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("0044 ", "");
}

Test(printf, test_b_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.4b", 1);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("0001 ", "");
}

Test(printf, test_s_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3s", "hehe");

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("heh  ", "");
}

Test(printf, test_hs_1, .init = redirect_all_std)
{
    int const nb = my_printf("%hs", "hehe");

    cr_assert_eq(nb, 0);
    cr_assert_stdout_eq_str("", "");
}

Test(printf, test_q_1, .init = redirect_all_std)
{
    int const nb = my_printf("%qs", "hehe");

    cr_assert_eq(nb, 0);
    cr_assert_stdout_eq_str("", "");
}

Test(printf, test_l_1, .init = redirect_all_std)
{
    int const nb = my_printf("%ls", "hehe");

    cr_assert_eq(nb, 0);
    cr_assert_stdout_eq_str("", "");
}

Test(printf, test_lld_1, .init = redirect_all_std)
{
    int const nb = my_printf("%lld", 2054);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("2054", "");
}

Test(printf, test_ld_1, .init = redirect_all_std)
{
    int const nb = my_printf("%ld", 2054);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("2054", "");
}

Test(printf, test_lo_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3lo", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("066  ", "");
}

Test(printf, test_lu_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3lu", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("054  ", "");
}

Test(printf, test_lx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3lx", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_lbigx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3lX", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_lb_2, .init = redirect_all_std)
{
    int const nb = my_printf("%7.3lb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str(" 100000", "");
}

Test(printf, test_llo_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3llo", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("066  ", "");
}

Test(printf, test_llu_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3llu", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("054  ", "");
}

Test(printf, test_llx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3llx", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_llbigx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3llX", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_llb_2, .init = redirect_all_std)
{
    int const nb = my_printf("%7.3llb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str(" 100000", "");
}

Test(printf, test_llb_3, .init = redirect_all_std)
{
    int const nb = my_printf("%-7.3llb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str("100000 ", "");
}

Test(printf, test_ho_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3ho", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("066  ", "");
}

Test(printf, test_hu_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hu", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("054  ", "");
}

Test(printf, test_hx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hx", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_hbigx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hX", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_hb_2, .init = redirect_all_std)
{
    int const nb = my_printf("%7.3hb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str(" 100000", "");
}

Test(printf, test_hb_3, .init = redirect_all_std)
{
    int const nb = my_printf("%-7.3hb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str("100000 ", "");
}

Test(printf, test_hho_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hho", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("066  ", "");
}

Test(printf, test_hhu_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hhu", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("054  ", "");
}

Test(printf, test_hhx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hhx", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_hhbigx_1, .init = redirect_all_std)
{
    int const nb = my_printf("%-5.3hhX", 54);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("036  ", "");
}

Test(printf, test_hhb_2, .init = redirect_all_std)
{
    int const nb = my_printf("%7.3hhb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str(" 100000", "");
}

Test(printf, test_hhb_3, .init = redirect_all_std)
{
    int const nb = my_printf("%-7.3hhb", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str("100000 ", "");
}

Test(printf, test_f_1, .init = redirect_all_std)
{
    int const nb = my_printf("%F", -1.563);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("-1.563000", "");
}

Test(printf, test_d_3, .init = redirect_all_std)
{
    int const nb = my_printf("% -7.3d", 32);

    cr_assert_eq(nb, 7);
    cr_assert_stdout_eq_str(" 032   ", "");
}

Test(printf, test_f_3, .init = redirect_all_std)
{
    int const nb = my_printf("%+.3f", 3.2369);

    cr_assert_eq(nb, 6);
    cr_assert_stdout_eq_str("+3.237", "");
}

Test(printf, test_d_4, .init = redirect_all_std)
{
    int const nb = my_printf("%+-5.3d", 3);

    cr_assert_eq(nb, 5);
    cr_assert_stdout_eq_str("+003 ", "");
}

Test(printf, test_e_4, .init = redirect_all_std)
{
    int const nb = my_printf("% e", 0.0069);

    cr_assert_eq(nb, 13);
    cr_assert_stdout_eq_str(" 6.900000e-03", "");
}

Test(printf, test_e_5, .init = redirect_all_std)
{
    int const nb = my_printf("% +e", 0.0069);

    cr_assert_eq(nb, 13);
    cr_assert_stdout_eq_str("+6.900000e-03", "");
}

Test(printf, test_x_2, .init = redirect_all_std)
{
    int const nb = my_printf("%#+x", 69);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("0x45", "");
}

Test(printf, test_bigx_2, .init = redirect_all_std)
{
    int const nb = my_printf("%#+X", 69);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("0X45", "");
}

Test(printf, test_o_2, .init = redirect_all_std)
{
    int const nb = my_printf("%#+o", 69);

    cr_assert_eq(nb, 4);
    cr_assert_stdout_eq_str("0105", "");
}

Test(printf, test_bigx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3X", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0X006    ", "");
}

Test(printf, test_x_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3x", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0x006    ", "");
}

Test(printf, test_o_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3o", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("006      ", "");
}

Test(printf, test_biglx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3lX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0X006    ", "");
}

Test(printf, test_lx_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3lx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0x006    ", "");
}

Test(printf, test_lo_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3lo", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("006      ", "");
}

Test(printf, test_bigllx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3llX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0X006    ", "");
}

Test(printf, test_llx_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3llx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0x006    ", "");
}

Test(printf, test_llo_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3llo", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("006      ", "");
}

Test(printf, test_bighx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3hX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0X006    ", "");
}

Test(printf, test_hx_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3hx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0x006    ", "");
}

Test(printf, test_ho_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3ho", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("006      ", "");
}

Test(printf, test_bighhx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3hhX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0X006    ", "");
}

Test(printf, test_hhx_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3hhx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("0x006    ", "");
}

Test(printf, test_hho_3, .init = redirect_all_std)
{
    int const nb = my_printf("%#-9.3hho", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("006      ", "");
}

Test(printf, test_biglx_5, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3lX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0X006", "");
}

Test(printf, test_lx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3lx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0x006", "");
}

Test(printf, test_lo_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3lo", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("      006", "");
}

Test(printf, test_bigllx_5, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3llX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0X006", "");
}

Test(printf, test_llx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3llx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0x006", "");
}

Test(printf, test_llo_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3llo", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("      006", "");
}

Test(printf, test_bighx_5, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3hX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0X006", "");
}

Test(printf, test_hx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3hx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0x006", "");
}

Test(printf, test_ho_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3ho", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("      006", "");
}

Test(printf, test_bighhx_5, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3hhX", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0X006", "");
}

Test(printf, test_hhx_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3hhx", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("    0x006", "");
}

Test(printf, test_hho_4, .init = redirect_all_std)
{
    int const nb = my_printf("%#9.3hho", 6);

    cr_assert_eq(nb, 9);
    cr_assert_stdout_eq_str("      006", "");
}

Test(printf, test_0d_4, .init = redirect_all_std)
{
    int const nb = my_printf("%03d", 15);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("015", "");
}

Test(printf, test_0u_4, .init = redirect_all_std)
{
    int const nb = my_printf("%-03u", 15);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("15 ", "");
}

Test(printf, test_0d_5, .init = redirect_all_std)
{
    int const nb = my_printf("%+03d", 15);

    cr_assert_eq(nb, 3);
    cr_assert_stdout_eq_str("+15", "");
}
