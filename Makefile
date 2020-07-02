##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## duo_stumper 6
##

SRC    =	*.c\
		lib/my/*.c\
		function/*.c

NAME    =	corewar

ERROR	=	-Wall -W -Wextra

CC	=	gcc

all	:	$(NAME)

$(NAME) :
	$(CC) $(ERROR) -I./include $(SRC) -o $(NAME) -g3 -Wno-unused-value -Wno-unused-parameter

clean	:
	$(RM) $(NAME)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all
