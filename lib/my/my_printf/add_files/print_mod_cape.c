/*
** EPITECH PROJECT, 2020
** mod_e
** File description:
** mod_e
*/

#include "../my_printf.h"

void print_mod_cape(double nb)
{
    unsigned long long nbr = get_number(nb, nbr);
    int *arr = get_arr(arr, nb, nbr);

    if (nb < 0) {
        nb *= -1;
        my_putchar_p('-');
    }
    my_put_nbr_p(nbr / my_pow(10, arr[1]));
    my_putchar_p('.');
    arr[1]--;
    for (int i = 1; i <= 6; i++, arr[1]--) {
        my_put_nbr_p((nbr / my_pow(10, arr[1])) % 10);
    }
    if (nb > 1)
        my_putstr_p("E+");
    else if (nb < 1 && nb > 0)
        my_putstr_p("E-");
    if (arr[0] < 10)
        my_putchar_p('0');
    my_put_nbr_p(arr[0]);
}
