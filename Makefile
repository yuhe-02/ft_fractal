NAME=ft_fractal
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
CC = gcc

COLORS= src/calc_colors/calc_color1.c src/calc_colors/calc_color2.c
DRAWER= src/draw_fractal/ft_julia.c src/draw_fractal/ft_mandel.c src/draw_fractal/ft_newton5.c
UTILS=	src/utils/ft_strncmp.c src/utils/ft_atob.c src/utils/ft_is_valid_num.c \
		src/utils/ft_strlen.c src/utils/ft_strrchr.c src/utils/ft_strchr.c \
		src/utils/ft_substr.c src/utils/ft_delete_space.c src/utils/ft_is_num.c \
		src/utils/ft_strlcpy.c src/utils/ft_isspace.c \
		src/set_error.c src/utils/ft_put_pixel.c
MATH= src/math/ft_cabs.c src/math/ft_cpow.c src/math/ft_complex_diff.c \
	  src/math/ft_complex_div.c src/math/ft_complex_add.c src/math/ft_complex_mul.c \
	  src/math/ft_complex_mul_st.c
SRCS=src/choose_fractal.c src/hooks.c
MAIN=src/main.c 
SRCS+=$(COLORS)
SRCS+=$(DRAWER)
SRCS+=$(UTILS)
SRCS+=${MATH}
SRCS+=${MAIN}
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
	# $(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	# $(RM) -r $(MINILIBX_DIR)
	# $(RM) $(MINILIBX_TAR_GZ)

re: fclean all

.PHONY: all clean fclean re