##
## EPITECH PROJECT, 2019
## dante
## File description:
## Makefile
##

all:
	+$(MAKE) -C generator/
	+$(MAKE) -C solver/

$(NAME):
	rm -f $(shell find $(SOURCEDIR) -name '*.o')

clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*#')
	rm -f $(shell find $(SOURCEDIR) -name 'vgcore.*')
	rm -f generator/generator
	rm -f solver/solver

fclean: clean

re: clean all

.PHONY: all clean fclean re
