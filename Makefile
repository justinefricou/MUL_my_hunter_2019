##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile my_hunter
##

NAME	=	my_hunter

SRC	=	source/main.c\
		source/display_usage.c\
		source/play.c\
		source/events_play.c\
		source/pigeon.c\
		source/pigeons_arrays.c\
		source/background.c\
		source/weapon.c\
		source/game_over_message.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS) -l csfml-graphics -l csfml-system\
			-l csfml-audio

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all