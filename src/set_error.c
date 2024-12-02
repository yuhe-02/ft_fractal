/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:26:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/01 15:27:55 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	ft_help_sentence(int file_des)
{
	(void)write(file_des, SENTENCE1, ft_strlen(SENTENCE1));
	(void)write(file_des, SENTENCE2, ft_strlen(SENTENCE2));
	(void)write(file_des, SENTENCE3, ft_strlen(SENTENCE3));
	(void)write(file_des, SENTENCE4, ft_strlen(SENTENCE4));
}

void	display_errorlog(char *message, int is_put_sample)
{
	(void)write(1, message, ft_strlen(message));
	if (is_put_sample)
		ft_help_sentence(1);
}

void	set_error(char *message, int is_put_sample, int exit_no)
{
	write(1, message, ft_strlen(message));
	if (is_put_sample)
		ft_help_sentence(1);
	exit(exit_no);
}
