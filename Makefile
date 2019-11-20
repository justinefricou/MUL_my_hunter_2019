##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile my_hunter
##

NAME	=	my_hunter

SRC	=	main.c\
		event_handling.c

OBJ	=	$(SRC:.c=.o)

NAME_TESTS = 	test_my_hunter

SRC_TESTS =	event_handling.c

OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_TESTS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)
		rm -f *.gcno
		rm -f *.gcda

re:	fclean all

tests_run: 	$(OBJ_TESTS)
			gcc -o $(NAME_TESTS) $(OBJ_TESTS) --coverage -lcriterion
			./$(NAME_TESTS)