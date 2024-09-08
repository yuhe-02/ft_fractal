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
}				t_data;

#define WIDTH 400
#define HEIGHT 400
#define ACRAC 1000

void init_images(t_data *img, int argc);
int key_hook(int keycode, void *param);
int mouse_hook(int button, int x, int y, void *param);
void choose_fractal(t_data *img);
void draw_mandelbrot_set(t_data *img);
void draw_julia_set(t_data *img);
int close_window(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif