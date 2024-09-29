/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton5_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:43:22 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 12:08:08 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

static	double	complex	newton_method(double complex z,
									double power, double section)
{
	double complex	f;
	double complex	df;

	f = cpow(z, power) + section;
	printf("f    : %f + %fi\n", creal(f), cimag(f));
	df = power * cpow(z, power - 1);
	printf("df   : %f + %fi\n", creal(df), cimag(df));
	if (creal(df) != 0 || cimag(df) != 0)
		return (z - f / df);
	else
		return (z);
}

static	double	complex	root_of_func(double complex z,
								int *iterations, double power, double section)
{
	int				counter;
	double complex	z_new;
	double			eps;

	counter = 0;
	while (counter < MAX_ITER)
	{
		z_new = newton_method(z, power, section);
		eps = cabs(z_new - z);
		printf("z_new: %f + %fi\n", creal(z_new), cimag(z_new));
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
	double complex	z;
	double complex	root;

	cd = (t_coord *)malloc(sizeof(t_coord));
	if (!cd)
		exit(1);
	cd->zx = (x - WIDTH / 2.0) * (F_RAN / WIDTH) / img->zoom + img->offset_x;
	cd->cx = (y - HEIGHT / 2.0) * (F_RAN / HEIGHT) / img->zoom + img->offset_y;
	z = cd->zx + cd->cx * I;
	root = root_of_func(z, &iterations, img->param1, img->param2);
	cd->cx = creal(z);
	cd->cy = cimag(z);
	cd->zx = creal(root);
	cd->zy = cimag(root);
	cd->iterations = iterations;
	return (cd);
}
