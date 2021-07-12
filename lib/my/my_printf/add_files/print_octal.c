/*
** EPITECH PROJECT, 2020
** print_octal
** File description:
** print_octal
*/

#include "../my_printf.h"

void print_octal_s(unsigned int ascii)
{
    char *str = malloc(sizeof(char) * 12);
    unsigned int oct = 1;
    unsigned int rest = 1;
    int i = 0;

    for (; ascii != 0; i++) {
        str[i] = (ascii - ((ascii / 8) * 8)) + '0';
        ascii /= 8;
    }
    str[i] = '\0';
    my_putstr_p("\\0");
    if (my_getnbr(my_revstr(str)) < 10)
        my_putchar_p('0');
    my_putstr_p(str);
}

void print_octal_o(int nb)
{
    int div = 0;

    for (int times = 1, min; nb != 0; nb -= min) {
        div = 0;
        times = 1;
        for (; my_pow(8, (div + 1)) <= nb; div++);
        for (; (times + 1) * my_pow(8, div) <= nb; times++);
        my_put_nbr_p(times);
        min = times * my_pow(8, div);
    }
    for (; div != 0; div--)
        my_putchar_p('0');
}
