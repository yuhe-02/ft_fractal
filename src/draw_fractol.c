/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:23:27 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/02 14:19:35 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	get_pixel_color(t_param *param, int x, int y)
{
	int	pixel_position;
	int	red;
	int	green;
	int	blue;

	pixel_position = (y * param->data.llen) + (x * (param->data.bpp / 8));
	blue = (unsigned char)param->data.addr[pixel_position];
	green = (unsigned char)param->data.addr[pixel_position + 1];
	red = (unsigned char)param->data.addr[pixel_position + 2];
	return (red << 16 | green << 8 | blue);
}

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
			if (get_pixel_color(param, x, y) == 0)
			{
				param = param->calculator(param, x, y);
				color = param->calc_color(param, param->space_flg);
				put_mlx_pixel(param, x, y, color);
			}
			x++;
		}
		y++;
	}
}
