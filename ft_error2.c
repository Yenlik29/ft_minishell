/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:37:10 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/16 14:37:13 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void				ft_no_such_file_env_1(char *w_splited)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(w_splited, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void				ft_permission_env(char *w_splited)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(w_splited, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}
