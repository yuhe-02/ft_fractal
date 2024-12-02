/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:36:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/02 14:18:05 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	move_by_key(int keycode, t_param *param)
{
	if (keycode == KEY_DOWN)
	{
		param->min_im -= (param->max_im - param->min_im) * MOVE_MAG;
		param->max_im -= (param->max_im - param->min_im) * MOVE_MAG;
	}
	if (keycode == KEY_UP)
	{
		param->min_im += (param->max_im - param->min_im) * MOVE_MAG;
		param->max_im += (param->max_im - param->min_im) * MOVE_MAG;
	}
	if (keycode == KEY_LEFT)
	{
		param->min_re += (param->max_re - param->min_re) * MOVE_MAG;
		param->max_re += (param->max_re - param->min_re) * MOVE_MAG;
	}
	if (keycode == KEY_RIGHT)
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
	else if (keycode == KEY_SPACE)
		param->space_flg = !param->space_flg;
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move_by_key(keycode, param);
	else
		return (0);
	param->cur_iter = param->max_iter / 2;
	ft_bzero(param->data.addr, param->data.llen * HEIGHT);
	return (0);
}
