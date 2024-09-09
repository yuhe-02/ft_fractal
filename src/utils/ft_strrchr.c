/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:59:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/09 14:06:57 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	int				i;
	unsigned char	word;

	str = (char *)s;
	word = (unsigned char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == word)
			return (&str[i]);
		i--;
	}
	return (0);
}