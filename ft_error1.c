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

void				ft_illegal_env_opt(char c)
{
	ft_putstr_fd("env: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: env [-u name]\n", 2);
}

void				ft_opt_require_arg(char c)
{
	ft_putstr_fd("env: option requires an argument -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
}

void				ft_parse_error(void)
{
	ft_putstr_fd("minishell: parse error \\n\n", 2);
}

void				ft_wrong_quantity_env(void)
{
	ft_putstr_fd("env: wrong quantyti\n", 2);
}

void				ft_command_not_found(char *command)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(command, 2);
	ft_putchar_fd('\n', 2);
}
