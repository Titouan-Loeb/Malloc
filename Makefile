##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	src/malloc.c \
		src/free.c	\
		src/calloc.c	\
		src/realloc.c	\
		src/reallocarray.c	\
		src/init.c 	\
		src/tools.c

NAME	=	libmy_malloc.so

CC	=	gcc

CFLAGS	=	-shared -fPIC

CPPFLAGS	=	-I ./include/

RM	=	rm -rf

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(CPPFLAGS)

clean:
	$(RM) *.o
	$(RM) *~

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all re clean