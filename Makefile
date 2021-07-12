##
## EPITECH PROJECT, 2020
## issam ch
## File description:
## makefile
##

SRC		=	src/main.c							\
			src/menus/transition.c				\
			src/menus/main_menu.c				\
			src/menus/lose.c 					\
			src/menus/create_main_menu.c		\
			src/menus/quest.c					\
			src/menus/my_pause.c				\
			src/menus/control_sound.c 			\
			src/menus/my_info.c 				\
			src/create/create_object.c			\
			src/create/create_window.c			\
			src/create/create_text.c			\
			src/player/create_player.c 			\
			src/player/player.c 				\
			src/player/player2.c				\
			src/player/bullets/shoot.c			\
			src/player/bullets/bullet_utils.c	\
			src/player/inv/create_inv.c 		\
			src/player/inv/inventory.c			\
			src/player/inv/inv_utils.c 			\
			src/player/inv/create_wtype.c		\
			src/player/inv/stats.c 				\
			src/player/inv/minimap.c			\
			src/player/collisions.c				\
			src/player/weapons/weapons.c		\
			src/player/weapons/draw_weapons.c 	\
			src/player/pstats.c					\
			src/player/display_pstat.c			\
			src/player/orb.c					\
			src/ennemies/create_ennemies.c		\
			src/ennemies/ennemies.c				\
			src/ennemies/ennemies_hb.c 			\
			src/level/create_levels.c			\
			src/level/lvl_transition.c 			\
			src/level/allocate_levels.c			\
			src/chests/init_chests.c			\
			src/chests/chest_hb.c				\
			src/audio/sound.c					\
			src/mode.c							\
			src/utils.c 						\
			src/create/create_map.c				\
			src/draw_ground.c					\

OBJ			=	$(SRC:.c=.o)

NAME		=	my_rpg

CPPFLAGS	=	-I./include -I./lib/my

LIB			=	-L./lib/my -lmy

CFLAGS		=	-g3

CSFMLFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

LIB_PTH		=	lib/my/

DOTE_A		=	lib/my/libmy.a lib/libmy.a

MY_H		=	include/my.h

all:	$(NAME)

$(NAME):	$(OBJ)
		make -s -C $(LIB_PTH)
		gcc -o $(NAME) $(OBJ) $(CSFMLFLAGS) $(LIB) $(CPPFLAGS)
		rm $(OBJ)

clean:
	rm -f *.c~
	rm -f Makefile~
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(DOTE_A)
	rm -f $(MY_H)

re:	fclean	all

.PHONY:	re	fclean	clean	all