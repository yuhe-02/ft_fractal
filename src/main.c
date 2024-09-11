#include "ft_fractal.h"

void	put_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void init_images(t_data *img, int argc, char **argv) 
{
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Some Set");
    img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->zoom = 1.0;
    img->offsetX = 0.0;
    img->offsetY = 0.0;
    if (ft_strncmp(argv[1], "julia", 6) == 0)
        img->set_type = 0;
    else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
        img->set_type = 1;
    else 
        exit(1);
    if (!ft_is_valid_num(argv[2]) || !ft_is_valid_num(argv[3]))
        exit(1);
    img->param1 = ft_atob(argv[2]);
    img->param2 = ft_atob(argv[3]);
}

static void    set_hooks(t_data *img)
{
    mlx_hook(img->win, 17, 0, close_window, img);
    mlx_key_hook(img->win, key_hook, img);
    mlx_mouse_hook(img->win, mouse_hook, img);
}

int	main(int argc, char **argv)
{
    t_data	img;

    if (argc != 4)
        exit(1);
    init_images(&img, argc);
    choose_fractal(&img);
    set_hooks(&img);
    mlx_loop(img.mlx);
    return (0);
}