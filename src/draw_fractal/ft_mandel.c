/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:42:50 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/25 13:24:03 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_param	*calc_mandelbrot_set(t_param *param, int x, int y)
{
	param->z_re = param->param1;
	param->z_im = param->param2;
	param->c_im = param->min_im + y * param->delta_im;
	param->c_re = param->min_re + x * param->delta_re;
	return (param);
}
