/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** my_printf.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void print_octal_s(unsigned int ascii);
void my_putchar_p(char c);
void my_putstr_p(char const *str);
void my_putstr_octal_p(char const *str);
void my_put_nbr_p(long nb);
char *my_revstr(char *str);
void print_mod(int i, char *str, va_list ap);
int my_getnbr(char const *str);
char *my_getstr(int nb);
int my_pow(int nb, int pow);
void print_binary(int nb);
void print_hexa(int nb, int mod);
void print_octal_o(int nb);
void print_mod_e(double nb);
int get_number(double n, unsigned long long nbr);
int *get_arr(int *arr, double nb, unsigned long long nbr);
void print_mod_cape(double nb);
void print_mod_f(double nb);
