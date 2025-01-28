##
## EPITECH PROJECT, 2024
## B-PSU-100-MLN-1-1-mysudo-flavien.latrasse-chevalier
## File description:
## Makefile
##

CC	=	gcc

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

INCLUDES	=	include

CFLAGS		= 	-I./$(INCLUDES) -Wall -Wextra -Werror
LDFLAGS 	= 	-L./lib/my -lmy -lcrypt

NAME	=	my_sudo

all:	libmy $(NAME)

libmy:
	make -C lib/my

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)
	@$ make -C lib/my fclean

re:	fclean all
