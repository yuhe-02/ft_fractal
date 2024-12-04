/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:38:26 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/04 11:39:35 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_param	*calc_burningship_set(t_param *param, int x, int y)
{
	param->c_im = param->min_im + y * param->delta_im;
	param->c_re = param->min_re + x * param->delta_re;
	param->z_re = param->param1;
	param->z_im = param->param2;
	return (param);
}