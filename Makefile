NAME=ft_fractal
CFLAGS=-Wall -Wextra -Werror
SRCS=src/main.c src/choose_fractal.c src/ft_julia.c src/ft_mandel.c
OBJS=$(SRCS:.c=.o)

# minilibx
MINILIBX_URL := https://cdn.intra.42.fr/document/document/23420/minilibx_opengl.tgz
MINILIBX_TAR_GZ := minilibx_opengl.tgz
MINILIBX_DIR := ./minilibx-linux
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I$(MINILIBX_DIR) -Isrc/includes
LDFLAGS := -L$(MINILIBX_DIR)
LIBS=-lm -lmlx

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) minilibx-linux/libmlx_Linux.a -lX11 -lXext -o $(NAME)

%.o: %.c
	# $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(CC) $(INCLUDES) -c $< -o $@

$(MINILIBX_TAR_GZ):
	curl -O $(MINILIBX_URL)

$(MINILIBX): $(MINILIBX_TAR_GZ)
	tar xvzf $(MINILIBX_TAR_GZ)
	$(MAKE) -j4 -C $(MINILIBX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(MINILIBX_DIR)
	$(RM) $(MINILIBX_TAR_GZ)

re: fclean all

.PHONY: all clean fclean re