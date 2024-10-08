/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:02:24 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/26 00:04:08 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	calc_color2(t_coord *cd, int color_flg)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	ratio = ((double)cd->iterations / MAX_ITER) * (double)color_flg;
	red = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	green = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	blue = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	return ((red << 16) | (green << 8) | blue);
}
