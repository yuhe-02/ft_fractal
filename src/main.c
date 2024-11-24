/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:18 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/05 15:32:49 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static int	validate_params(char **argv, int param_num, int start_index)
{
	while (start_index < param_num)
	{
		if (!(ft_is_valid_num(argv[start_index])))
			return (FT_FALSE);
		start_index++;
	}
	return (FT_TRUE);
}

int	main_loop(t_data *img)
{
	// if (canvas->is_pressed_shift)
	// 	update_fractal_c(canvas);
	draw_fractal(img, img->calc_set, img->calc_color);
	// mlx_put_image_to_window(img->mlx, img->win, img->img.img, 0, 0);
	return (0);
}

static int	set_shape_param(t_data *img, int argc, char **argv)
{
	int	param_num;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-h", 3) || !ft_strncmp(argv[1], "--help", 7))
			set_error("", 1, 0);
	}
	param_num = 4;
	if (argc != param_num)
	{
		close_window(img);
		set_error("ft_fractal: the number of parameter is invalid\n", 1, 1);
	}
	if (ft_strncmp(argv[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
	{
		img->calc_set = calc_julia_set;
		img->calc_color = calc_color1;
	}
	else if (ft_strncmp(argv[1], MD_S, ft_strlen(MD_S) + 1) == 0)
	{
		img->calc_set = calc_mandelbrot_set;
		img->calc_color = calc_color1;
	}
	else if (ft_strncmp(argv[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
	{
		img->calc_set = calc_newton5_set;
		img->calc_color = calc_color2;
	}
	else
	{
		close_window(img);
		set_error("ft_fractal: cannot find shape name\n", 1, 1);
	}
	if (!validate_params(argv, param_num, 2))
	{
		close_window(img);
		set_error("ft_fractal: invalid parameter\n", 1, 1);
	}
	img->param1 = ft_atob(argv[2]);
	img->param2 = ft_atob(argv[3]);
}

void	init_images(t_data *img, int argc, char **argv)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		exit(1);
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, argv[1]);
	if (!img->win)
		exit(1);
	img->img.img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img.img)
		exit(1);
	img->img.addr = mlx_get_data_addr(img->img.img, &img->img.bpp, &img->img.llen, &img->img.eda);
	set_shape_param(img, argc, argv);
	img->color_flg = 1;
	img->zoom = 1.0;
	img->offset_x = 0.0;
	img->offset_y = 0.0;
	// img->max_re = 2;
	// img->max_im = 2;
	// img->min_re = -2;
	// img->min_im = -2;
	// img->c_re = DEFAULT_JULIA_C_RE;
	// img->c_im = DEFAULT_JULIA_C_IM;
	// img->is_pressed_shift = 0;
}

static void	set_hooks(t_data *img)
{
	mlx_hook(img->win, WINDOW_CLOSE, 0, close_window, img);
	mlx_key_hook(img->win, key_hook, img);
	mlx_mouse_hook(img->win, mouse_hook, img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc <= 1)
		set_error("please input parameter\n", 0, 0);
	init_images(&img, argc, argv);
	set_hooks(&img);
	mlx_loop_hook(img.mlx, &main_loop, &img);
	mlx_loop(img.mlx);
	return (0);
}
