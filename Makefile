##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile my_hunter
##

NAME	=	my_hunter

SRC	=	main.c\
		display_usage.c\
		play.c\
		events_play.c\
		pigeon.c\
		pigeons_arrays.c\
		background.c\
		weapon.c\
		game_over_message.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system\
			-l csfml-audio

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all