/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_diff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:40:40 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 10:41:45 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_complex	ft_complex_diff(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.real = z1.real - z2.real;
	z.imag = z1.imag - z2.imag;
	return (z);
}