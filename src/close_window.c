/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:09 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/26 15:11:03 by yyamasak         ###   ########.fr       */
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

void	update_fractal_c(t_param *param)
{
	int		x;
	int		y;
	double	mouse_re;
	double	mouse_im;

	mlx_mouse_get_pos(param->mlx, param->win, &x, &y);
	if (!x && !y)
		return ;
	mouse_re = (double)x
		/ (WIDTH / (param->max_re - param->min_re)) + param->min_re;
	mouse_im = (double)y
		/ (HEIGHT / (param->max_im - param->min_im)) * -1 + param->max_im;
	param->c_re = mouse_re;
	param->c_im = mouse_im;
}