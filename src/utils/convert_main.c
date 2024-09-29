/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:18:35 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 16:27:20 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractal.h"

int	main(int argc, char **argv)
{
	int			count;
	char		*message1;
	char		*message2;
	const char	*test_cases[] = {
		"0.00",
		"34.0",
		"-0.00",
		"0,23",
		"1000000000000000000000000000000",
		"12.0002",
		"-12.0002",
		"0.03002333",
		"12.2",
		"-12.0002",
		" 167856782.0002 ",
		" 0.0001",
		"-0.0001",
		"1e5",
		"-1e-5",
		"inf",
		"-inf",
		"NaN",
		"",
		"123abc",
		"abc123",
		"1.0.1",
		"00001.234",
		"-00001.234",
		"+00001.234",
		"1.234e10",
		"-1.234e-10",
		"324908239048.93849389",
		"-1",
		NULL
	};

	count = 0;
	message1 = "[handmade] before: [%s] after: [%f]\n";
	message2 = "[origin] before: [%s] after: [%f]\n";
	while (test_cases[count])
	{
		if (ft_is_valid_num(test_case[count]))
		{
			if (handmade != origin)
			{
				printf("%d: ×\n", count);
				printf(message1, test_case[count], ft_atob(test_case[count]));
				printf(message2, test_case[count], atof(test_case[count]));
			}
			else
			{
				printf("%d: ○\n", count);
			}
		}
		else
			printf("invalid: %s\n", test_case[count]);
		count++;
	}
	return (0);
}
