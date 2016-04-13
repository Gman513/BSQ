NAME = bsq
SRCS = main.c header.h
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -Rf $(NAME) 

re: fclean all
