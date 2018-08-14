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

char		*ft_read_dir(char *path, char **command, char **envp, char *c_path)
{
	DIR				*dir;
	struct dirent	*entry;

	if ((dir = opendir(path)) != NULL)
	{
		while ((entry = readdir(dir)) != NULL)
		{
			if (!(ft_strcmp(entry->d_name, command[0])))
			{
				c_path = ft_strjoin(path, "/");
				c_path = ft_strncat(c_path, entry->d_name, ft_strlen(entry->d_name));
				execve(c_path, command, envp);
			}
		}
		closedir(dir);
	}
	return (c_path);
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
}