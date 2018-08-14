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

char			**ft_path(char **env)
{
	char	*path;
	char	**path_del;
	int		i;

	i = 0;
	while (env[i])
	{
		if ((ft_strnequ(env[i], "PATH", 4)) == 1)
			path = ft_strsub(env[i], 5, ft_strlen(env[i]));
		i++;
	}
	path_del = str_split(path, ':');
	return (path_del);
}

int				ft_if_path(char **command)
{
	int i;

	i = 0;
	while (command[0][i])
	{
		if (command[0][i] == '/')
			return (1);
		i++;
	}
	return (0);
}
