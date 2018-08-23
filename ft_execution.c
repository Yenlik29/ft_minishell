/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:11:32 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/23 12:11:33 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char		*ft_read_dir(char *path, char **command, char **envp, char *c_p)
{
	DIR				*dir;
	struct dirent	*entry;

	if ((dir = opendir(path)) != NULL)
	{
		while ((entry = readdir(dir)) != NULL)
		{
			if (!(ft_strcmp(entry->d_name, command[0])))
			{
				c_p = ft_strjoin(path, "/");
				c_p = ft_strncat(c_p, entry->d_name, ft_strlen(entry->d_name));
				execve(c_p, command, envp);
			}
		}
		closedir(dir);
	}
	return (c_p);
}

void		ft_exec_sys(char **path, char **command, char **envp)
{
	int		i;
	char	*c_path;

	i = 0;
	c_path = NULL;
	if (ft_if_path(command) == 1)
	{
		if (execve(command[0], command, envp) == -1)
		{
			ft_putstr_fd("minishell: permission denied: ", 2);
			ft_putstr_fd(command[0], 2);
			ft_putchar_fd('\n', 2);
		}
	}
	else
	{
		while (path[i])
		{
			c_path = ft_read_dir(path[i], command, envp, c_path);
			i++;
		}
		if (c_path == NULL)
			ft_command_not_found(command[0]);
	}
	(c_path != NULL) ? free(c_path) : NULL;
}
