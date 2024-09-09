#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef enum e_keys {
    KEY_ESC = 65307,
    KEY_LEFT = 65361,
    KEY_UP = 65362,
    KEY_RIGHT = 65363,
    KEY_DOWN = 65364
} t_keys;


typedef struct	s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double zoom;
    double offsetX;
    double offsetY;
    int     set_type;
    int     param1;
    int     param2;
}				t_data;

typedef struct	s_coord {
    double cx;
    double cy;
    double zx;
    double zy;
}				t_coord;

#define WIDTH 400
#define HEIGHT 400
#define ACRAC 1000

void    init_images(t_data *img, int argc);
int     key_hook(int keycode, void *param);
int     mouse_hook(int button, int x, int y, void *param);
void    choose_fractal(t_data *img);
t_coord*     calc_mandelbrot_set(t_data *img, int x, int y);
t_coord*     calc_julia_set(t_data *img, int x, int y);
int     close_window(t_data *data);
void	put_mlx_pixel(t_data *data, int x, int y, int color);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
double ft_atob(const char *str);
char	*ft_strchr(const char *s, int c);
int	ft_strlen(char *str);
char	*ft_strrchr(const char *s, int c);

#endif