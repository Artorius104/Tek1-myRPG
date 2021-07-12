/*
** EPITECH PROJECT, 2020
** print_binary
** File description:
** print_binary
*/

#include "../my_printf.h"

void print_binary(int nb)
{
    int	len = 0;
    char *binary;
    int i = nb;

    for (; i != 0; len++, i /= 2);
    binary = malloc(sizeof(char) * (len + 1));
        for (int t = 0; nb != 0; nb /= 2, t++)
        binary[t] = (nb % 2) + '0';
    my_putstr_p(my_revstr(binary));
}
