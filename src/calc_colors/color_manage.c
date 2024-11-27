/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:39:33 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 14:12:17 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	abs_double(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

uint32_t	rgb2hex(int r, int g, int b)
{
	uint32_t	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

uint32_t	hsv2hex(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	c = v * s;
	x = c * (1 - abs_double(((int)h / 60 % 2) - 1));
	m = v - c;
	if (s == 0)
		return (rgb2hex((v + m) * 255, (v + m) * 255, (v + m) * 255));
	if (h >= 300)
		return (rgb2hex((c + m) * 255, (0 + m) * 255, (x + m) * 255));
	else if (h >= 240)
		return (rgb2hex((x + m) * 255, (0 + m) * 255, (c + m) * 255));
	else if (h >= 180)
		return (rgb2hex((0 + m) * 255, (x + m) * 255, (c + m) * 255));
	else if (h >= 120)
		return (rgb2hex((0 + m) * 255, (c + m) * 255, (x + m) * 255));
	else if (h >= 60)
		return (rgb2hex((x + m) * 255, (c + m) * 255, (0 + m) * 255));
	else if (h >= 0)
		return (rgb2hex((c + m) * 255, (x + m) * 255, (0 + m) * 255));
	else
		return (rgb2hex((0 + m) * 255, (0 + m) * 255, (0 + m) * 255));
}

int	get_colors(int iteration, int max_iter, t_param *param, int color_flg)
{
	int		color;
	double	hue;
	double	ratio;

	if (iteration == max_iter && color_flg)
		color = rgb2hex(255, 255, 255);
	else if (iteration == max_iter && !color_flg)
		color = rgb2hex(0, 0, 0);
	else
	{
		hue = iteration % 360;
		ratio = (double)iteration / max_iter;
		if (color_flg)
		{
			hue = fmod(hue + 180.0, 360.0);
			ratio = 1 - ratio;
		}
		color = hsv2hex(hue, ratio, ratio);
	}
	return (color);
}
