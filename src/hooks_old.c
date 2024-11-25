/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:36:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/24 15:57:51 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void close_window2(t_param *data)
{
	close_window(data);
	exit(0);
}

int close_window(t_param *param)
{
	if (!param)
		exit(0);
	if (param->data.img)
	{
		mlx_destroy_image(param->mlx, param->data.img);
		param->data.img = NULL;
	}
	if (param->win)
	{
	// 	// mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(param->mlx, param->win); // ウィンドウを破棄
		param->win = NULL;
	}
	if (param->mlx)
	{
		mlx_destroy_display(param->mlx); // ディスプレイを破棄
		free(param->mlx);
		param->mlx = NULL;
	}
	exit(0);
	return (0);
}

static void	change_centered(t_param *i, int x, int y)
{
	i->offset_x = (x - WIDTH / 2.0) * (F_RAN / WIDTH) / i->zoom + i->offset_x;
	i->offset_y = (y - HEIGHT / 2.0) * (F_RAN / HEIGHT) / i->zoom + i->offset_y;
}

int	mouse_hook(int button, int x, int y, void *img)
{
	t_param	*param;

	param = (t_param *)img;
	if (button == MOUSE_WHEEL_UP)
		param->zoom *= ZOOM_MAG;
	else if (button == MOUSE_WHEEL_DOWN)
		param->zoom /= ZOOM_MAG;
	else if (button == MOUSE_LEFT_CLICK)
		change_centered(param, x, y);
	else
		return (0);
	mlx_clear_window(param->mlx, param->win);
	choose_fractal(param);
	return (0);
}

int	key_hook(int keycode, void *data)
{
	t_param	*param;

	param = (t_param *)data;
	if (keycode == KEY_ESC)
		close_window(param);
	else if (keycode == KEY_LEFT)
		param->offset_x -= (double)MOVE_MAG / param->zoom;
	else if (keycode == KEY_RIGHT)
		param->offset_x += (double)MOVE_MAG / param->zoom;
	else if (keycode == KEY_UP)
		param->offset_y -= (double)MOVE_MAG / param->zoom;
	else if (keycode == KEY_DOWN)
		param->offset_y += (double)MOVE_MAG / param->zoom;
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
