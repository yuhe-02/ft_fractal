/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:01:36 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 14:13:15 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	calc_color1(t_param *param, int color_flg)
{
	int		i;
	int		color;
	double	tmp;

	i = 0;
	while (param->z_re * param->z_re + param->z_im * param->z_im <= 4
		&& i < param->max_iter)
	{
		tmp = param->z_re * param->z_re
			- param->z_im * param->z_im + param->c_re;
		param->z_im = 2.0 * param->z_re * param->z_im + param->c_im;
		param->z_re = tmp;
		i++;
	}
	color = get_colors(i, param->max_iter, param, color_flg);
	return (color);
}
