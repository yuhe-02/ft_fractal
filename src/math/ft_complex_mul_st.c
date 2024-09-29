/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_mul_st.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:40:40 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 10:50:46 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

t_complex	ft_complex_mul_st(t_complex z1, double st_value)
{
	t_complex	z;

	z.real = z1.real * st_value;
	z.imag = z1.imag * st_value;
	return (z);
}