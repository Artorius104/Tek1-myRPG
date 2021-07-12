/*
** EPITECH PROJECT, 2020
** CPool_Day09_2019
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stddef.h>

void *my_printf(char *str, ...);
char *my_strcat_r(char *dest, char const *src);
int my_pow(int nb, int pow);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int is_whole_number(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_getnbr(char *str);
char *my_getstr(int nb);
int my_isneg(int n);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
int can_you_change_in_capital(char *str, int i);
char *my_strcat(char *dest, char const *src);
int  my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strlowcase(char *str);
char *my_itoa(int nb);
char my_clowcase(char c);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n_1, int n_2);
int  my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int check_forbidden_op(int nb_1, char op, int nb_2);
int check_operator(char *operator);
int check_string(char *str);
int my_intlen(int nb);
char **open_map(char *pth);

#endif
