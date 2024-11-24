/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:23:27 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/24 16:13:37 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static void	draw_fractal(t_param *param,
						t_fractal_func func, t_calc_color cal_color)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			param = func(param, x, y);
			color = cal_color(param, param->color_flg);
			put_mlx_pixel(param, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->data.img, 0, 0);
}

void	choose_fractal(t_param *param)
{
	t_fractal_func	func;
	t_calc_color	cal_color;

	cal_color = calc_color1;
	if (param->set_type == 0)
		func = calc_julia_set;
	else if (param->set_type == 1)
		func = calc_mandelbrot_set;
	else
	{
		func = calc_newton5_set;
		cal_color = calc_color2;
	}
	draw_fractal(param, func, cal_color);
}
