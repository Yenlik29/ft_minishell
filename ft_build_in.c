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

void			ft_env(char **w_splited, char **envp)
{
	int i;

	i = 0;
	if (len_env(w_splited) == 1)
	{
		while (envp[i])
		{
			ft_putendl(envp[i]);
			i++;
		}
	}
	if (len_env(w_splited) > 3)
		ft_wrong_quantity_env();
	if (len_env(w_splited) == 2 || len_env(w_splited) == 3)
		ft_parse_env(w_splited, envp);
}

char			**ft_exec_buil_in(char **w_splited, char **envp)
{
	if (!(ft_strcmp(w_splited[0], "cd")))
		envp = ft_cd(w_splited, envp);
	// if (!(ft_strcmp(w_splited[0], "setenv")))
	// 	envp = ft_setenv(w_splited, envp);
	// if (!(ft_strcmp(w_splited[0], "unsetenv")))
	// 	envp = ft_unsetenv(w_splited, envp);
	if (!(ft_strcmp(w_splited[0], "env")))
		ft_env(w_splited, envp);
	// if (!(ft_strcmp(w_splited[0], "echo")))
	// 	ft_echo(w_splited, envp);
	if (!(ft_strcmp(w_splited[0], "exit")))
		exit(0);
	return (envp);
}
