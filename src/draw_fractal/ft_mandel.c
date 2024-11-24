/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:42:50 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/24 16:07:17 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_param	*calc_mandelbrot_set(t_param *param, int x, int y)
{
	param->z_re = param->param1;
	param->z_im = param->param2;
	param->c_re = (x - (WIDTH / 2)) / (0.5 * param->zoom * WIDTH) + param->offset_x;
	param->c_im = (y - (HEIGHT / 2)) / (0.5 * param->zoom * HEIGHT) + param->offset_y;
	return (param);
}
