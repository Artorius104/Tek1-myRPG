/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** my_putnbr
*/

#include "../my_printf.h"

void my_put_nbr_p(long nb)
{
    int md;

    if (nb < 0) {
        my_putchar_p('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            md = nb % 10;
            nb = (nb - md) /10;
            my_put_nbr_p(nb);
            my_putchar_p(48 + md);
        }
        else
            my_putchar_p(48 + nb %10);
    }
}
