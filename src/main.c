/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:18 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/02 14:20:13 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	set_hooks(t_param *param)
{
	mlx_hook(param->win, WINDOW_CLOSE, 0, close_window, param);
	mlx_key_hook(param->win, key_hook, param);
	mlx_mouse_hook(param->win, mouse_hook, param);
}

int	main_loop(t_param *param)
{
	if (param->cur_iter <= param->max_iter)
	{
		draw_fractol(param);
		mlx_put_image_to_window(param->mlx, param->win, param->data.img, 0, 0);
		param->cur_iter += 10;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;

	if (!check_params(argc, argv))
		return (1);
	if (!set_shape_param(&param, argv))
		return (1);
	initialize_param(&param);
	set_hooks(&param);
	mlx_loop_hook(param.mlx, &main_loop, &param);
	mlx_loop(param.mlx);
	return (0);
}
