/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:10:20 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 13:48:07 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(src + i))
		i++;
	if (!n)
		return (i);
	while (j < n - 1 && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}
