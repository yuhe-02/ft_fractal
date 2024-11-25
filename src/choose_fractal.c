/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:23:27 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/25 13:22:38 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static void	draw_fractal(t_param *param)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	param->delta_re = (param->max_re - param->min_re) / (WIDTH - 1);
	param->delta_im = (param->max_im - param->min_im) / (HEIGHT - 1);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			param = param->calculator(param, x, y);
			color = param->calc_color(param, param->color_flg);
			put_mlx_pixel(param, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->data.img, 0, 0);
}

void	choose_fractal(t_param *param)
{	
	draw_fractal(param);
}
