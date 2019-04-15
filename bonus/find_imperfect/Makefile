##
## EPITECH PROJECT, 2019
## dante
## File description:
## Makefile
##

SRC	=	solver.c	\
		fill_map.c	\
		resolving_algo.c	\
		final_check.c	\
		free_all.c	\
		main.c	\

SRCDIR	=	./src/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3 -O3

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
