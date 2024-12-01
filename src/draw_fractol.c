/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:23:27 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/01 14:41:35 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	draw_fractol(t_param *param)
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
			color = param->calc_color(param, param->shift_flg);
			put_mlx_pixel(param, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->data.img, 0, 0);
}
