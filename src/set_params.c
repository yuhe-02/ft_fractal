/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:51:02 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/02 14:18:25 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	set_shape_param(t_param *param, char **argv)
{
	param->calc_color = calc_color1;
	param->param1 = 0;
	param->param2 = 0;
	if (ft_strncmp(argv[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
		param->calculator = calc_julia_set;
	else if (ft_strncmp(argv[1], MD_S, ft_strlen(MD_S) + 1) == 0)
		param->calculator = calc_mandelbrot_set;
	else if (ft_strncmp(argv[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
	{
		param->calculator = calc_newton5_set;
		param->calc_color = calc_color2;
	}
	else
	{
		display_errorlog("fractol: invalid nunber\n", FT_FALSE);
		return (FT_FALSE);
	}
	if (ft_strncmp(argv[1], MD_S, ft_strlen(MD_S) + 1) != 0)
	{
		param->param1 = ft_atob(argv[2]);
		param->param2 = ft_atob(argv[3]);
	}
	return (FT_TRUE);
}

void	init_images(t_param *param)
{
	param->max_re = 2;
	param->max_im = 2;
	param->min_re = -2;
	param->min_im = -2;
	param->max_iter = MAX_ITER;
	param->space_flg = FT_FALSE;
	param->iteration = 0;
	param->cur_iter = MAX_ITER / 2;
	param->data.addr = mlx_get_data_addr(param->data.img, &(param->data.bpp),
			&(param->data.llen), &(param->data.eda));
}

void	initialize_param(t_param *param)
{
	param->mlx = mlx_init();
	if (!param->mlx)
		exit(1);
	param->win = mlx_new_window(param->mlx, WIDTH, HEIGHT, "fractol");
	if (!param->win)
		exit(1);
	param->data.img = mlx_new_image(param->mlx,
			WIDTH, HEIGHT);
	if (!param->data.img)
		exit(1);
	param->data.addr = mlx_get_data_addr(param->data.img,
			&param->data.bpp,
			&param->data.llen, &param->data.eda);
	init_images(param);
}
