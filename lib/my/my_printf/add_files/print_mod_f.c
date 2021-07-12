/*
** EPITECH PROJECT, 2020
** mod_f
** File description:
** mod_f
*/

#include "../my_printf.h"

void print_mod_f(double nb)
{
    unsigned long long nbr = nb * 1000000;
    int len = 0;

    for (int i = nbr; i > 9; len++, i /= 10);
    for (; len >= 6; len--)
        my_put_nbr_p(nbr / my_pow(10, len) % 10);
    my_putchar_p('.');
    for (; len >= 0; len--)
        my_put_nbr_p(nbr / my_pow(10, len) % 10);
}
