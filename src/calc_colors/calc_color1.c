/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:01:36 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/26 00:02:16 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	calc_color1(t_coord *cd, int color_flg)
{
	int		i;
	int		color;
	double	tmp;

	i = 0;
	while (cd->zx * cd->zx + cd->zy * cd->zy < 4 && i < ACRAC)
	{
		tmp = cd->zx * cd->zx - cd->zy * cd->zy + cd->cx;
		cd->zy = 2.0 * cd->zx * cd->zy + cd->cy;
		cd->zx = tmp;
		i++;
	}
	if (i == ACRAC)
		i = 0;
	color = i * 10000 * color_flg;
	return (color);
}
