/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:12:30 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 13:48:07 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

char	*ft_delete_space(const char *str)
{
	int		i;
	int		start;
	char	*str2;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	start = i;
	while (!(ft_isspace(str[i])) && str[i])
		i++;
	str2 = ft_substr(str, start, i - start);
	if (!str2)
		exit(1);
	return (str2);
}
