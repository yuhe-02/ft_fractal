/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:02:24 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/25 13:11:17 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	calc_color2(t_param *param, int color_flg)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	ratio = ((double)param->iteration / param->max_iter) * (double)color_flg;
	red = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	green = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	blue = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	return ((red << 16) | (green << 8) | blue);
}
