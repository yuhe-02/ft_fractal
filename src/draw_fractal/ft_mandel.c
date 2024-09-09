#include "ft_fractal.h"

t_coord *calc_mandelbrot_set(t_data *img, int x, int y) 
{
    t_coord *cd;

    cd = (t_coord *)malloc(sizeof(t_coord));
    if (!cd)
        exit(1);
    cd->zx = 0;
	cd->zy = 0;
    cd->cx = (x - (WIDTH / 2)) / (0.5 * img->zoom * WIDTH) + img->offsetX;
    cd->cy = (y - (HEIGHT / 2)) / (0.5 * img->zoom * HEIGHT) + img->offsetY;
    return (cd);
}
