/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:42:23 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/24 16:07:58 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_param	*calc_julia_set(t_param *param, int x, int y)
{
	param->c_re = param->param1;
	param->c_im = param->param2;
	param->z_re = (x - (WIDTH / 2)) / (0.5 * param->zoom * WIDTH) + param->offset_x;
	param->z_im = (y - (HEIGHT / 2)) / (0.5 * param->zoom * HEIGHT) + param->offset_y;
	return (param);
}
