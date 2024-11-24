/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:36:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/05 15:31:39 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

void close_window2(t_data *data)
{
	close_window(data);
	exit(0);
}

int close_window(t_data *data)
{
	if (!data)
		exit(0);
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win); // ウィンドウを破棄
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx); // ディスプレイを破棄
		free(data->mlx);
		data->mlx = NULL;
	}
	exit(0);
	return (0);
}

# TODO review this calculation 
static void	change_centered(t_data *i, int x, int y)
{
	i->offset_x = (x - WIDTH / 2.0) * (F_RAN / WIDTH) / i->zoom + i->offset_x;
	i->offset_y = (y - HEIGHT / 2.0) * (F_RAN / HEIGHT) / i->zoom + i->offset_y;
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*img;

	img = (t_data *)param;
	if (button == MOUSE_WHEEL_UP)
		img->zoom *= ZOOM_MAG;
	else if (button == MOUSE_WHEEL_DOWN)
		img->zoom /= ZOOM_MAG;
	else if (button == MOUSE_LEFT_CLICK)
		change_centered(img, x, y);
	else
		return (0);
	mlx_clear_window(img->mlx, img->win);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_data	*img;

	img = (t_data *)param;
	if (keycode == KEY_ESC)
		close_window(img);
	else if (keycode == KEY_LEFT)
		img->offset_x -= (double)MOVE_MAG / img->zoom;
	else if (keycode == KEY_RIGHT)
		img->offset_x += (double)MOVE_MAG / img->zoom;
	else if (keycode == KEY_UP)
		img->offset_y -= (double)MOVE_MAG / img->zoom;
	else if (keycode == KEY_DOWN)
		img->offset_y += (double)MOVE_MAG / img->zoom;
	else if (keycode == KEY_C)
		img->color_flg = 10;
	else if (keycode == KEY_B)
		img->color_flg = 1;
	else
		return (0);
	mlx_clear_window(img->mlx, img->win);
	return (0);
}
