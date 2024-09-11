NAME=ft_fractal
CFLAGS=-Wall -Wextra -Werror
CC = cc

DRAWER= src/draw_fractal/ft_julia.c src/draw_fractal/ft_mandel.c
UTILS=	utils/ft_strncmp.c utils/ft_atob.c utils/ft_is_valid_num.c \
		utils/ft_strlen.c utils/ft_strrchr.c utils/ft_strchr.c
SRCS=src/main.c src/choose_fractal.c src/hooks.c
SRCS+=$(DRAWER)
SRCS+=$(UTILS)
OBJS=$(SRCS:.c=.o)

# minilibx
MINILIBX_URL := https://cdn.intra.42.fr/document/document/23420/minilibx_opengl.tgz
MINILIBX_TAR_GZ := minilibx_opengl.tgz
MINILIBX_DIR := ./minilibx-linux
MINILIBX := $(MINILIBX_DIR)/libmlx.a
MINILIBX_LINUX := $(MINILIBX_DIR)/libmlx_Linux.a

INCLUDES := -I$(MINILIBX_DIR) -Isrc/includes
LDFLAGS := -L$(MINILIBX_DIR)
LIBS=-lm -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MINILIBX_LINUX) $(LIBS)  -o $(NAME)

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