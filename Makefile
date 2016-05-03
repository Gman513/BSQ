NAME = bsq
SRCS = main.c bsq.h array_solution.c algorithm.c checks.c
CC = gcc -o
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(NAME) $(CFLAGS) $(SRCS)

clean:
	rm -Rf $(NAME) 

re: clean all
