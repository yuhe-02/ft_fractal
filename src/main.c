#include "ft_fractal.h"

void	put_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void validate_params(char **argv, int param_num, int start_index)
{
    while (start_index < param_num)
    {
        if (!(ft_is_valid_num(argv[start_index])))
            set_error("invalid parameter");
        start_index++;
    }
}

static int set_shape_param(t_data *img, int argc, char **argv)
{
    int param_num;

    if (ft_strncmp(argv[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
        img->set_type = JULIA;
    else if (ft_strncmp(argv[1], MANDELBROT_S, ft_strlen(MANDELBROT_S) + 1) == 0)
        img->set_type = MANDELBROT;
    else if (ft_strncmp(argv[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
        img->set_type = BONUS;
    else
        set_error("cannot find shape name");
    param_num = 4;
    if (argc != param_num)
        set_error("the number of parameter is invalid");
    validate_params(argv, param_num, 2);
    img->param1 = ft_atob(argv[2]);
    img->param2 = ft_atob(argv[3]);
}

void init_images(t_data *img, int argc, char **argv) 
{
    set_shape_param(img, argc, argv);
    img->color_flg = 1;
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, argv[1]);
    img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->zoom = 1.0;
    img->offsetX = 0.0;
    img->offsetY = 0.0;
    printf("x,y: %f,%f\n", img->param1, img->param2);
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

    if (argc <= 1)
        exit(1);
    init_images(&img, argc, argv);
    choose_fractal(&img);
    set_hooks(&img);
    mlx_loop(img.mlx);
    return (0);
}