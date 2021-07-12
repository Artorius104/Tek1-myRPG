/*
** EPITECH PROJECT, 2020
** print_hexa
** File description:
** print_hexa
*/

#include "../my_printf.h"

void print_hexa_lowcase(int nb)
{
    if (nb >= 0 && nb <= 9)
        my_put_nbr_p(nb);
    if (nb == 10)
        my_putchar_p('a');
    if (nb == 11)
        my_putchar_p('b');
    if (nb == 12)
        my_putchar_p('c');
    if (nb == 13)
        my_putchar_p('d');
    if (nb == 14)
        my_putchar_p('e');
    if (nb == 15)
        my_putchar_p('f');
}

void print_hexa_upcase(int nb)
{
    if (nb >= 0 && nb <= 9)
        my_put_nbr_p(nb);
    if (nb == 10)
        my_putchar_p('A');
    if (nb == 11)
        my_putchar_p('B');
    if (nb == 12)
        my_putchar_p('C');
    if (nb == 13)
        my_putchar_p('D');
    if (nb == 14)
        my_putchar_p('E');
    if (nb == 15)
        my_putchar_p('F');
}

void print_hexa(int nb, int mod)
{
    int div = 0;

    for (int times = 1, min; nb != 0; nb -= min) {
        div = 0;
        times = 1;
        for (; my_pow(16, (div + 1)) <= nb; div++);
        for (; (times + 1) * my_pow(16, div) <= nb; times++);
        if (mod == 1)
            print_hexa_lowcase(times);
        if (mod == 2)
            print_hexa_upcase(times);
        min = times * my_pow(16, div);
    }
    for (; div != 0; div--)
        my_putchar_p('0');
}
