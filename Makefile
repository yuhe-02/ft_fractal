NAME=fractol
CFLAGS=-Wall -Wextra -Werror
CC=cc

COLORS= src/calc_colors/calc_color1.c src/calc_colors/calc_color2.c src/calc_colors/color_manage.c
DRAWER= src/draw_fractol/ft_julia.c src/draw_fractol/ft_mandel.c src/draw_fractol/ft_burning_ship.c
UTILS= src/utils/ft_strncmp.c src/utils/ft_atob.c src/utils/ft_is_valid_num.c \
       src/utils/ft_strlen.c src/utils/ft_strrchr.c src/utils/ft_strchr.c \
       src/utils/ft_substr.c src/utils/ft_delete_space.c src/utils/ft_is_num.c \
       src/utils/ft_strlcpy.c src/utils/ft_isspace.c src/utils/ft_bzero.c \
       src/set_error.c src/utils/ft_put_pixel.c src/utils/validate_params.c
SRCS= src/draw_fractol.c src/key_hooks.c src/mouse_hooks.c src/close_window.c src/set_params.c
MAIN= src/main.c 
SRCS+=$(COLORS)
SRCS+=$(DRAWER)
SRCS+=$(UTILS)
SRCS+=$(MATH)
SRCS+=$(MAIN)
OBJS=$(SRCS:.c=.o)

# minilibx
MINILIBX_DIR := ./minilibx-linux
MINILIBX := $(MINILIBX_DIR)/libmlx_Linux.a

INCLUDES := -I$(MINILIBX_DIR) -Isrc/includes
LDFLAGS := -L$(MINILIBX_DIR)
LIBS=-lm -L$(MINILIBX_DIR) -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS) $(MINILIBX)
	$(CC) $(OBJS) $(MINILIBX) $(LIBS) -o $(NAME)

$(MINILIBX):
	make -C $(MINILIBX_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	${RM} ${MINILIBX}
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
