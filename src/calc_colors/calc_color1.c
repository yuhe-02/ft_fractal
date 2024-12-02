/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:01:36 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/02 14:18:14 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	calc_color1(t_param *param, int color_flg)
{
	int		color;
	double	tmp;
	int		i;

	i = 0;
	while (param->z_re * param->z_re + param->z_im * param->z_im <= 4
		&& i < param->cur_iter)
	{
		tmp = param->z_re * param->z_re
			- param->z_im * param->z_im + param->c_re;
		param->z_im = 2.0 * param->z_re * param->z_im + param->c_im;
		param->z_re = tmp;
		i++;
	}
	color = get_colors(i, param->cur_iter, color_flg);
	return (color);
}
