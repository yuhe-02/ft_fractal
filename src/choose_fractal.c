#include "ft_fractal.h"

void choose_fractal(t_data *img) 
{
    if (img->set_type == 0) {
        draw_julia_set(img);
    } else if (img->set_type == 1) {
        draw_mandelbrot_set(img);
    } else {
        printf("Unknown fractal set type!\n");
    }
}