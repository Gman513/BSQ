NAME = bsq
SRCS = main.c bsq.h map_setup.c display.c reduction_linked.c
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -Rf $(NAME) 

re: fclean all
