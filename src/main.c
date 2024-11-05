/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:18 by yyamasak          #+#    #+#             */
/*   Updated: 2024/10/31 16:10:08 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static int	set_shape_param(t_data *img, int argc, char **argv)
{
	int	param_num;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-h", 3) || !ft_strncmp(argv[1], "--help", 7))
			set_error("", 1, 0);
	}
	if (ft_strncmp(argv[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
		img->set_type = JULIA;
	else if (ft_strncmp(argv[1], MD_S, ft_strlen(MD_S) + 1) == 0)
		img->set_type = MANDELBROT;
	else if (ft_strncmp(argv[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
		img->set_type = BONUS;
	else
	{
		close_window(img);
		set_error("ft_fractal: cannot find shape name\n", 1, 1);
	}
}

void	init_images(t_data *img, int argc, char **argv)
{
	img->bpp = 0;
	img->llen = 0;
	img->eda = 0;
	img->mlx = NULL;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, argv[1]);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	set_shape_param(img, argc, argv);
	img->color_flg = 1;
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

static int	main_loop(t_data *img)
{
	// if (canvas->is_pressed_shift)
	// 	update_fractal_c(canvas);
	choose_fractal(img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc <= 1)
		set_error("please input parameter\n", 0, 0);
	init_images(&img, argc, argv);
	choose_fractal(&img);
	set_hooks(&img);
	mlx_loop_hook(img.mlx, &main_loop, &img);
	mlx_loop(img.mlx);
	return (0);
}
