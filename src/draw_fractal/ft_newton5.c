/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:43:22 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 15:01:18 by yyamasak         ###   ########.fr       */
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

t_coord	*calc_newton5_set(t_data *img, int x, int y)
{
	t_coord			*cd;
	int				iterations;
	t_complex		z;
	t_complex		root;

	cd = (t_coord *)malloc(sizeof(t_coord));
	if (!cd)
		exit(1);
	z.real = (x - WIDTH / 2.0) * (F_RAN / WIDTH) / img->zoom + img->offset_x;
	z.imag = (y - HEIGHT / 2.0) * (F_RAN / HEIGHT) / img->zoom + img->offset_y;
	root = root_of_func(z, &iterations, img->param1, img->param2);
	cd->cx = z.real;
	cd->cy = z.imag;
	cd->zx = root.real;
	cd->zy = root.imag;
	cd->iterations = iterations;
	return (cd);
}
