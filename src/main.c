/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:27:18 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/01 19:07:20 by yyamasak         ###   ########.fr       */
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
	if (param->shift_flg)
		update_fractol_c(param);
	draw_fractol(param);
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
	draw_fractol(&param);
	set_hooks(&param);
	mlx_loop_hook(param.mlx, &main_loop, &param);
	mlx_loop(param.mlx);
	return (0);
}
