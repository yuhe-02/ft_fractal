/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:40:40 by yyamasak          #+#    #+#             */
/*   Updated: 2024/10/08 13:38:20 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_complex	ft_complex_div(t_complex z1, t_complex z2)
{
	t_complex	result;
	double		denominator;

	denominator = z2.real * z2.real + z2.imag * z2.imag;
	if (denominator == 0)
	{
		result.real = INFINITY;
		result.imag = INFINITY;
	}
	else
	{
		result.real = (z1.real * z2.real + z1.imag * z2.imag) / denominator;
		result.imag = (z1.imag * z2.real - z1.real * z2.imag) / denominator;
	}
	return (result);
}
