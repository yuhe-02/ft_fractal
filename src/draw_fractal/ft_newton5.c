/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:43:22 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/24 16:10:59 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static	t_complex	newton_method(t_complex z,
									double power, double section)
{
	t_complex	f;
	t_complex	df;
	t_complex	res;

	f = ft_cpow(z, power);
	f.real += section;
	// printf("f    : %f + %fi\n", f.real, f.imag);
	df = ft_complex_mul_st(ft_cpow(z, power - 1), power);
	// printf("df   : %f + %fi\n", df.real, df.imag);
	if (df.real == 0 && df.imag == 0)
		return (z);
	res = ft_complex_diff(z, ft_complex_div(f, df));
	// printf("res  : %f + %fi\n", res.real, res.imag);
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
		// printf("z_new: %f + %fi\n", z_new.real, z_new.imag);
		eps = ft_cabs(ft_complex_diff(z_new, z));
		if (eps < EPS)
			break ;
		z = z_new;
		counter++;
	}
	*iterations = counter;
	return (z_new);
}

t_param *calc_newton5_set(t_param *param, int x, int y)
{
	int				iterations;
	t_complex		z;
	t_complex		root;

	z.real = (x - WIDTH / 2.0) * (F_RAN / WIDTH) / param->zoom + param->offset_x;
	z.imag = (y - HEIGHT / 2.0) * (F_RAN / HEIGHT) / param->zoom + param->offset_y;
	root = root_of_func(z, &iterations, param->param1, param->param2);
	param->c_re = z.real;
	param->c_im = z.imag;
	param->z_re = root.real;
	param->c_im = root.imag;
	param->iteration = iterations;
	return (param);
}
