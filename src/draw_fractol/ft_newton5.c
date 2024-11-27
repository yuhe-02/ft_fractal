/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:43:22 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 14:13:29 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static	t_complex	newton_method(t_complex z,
									double power, double section)
{
	t_complex	f;
	t_complex	df;
	t_complex	res;

	f = ft_cpow(z, power);
	f.real += section;
	df = ft_complex_mul_st(ft_cpow(z, power - 1), power);
	if (df.real == 0 && df.imag == 0)
		return (z);
	res = ft_complex_diff(z, ft_complex_div(f, df));
	return (res);
}

static	t_complex	root_of_func(t_complex z,
								int *iterations, double power, double section)
{
	int				counter;
	t_complex		z_new;
	double			eps;

	counter = 0;
	while (counter < MAX_ITER)
	{
		z_new = newton_method(z, power, section);
		eps = ft_cabs(ft_complex_diff(z_new, z));
		if (eps < EPS)
			break ;
		z = z_new;
		counter++;
	}
	*iterations = counter;
	return (z_new);
}

t_param	*calc_newton5_set(t_param *param, int x, int y)
{
	int				iterations;
	t_complex		z;
	t_complex		root;

	z.imag = param->min_im + y * param->delta_im;
	z.real = param->min_re + x * param->delta_re;
	root = root_of_func(z, &iterations, param->param1, param->param2);
	param->c_re = z.real;
	param->c_im = z.imag;
	param->z_re = root.real;
	param->c_im = root.imag;
	param->iteration = iterations;
	return (param);
}
