SRC	=	src/main.c	\
		src/lib.c	\
		src/map.c	\
		src/player.c	\
		src/inter.c	\
		src/computer.c	\
		src/matchstick.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-I ./includes	\
			-Wall	\
			-Wextra	\
			-g

LDFLAGS	=	-lncurses

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	rm -f $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean re fclean