/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:36:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/01 14:43:29 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	move_by_key(int keycode, t_param *param)
{
	if (keycode == KEY_UP)
	{
		param->min_im -= (param->max_im - param->min_im) * MOVE_MAG;
		param->max_im -= (param->max_im - param->min_im) * MOVE_MAG;
	}
	if (keycode == KEY_DOWN)
	{
		param->min_im += (param->max_im - param->min_im) * MOVE_MAG;
		param->max_im += (param->max_im - param->min_im) * MOVE_MAG;
	}
	if (keycode == KEY_RIGHT)
	{
		param->min_re += (param->max_re - param->min_re) * MOVE_MAG;
		param->max_re += (param->max_re - param->min_re) * MOVE_MAG;
	}
	if (keycode == KEY_LEFT)
	{
		param->min_re -= (param->max_re - param->min_re) * MOVE_MAG;
		param->max_re -= (param->max_re - param->min_re) * MOVE_MAG;
	}
}

int	key_hook(int keycode, void *data)
{
	t_param	*param;

	param = (t_param *)data;
	if (keycode == KEY_ESC)
		close_window(param);
	else if (keycode == KEY_SHIFT)
		param->shift_flg = FT_TRUE;
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_by_key(keycode, param);
	else
		return (0);
	mlx_clear_window(param->mlx, param->win);
	draw_fractol(param);
	return (0);
}
