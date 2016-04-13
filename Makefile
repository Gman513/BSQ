NAME = ft_display_file

SRCS = main.c controls.c

INC = header.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS)

clean:
	rm -Rf $(OBJS) file.o

fclean: clean
	rm -Rf $(NAME)

re: fclean all
