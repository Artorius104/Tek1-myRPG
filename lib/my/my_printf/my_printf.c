/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"

void *my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            print_mod(i, str, ap);
            i++;
        } else
            my_putchar_p(str[i]);
    }
    va_end(ap);
}
