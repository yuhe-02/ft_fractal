/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:30:42 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/24 15:54:33 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void	put_mlx_pixel(t_param *param, int x, int y, int color)
{
	char	*dst;

	dst = param->data.addr + (y * param->data.llen + x * (param->data.bpp / 8));
	*(unsigned int *)dst = color;
}
