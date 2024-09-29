/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 07:02:06 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 07:11:11 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	char 	*str;
	int		i;

	str = " \t\n\r\v\f";
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	printf("expect:%d real:%d\n", 1, ft_isspace('\n'));
// 	printf("expect:%d real:%d\n", 1, ft_isspace('\t'));
// 	printf("expect:%d real:%d\n", 1, ft_isspace('\r'));
// 	printf("expect:%d real:%d\n", 1, ft_isspace('\v'));
// 	printf("expect:%d real:%d\n", 1, ft_isspace('\f'));
// 	printf("expect:%d real:%d\n", 0, ft_isspace('\0'));
// 	printf("expect:%d real:%d\n", 0, ft_isspace('a'));
// }