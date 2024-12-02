/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:02:24 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/01 16:32:18 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	calc_color2(t_param *param, int color_flg)
{
	return (get_colors(param->iteration, param->cur_iter, color_flg));
}
