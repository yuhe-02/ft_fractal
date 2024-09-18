#include "ft_fractal.h"

t_coord *calc_julia_set(t_data *img, int x, int y) 
{
    t_coord *cd;

    cd = (t_coord *)malloc(sizeof(t_coord));
    if (!cd)
        exit(1);
    cd->cx = img->param1;
    cd->cy = img->param2;
    cd->zx = (x - (WIDTH / 2)) / (0.5 * img->zoom * WIDTH) + img->offsetX;
    cd->zy = (y - (HEIGHT / 2)) / (0.5 * img->zoom * HEIGHT) + img->offsetY;
    return (cd);
}