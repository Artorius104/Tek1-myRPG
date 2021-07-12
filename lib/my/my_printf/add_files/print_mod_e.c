/*
** EPITECH PROJECT, 2020
** mod_e
** File description:
** mod_e
*/

#include "../my_printf.h"

int *get_arr(int *arr, double nb, unsigned long long nbr)
{
    if (nb < 0)
        nb *= -1;
    arr = malloc(sizeof(int) * 2);
    arr[0] = 0;
    arr[1] = 0;
    if (nb > 1) {
        for (int i = nb; i > 1; i /= 10, arr[0]++);
        for (int i = nbr; i > 9; i /= 10, arr[1]++);
    } else if (nb < 1 && nb > 0) {
        for (double i = nb; i < 1; i *= 10, arr[0]++);
            for (int i = nbr; i > 9; i /= 10, arr[1]++);
    }
    return arr;
}

int get_number(double n, unsigned long long nbr)
{
    double nb = n;

    if (nb < 0)
        nb *= -1;
    if (nb < 1 && nb > 0)
        for (;nb < 1; nb *= 10);
    nbr = nb * 1000000;
    return nbr;
}

void print_mod_e(double nb)
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
        my_putstr_p("e+");
    else if (nb < 1 && nb > 0)
        my_putstr_p("e-");
    if (arr[0] < 10)
        my_putchar_p('0');
    my_put_nbr_p(arr[0]);
}
