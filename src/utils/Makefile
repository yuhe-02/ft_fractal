NAME=ft_test
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
INCLUDES=-I../includes

UTILS=	ft_strncmp.c ft_strlen.c  \
CC=gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
