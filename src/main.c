/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:18 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/26 15:29:43 by yyamasak         ###   ########.fr       */
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

static int	set_shape_param(t_param *param, int argc, char **argv)
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
		close_window(param);
		set_error("ft_fractal: the number of parameter is invalid\n", 1, 1);
	}
	if (ft_strncmp(argv[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
	{
		param->set_type = JULIA;
		param->calculator = calc_julia_set;
		param->calc_color = calc_color1;
	}
	else if (ft_strncmp(argv[1], MD_S, ft_strlen(MD_S) + 1) == 0)
	{
		param->set_type = MANDELBROT;
		param->calculator = calc_mandelbrot_set;
		param->calc_color = calc_color1;
	}
	else if (ft_strncmp(argv[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
	{
		param->set_type = BONUS;
		param->calculator = calc_newton5_set;
		param->calc_color = calc_color2;
	}
	else
	{
		close_window(param);
		set_error("ft_fractal: cannot find shape name\n", 1, 1);
	}
	if (!validate_params(argv, param_num, 2))
	{
		close_window(param);
		set_error("ft_fractal: invalid parameter\n", 1, 1);
	}
	param->param1 = ft_atob(argv[2]);
	param->param2 = ft_atob(argv[3]);
}

void	init_images(t_param *param, int argc, char **argv)
{
	set_shape_param(param, argc, argv);
	param->max_re = 2;
	param->max_im = 2;
	param->min_re = -2;
	param->min_im = -2;
	param->max_iter = MAX_ITER;
	param->color_flg = 0;
	param->data.addr = mlx_get_data_addr(param->data.img, &(param->data.bpp), &(param->data.llen), &(param->data.eda));
}

void	initialize_param(t_param *param, int argc, char **argv)
{
	param->mlx = mlx_init();
	if (!param->mlx)
		exit(1);
	param->win = mlx_new_window(param->mlx, WIDTH, HEIGHT, "fractol");
	if (!param->win)
		exit(1);
	param->data.img = mlx_new_image(param->mlx,
			WIDTH, HEIGHT);
	if (!param->data.img)
		exit(1);
	param->data.addr = mlx_get_data_addr(param->data.img,
			&param->data.bpp,
			&param->data.llen, &param->data.eda);
	init_images(param, argc, argv);
}

static void	set_hooks(t_param *param)
{
	mlx_hook(param->win, WINDOW_CLOSE, 0, close_window, param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_mouse_hook(param->win, mouse_hook, param);
}

int	main_loop(t_param *param)
{
	if (param->shift_flg)
		update_fractal_c(param);
	// param->fractal_drawer(canvas);
	// mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img.img, 0, 0);
	choose_fractal(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_data	img;

	if (argc <= 1)
		set_error("please input parameter\n", 0, 0);
	initialize_param(&param, argc, argv);
	choose_fractal(&param);
	set_hooks(&param);
	mlx_loop_hook(param.mlx, &main_loop, &param);
	mlx_loop(param.mlx);
	return (0);
}
