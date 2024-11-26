/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:36:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/25 13:49:54 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int close_window(t_param *param)
{
	if (!param)
		exit(0);
	if (param->data.img)
		mlx_destroy_image(param->mlx, param->data.img);
	if (param->win)
		mlx_destroy_window(param->mlx, param->win); // ウィンドウを破棄
	if (param->mlx)
	{
		mlx_destroy_display(param->mlx); // ディスプレイを破棄
		free(param->mlx);
		param->mlx = NULL;
	}
	exit(0);
	return (0);
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void	move_by_zoom(int button, int x, int y, void *img)
{
	double	mouse_re;
	double	mouse_im;
	double	interpolation;
	t_param	*param;

	param = (t_param *)img;
	mouse_re = (double)x
		/ (WIDTH / (param->max_re - param->min_re)) + param->min_re;
	mouse_im = (double)y
		/ (HEIGHT / (param->max_im - param->min_im)) + param->min_im;
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
	param->min_re = interpolate(mouse_re, param->min_re, interpolation);
	param->min_im = interpolate(mouse_im, param->min_im, interpolation);
	param->max_re = interpolate(mouse_re, param->max_re, interpolation);
	param->max_im = interpolate(mouse_im, param->max_im, interpolation);
}

static void move_by_key(int keycode, t_param *param)
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
		choose_fractal(param);
	}
	return (0);
}

int	key_hook(int keycode, void *data)
{
	t_param	*param;

	param = (t_param *)data;
	if (keycode == KEY_ESC)
		close_window(param);
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_RIGHT || KEY_LEFT)
		move_by_key(keycode, param);
	else if (keycode == KEY_C)
		param->color_flg = 10;
	else if (keycode == KEY_B)
		param->color_flg = 1;
	else
		return (0);
	mlx_clear_window(param->mlx, param->win);
	choose_fractal(param);
	return (0);
}
