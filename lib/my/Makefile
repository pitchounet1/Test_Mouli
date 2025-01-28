##
## EPITECH PROJECT, 2024
## B-PSU-100-MLN-1-1-mysudo-flavien.latrasse-chevalier
## File description:
## Makefile
##

NAME = libmy.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
INCLUDE = -I./include

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all: $(NAME) cp

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

cp:
	cp *.h ../../include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
