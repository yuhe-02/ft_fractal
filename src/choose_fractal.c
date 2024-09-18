#include "ft_fractal.h"

static void draw_fractal(t_data *img, fractal_func func, calc_color cal_color)
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
			color = cal_color(cd, img->color_flg);
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
    fractal_func func;
    calc_color cal_color;

    cal_color = calc_color1;
    if (img->set_type == 0)
        func = calc_julia_set;
    else if (img->set_type == 1)
        func = calc_mandelbrot_set;
    else 
    {
        func = calc_newton5_set;
        cal_color = calc_color2;
    }
	draw_fractal(img, func, cal_color);
}