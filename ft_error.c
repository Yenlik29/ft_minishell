/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:03:22 by ybokina           #+#    #+#             */
/*   Updated: 2018/06/14 21:03:22 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void			ft_parse_error(void)
{
	ft_putstr_fd("minishell: parse error \\n\n", 2);
}

void				ft_command_not_found(char *command)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(command, 2);
	ft_putchar_fd('\n', 2);
}
