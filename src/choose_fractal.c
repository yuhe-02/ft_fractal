#include "ft_fractal.h"
static int calc_color(t_coord *cd)
{
	int		i;
	int		color;
	double	tmp;

	i = 0;
	while (cd->zx * cd->zx + cd->zy * cd->zy < 4 && i < ACRAC)
    {
        tmp = cd->zx * cd->zx - cd->zy * cd->zy + cd->cx;
        cd->zy = 2.0 * cd->zx * cd->zy + cd->cy;
        cd->zx = tmp;
        i++;
    }
    if (i == ACRAC)
        i = 0;
	color = i * 10000;
	return (color);
}

static void draw_fractal(t_data *img, t_coord *(*func)(t_data *, int, int))
{
	int	x;
	int	y;
	int	color;
	t_coord *cd;

	y = 0;
    while (y < HEIGHT) 
    {
        x = 0;
        while (x < WIDTH)
        {
			cd = func(img, x, y);
			color = calc_color(cd);
			free(cd);
            put_mlx_pixel(img, x, y, color);
            x++;
        }
        y++;
    }  
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);   
}

void choose_fractal(t_data *img) 
{
	t_coord *(*func)(t_data *, int, int);

    if (img->set_type == 0) {
        func = calc_julia_set;
    } else if (img->set_type == 1) {
        func = calc_mandelbrot_set;
    } else {
        func = calc_julia_set;
    }
	draw_fractal(img, func);
}