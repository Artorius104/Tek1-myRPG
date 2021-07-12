##
## EPITECH PROJECT, 2020
## CPool_Day10_2020
## File description:
## Makefile
##

SRC	=	my_compute_power_rec.c			\
		my_compute_square_root.c		\
		my_find_prime_sup.c			\
		my_getnbr.c				\
		my_getstr.c				\
		my_isneg.c				\
		my_is_prime.c				\
		my_putchar.c				\
		my_put_nbr.c				\
		my_putstr.c				\
		my_revstr.c				\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_strcapitalize.c			\
		my_strcat.c				\
		my_strcmp.c				\
		my_strcpy.c				\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_is_printable.c			\
		my_str_isupper.c			\
		my_strlen.c				\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c				\
		my_strupcase.c				\
		my_swap.c				\
		my_pow.c				\
		my_itoa.c				\
		open_map.c				\
		my_printf/my_printf.c			\
		my_printf/print_mod.c			\
		my_printf/add_files/my_putchar.c	\
		my_printf/add_files/my_putnbr.c		\
		my_printf/add_files/my_putstr.c		\
		my_printf/add_files/print_octal.c	\
		my_printf/add_files/my_revstr.c		\
		my_printf/add_files/my_getstr.c		\
		my_printf/add_files/print_binary.c	\
		my_printf/add_files/my_getnbr.c		\
		my_printf/add_files/print_hexa.c	\
		my_printf/add_files/print_mod_e.c	\
		my_printf/add_files/print_mod_cape.c	\
		my_printf/add_files/print_mod_f.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY_H	=	my.h

BACK	=	../

TO_INCLUDE	=	../../include

TO_MY_H	=	../../include/my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp $(NAME) $(BACK)
	cp $(MY_H) $(TO_INCLUDE)
	rm $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(BACK)$(NAME)
	rm -f $(TO_MY_H)
	rm $(OBJ)

re:	fclean all

.PHONY: clean fclean re