/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:03:07 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/09 14:06:26 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	int				i;
	unsigned char	word;

	str = (char *)s;
	word = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == word)
			return (&str[i]);
		i++;
	}
	if (word == '\0')
		return (&str[i]);
	return (0);
}