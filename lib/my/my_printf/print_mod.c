/*
** EPITECH PROJECT, 2020
** print_purcent
** File description:
** print_purcent
*/

#include "my_printf.h"

void print_mod_1(int i, char *str, va_list ap)
{
    if (str[i + 1] == 'b')
        print_binary(va_arg(ap, int));
    if (str[i + 1] == 'c')
        my_putchar_p(va_arg(ap, int));
    if (str[i + 1] == 'i' || str[i + 1] == 'd')
        my_put_nbr_p(va_arg(ap, int));
    if (str[i + 1] == 's')
        my_putstr_p(va_arg(ap, char *));
    if (str[i + 1] == 'S')
        my_putstr_octal_p(va_arg(ap, char *));
    if (str[i + 1] == 'x')
        print_hexa(va_arg(ap, int), 1);
    if (str[i + 1] == 'X')
        print_hexa(va_arg(ap, int), 2);
    if (str[i + 1] == 'o')
        print_octal_o(va_arg(ap, int));
    if (str[i + 1] == 'u')
        my_put_nbr_p(va_arg(ap, unsigned int));
    if (str[i + 1] == '%')
        my_putchar_p('%');
}

void print_mod_2(int i, char *str, va_list ap)
{
    if (str[i + 1] == 'e')
        print_mod_e(va_arg(ap, double));
    if (str[i + 1] == 'E')
        print_mod_cape(va_arg(ap, double));
    if (str[i + 1] == 'f')
        print_mod_f(va_arg(ap, double));
}

void print_mod(int i, char *str, va_list ap)
{
    if (str[i + 1] == '-' || str[i + 1] == '+'
        || str[i + 1] == ' ' || str[i + 1] == '\''
        || str[i + 1] == '#')
        va_arg(ap, void *);
    print_mod_1(i, str, ap);
    print_mod_2(i, str, ap);
}
