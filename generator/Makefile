##
## EPITECH PROJECT, 2019
## dante
## File description:
## Makefile
##

SRC	=	generator.c	\
		initialize_free.c	\
		final_check.c	\
		path.c	\
		imperfect_path.c	\
		main.c	\

SRCDIR	=	./src/

OBJ	=	$(addprefix $(SRCDIR), $(SRC:.c=.o))

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3 -O3

NAME	=	generator

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
