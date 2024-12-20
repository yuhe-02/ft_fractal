/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:08:26 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 13:48:07 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static double	convert_int(const char *str, int len)
{
	double	ans;
	int		i;

	i = 0;
	ans = 0;
	while (i < len)
	{
		ans = ans * 10 + (double)(str[i] - '0');
		i++;
	}
	return (ans);
}

static double	convert_fraction(const char *str)
{
	double	ans;
	int		len;

	len = ft_strlen((char *)str);
	ans = 0;
	while (len)
	{
		ans = ans / 10 + (double)(str[len - 1] - '0');
		len--;
	}
	return (ans / 10);
}

double	ft_atob(const char *str)
{
	double	ans;
	char	*dot_pos;
	char	*str2;
	int		minus_flg;

	str2 = ft_delete_space(str);
	minus_flg = FT_FALSE;
	if (*str2 == '-')
		minus_flg = FT_TRUE;
	dot_pos = ft_strchr(str2, '.');
	if (!dot_pos || !*dot_pos)
		ans = convert_int(str2 + minus_flg, ft_strlen(str2 + minus_flg));
	else
	{
		ans = convert_int(str2 + minus_flg, dot_pos - str2 - minus_flg);
		ans += convert_fraction(dot_pos + 1);
	}
	free(str2);
	if (minus_flg)
		ans = -ans;
	return (ans);
}
