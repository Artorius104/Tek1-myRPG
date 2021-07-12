/*
** EPITECH PROJECT, 2020
** getstr
** File description:
** getstr
*/

#include <stdlib.h>

int my_strlen(char *str);

int my_intlen(int nb)
{
    int i = 0;

    if (nb > 0)
        for (; nb > 1; i++)
            nb /= 10;
    if (nb < 0)
        for (; nb < -1; i++)
            nb /= 10;
    if (nb = 0)
        return 1;
    i++;
    return i;
}

int my_pow(int nb, int pow)
{
    int result = nb;

    if (pow == 1)
        return result;
    if (pow == 0)
        return 1;
    for (int i = 1; i < pow; i++)
        result *= nb;
    return result;
}

char *my_getstr(int nb)
{
    int t = 0;
    char *str = malloc(sizeof(char) * (my_intlen(nb) + 1));

    if (nb < 0) {
        nb *= -1;
        str[t] = '-';
        t++;
    }
    for (int i = my_intlen(nb); i > 0; i--, t++)
        str[t] = ((nb / my_pow(10, (i - 1)) % 10) + '0');
    return str;
}
