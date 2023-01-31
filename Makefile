##
## EPITECH PROJECT, 2022
## Makefiles
## File description:
## MakeFiles
##
SRC	=	$(wildcard lib/my/*.c file/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a
NAMEDEUX =	my_sokoban

all: $(NAME) clean

$(NAME): $(OBJ)
	mkdir -p includes
	cp lib/my/my.h includes/
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAMEDEUX) file/main.c -I includes/ -L. -lncurses -lmy

clean:
	rm -f $(OBJ)
	rm -f $(wildcard lib/my/.# lib/my/*~)
	rm -f $(wildcard file/.# file/*~)
	rm -f $(wildcard .# *~)
	rm -f $(wildcard vgcore.*)

fclean :	clean
	rm -f $(NAME)
	rm -f $(NAMEDEUX)

re:	fclean all
