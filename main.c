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

void			sighandler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr("\n");
		display_prompt();
		signal(SIGINT, sighandler);
	}
}

int				main(int argc, char **argv, char **envp)
{
	char	**env;
	char	**w_splited;

	env = (char **)malloc(sizeof(char *) * 1024);
	env = envp_create(env, envp);
	while (42)
	{
		w_splited = NULL;
		display_prompt();
		signal(SIGINT, sighandler);
		w_splited = read_line(env, w_splited);
		if (w_splited[0] != NULL)
		{
			env = ft_core(w_splited, env);
		}
		free_2darray(&w_splited);
	}
	argv = NULL;
	argc = 0;
	return (0);
}
