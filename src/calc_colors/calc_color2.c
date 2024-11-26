/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:02:24 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/26 15:36:06 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	calc_color2(t_param *param, int color_flg)
{
    // int color;

	return (get_colors(param->iteration, param->max_iter, param, color_flg));
	// if (param->iteration == param->max_iter)
	// 	color = rgb2hex(0, 0, 0);
	// else
	// 	color = hsv2hex(param->iteration % 360, (double)param->iteration / param->max_iter,
	// 			((double)param->iteration / param->max_iter));
    // return color;
}
