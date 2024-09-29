/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:18 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 09:11:20 by yyamasak         ###   ########.fr       */
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
		set_error("ft_fractal: the number of parameter is invalid\n", 1, 1);
	if (ft_strncmp(argv[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
		img->set_type = JULIA;
	else if (ft_strncmp(argv[1], MD_S, ft_strlen(MD_S) + 1) == 0)
		img->set_type = MANDELBROT;
	else if (ft_strncmp(argv[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
		img->set_type = BONUS;
	else
		set_error("ft_fractal: cannot find shape name\n", 1, 1);
	if (!validate_params(argv, param_num, 2))
		set_error("ft_fractal: invalid parameter\n", 1, 1);
	img->param1 = ft_atob(argv[2]);
	img->param2 = ft_atob(argv[3]);
}

void	init_images(t_data *img, int argc, char **argv)
{
	img->bpp = 0;
	img->llen = 0;
	img->eda = 0;
	set_shape_param(img, argc, argv);
	img->color_flg = 1;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, argv[1]);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->eda);
	img->zoom = 1.0;
	img->offset_x = 0.0;
	img->offset_y = 0.0;
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
	choose_fractal(&img);
	set_hooks(&img);
	mlx_loop(img.mlx);
	return (0);
}
