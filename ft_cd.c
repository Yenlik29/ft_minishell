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

char			**ft_cd_one(char *w_splited, char **envp)
{
	char	*buf;
	int		i;
	int		flag;
	char	*pwd;

	i = 0;
	flag = 0;
	buf = NULL;
	pwd = NULL;
	if (w_splited[0] == '\0')
	{
		while (envp[i])
		{
			if ((ft_strnequ(envp[i], "HOME", 4)) == 1)
			{
				flag = 1;
				pwd = ft_strdup(ft_strchr(envp[i], '=') + 1);
			}
			i++;
		}
	}
	if (flag == 0)
		pwd = ft_join_f("", getcwd(buf, 1024));
	// if (!(w_splited[0] == '-' && ft_strlen(w_splited) == 1) &&
	// (!(w_splited[0] == '-' && w_splited[1] == '-' &&
	// ft_strlen(w_splited) == 2)))
	// {
	// 	if (ft_parsed_cd(w_splited) == 1)
	// 		envp = ft_chdir(w_splited, envp);
	// }
	// else
	// 	envp = ft_chdir(w_splited, envp);
	// if (buf != NULL)
	// 	free(buf);
	return (envp);
}

char			**ft_only_cd(char **envp)
{
	char	*home_path;
	char	*cur_pwd;
	char	*old_pwd;
	char	*buf;

	buf = NULL;
	cur_pwd = NULL;
	home_path = ft_home(envp);
	old_pwd = ft_join_f("", getcwd(buf, 1024));
	if (home_path[0] == '\0')
		home_path = ft_join_f("", getcwd(buf, 1024));
	if (chdir(home_path) != 0)
	{
		ft_putstr_fd("chdir() failed\n", 2);
		return (envp);
	}
	cur_pwd = ft_join_f("", getcwd(buf, 1024));
	envp = ft_change_envp1(envp, home_path, cur_pwd, old_pwd);
	free_3var(home_path, cur_pwd, old_pwd);
	return (envp);
}

char			**ft_cd(char **w_splited, char **envp)
{
	char	*buf;
	int		len;

	buf = NULL;
	len = len_env(w_splited);
	if (len == 2)
		envp = ft_cd_one(w_splited[1], envp);
	// if (len == 3)
	// 	envp = ft_cd_two(w_splited, envp);
	if (len > 3)
		ft_putstr_fd("cd: too many arguments\n", 2);
	if (len == 1)
		envp = ft_only_cd(envp);
	return (envp);
}