NAME=ft_test
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
INCLUDES=-I../includes

UTILS=	ft_strncmp.c ft_atob.c ft_is_valid_num.c \
		ft_strlen.c ft_strrchr.c ft_strchr.c \
		ft_substr.c ft_delete_space.c ft_is_num.c \
		ft_strlcpy.c ft_isspace.c
OBJS=$(UTILS:.c=.o) convert_main.o
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
