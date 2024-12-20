/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:50:20 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/04 11:59:54 by yyamasak         ###   ########.fr       */
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
	if (ac == 4 && ft_strncmp(av[1], JULIA_S, ft_strlen(JULIA_S) + 1) == 0)
	{
		if (validate_params(av, 4, 2))
			return (FT_TRUE);
	}
	else if (ac == 2 && ft_strncmp(av[1], MD_S, ft_strlen(MD_S) + 1) == 0)
		return (FT_TRUE);
	else if (ac == 2 && ft_strncmp(av[1], BONUS_S, ft_strlen(BONUS_S) + 1) == 0)
		return (FT_TRUE);
	display_errorlog("fractol: invalid parameter\n", FT_TRUE);
	return (FT_FALSE);
}
