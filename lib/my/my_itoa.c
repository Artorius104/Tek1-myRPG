/*
** EPITECH PROJECT, 2019
** my_itoa.c
** File description:
** my_itoa
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int my_int_len(int nb)
{
    int count = 1;

    for (int div = 1; nb / div >= 1; div *= 10, count++);
    return count;
}

char *my_itoa(int nb)
{
    if (nb < 0)
        nb *= -1;
    else if (nb == 0)
        return "0\0";
    int i = my_int_len(nb) - 1;
    char *str = malloc(sizeof(char) * (i + 1));

    if (str == NULL)
        return NULL;
    str[i] = '\0';
    for (; i > 0; nb /= 10, i--)
        str[i - 1] = (nb % 10) + '0';
    if (str[0] == '\0')
        str = my_strcpy("\0", "0\0");
    return str;
}
