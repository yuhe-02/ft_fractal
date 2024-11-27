/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:50:20 by yyamasak          #+#    #+#             */
/*   Updated: 2024/11/27 14:11:28 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	validate_params(char **argv, int param_num, int start_index)
{
	while (start_index < param_num)
	{
		if (!(ft_is_valid_num(argv[start_index])))
			return (FT_FALSE);
		start_index++;
	}
	return (FT_TRUE);
}

int	check_params(int ac, char **av)
{
	if (ac != 4)
	{
		display_errorlog("", FT_TRUE);
		return (FT_FALSE);
	}
	if (!validate_params(av, 2, 2))
	{
		display_errorlog("ft_fractol: invalid parameter\n", FT_TRUE);
		return (FT_FALSE);
	}
	return (FT_TRUE);
}
