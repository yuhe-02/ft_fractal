/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:08:43 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/30 00:13:53 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_complex	ft_cpow(t_complex z, double power)
{
	double		r;
	double		theta;
	double		r_n;
	double		theta_n;
	t_complex	result;

	r = sqrt(z.real * z.real + z.imag * z.imag);
	theta = atan2(z.imag, z.real);
	r_n = pow(r, power);
	theta_n = theta * power;
	result.real = r_n * cos(theta_n);
	result.imag = r_n * sin(theta_n);
	return (result);
}

// t_complex	ft_cpow(t_complex z, double power)
// {
//     t_complex  res;

//     res.real = 1;
//     res.imag = 0;
//     while (power > 0)
//     {
//         res = ft_complex_mul(res, z);
//         power--;
//     }
//     return (res);
// }