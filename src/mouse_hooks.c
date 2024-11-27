/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:36:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 14:07:05 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static double	*get_mouse_pos(int x, int y, t_param *param)
{
	double	mouse_re;
	double	mouse_im;
	double	mouse_pos[2];

	mouse_re = (double)x
		/ (WIDTH / (param->max_re - param->min_re)) + param->min_re;
	mouse_im = (double)y
		/ (HEIGHT / (param->max_im - param->min_im)) + param->min_im;
	mouse_pos[0] = mouse_re;
	mouse_pos[1] = mouse_im;
	return (mouse_pos);
}

static void	move_by_zoom(int button, int x, int y, void *img)
{
	double	interpolation;
	t_param	*param;
	double	*mouse_pos;

	param = (t_param *)img;
	mouse_pos = get_mouse_pos(x, y, param);
	if (button == MOUSE_WHEEL_UP)
	{
		if (param->max_iter > 4)
			param->max_iter -= 4;
		interpolation = 1.0 / 0.8;
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
		param->max_iter += 4;
		interpolation = 1.0 / 1.2;
	}
	else
		return ;
	param->min_re = interpolate(mouse_pos[0], param->min_re, interpolation);
	param->min_im = interpolate(mouse_pos[1], param->min_im, interpolation);
	param->max_re = interpolate(mouse_pos[0], param->max_re, interpolation);
	param->max_im = interpolate(mouse_pos[1], param->max_im, interpolation);
}

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

int	mouse_hook(int button, int x, int y, void *data)
{
	t_param	*param;

	param = (t_param *)data;
	if (button == MOUSE_WHEEL_UP || button == MOUSE_WHEEL_DOWN)
	{
		move_by_zoom(button, x, y, param);
		mlx_clear_window(param->mlx, param->win);
		draw_fractol(param);
	}
	return (0);
}
