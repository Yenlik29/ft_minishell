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

char		*ft_pwd0(char **envp, char *pwd)
{
	int		i;
	int		flag;
	char	*buf;

	i = 0;
	flag = 0;
	buf = NULL;
	while (envp[i])
	{
		if ((ft_strnequ(envp[i], "HOME", 4)) == 1)
		{
			flag = 1;
			pwd = ft_strdup(ft_strchr(envp[i], '=') + 1);
		}
		i++;
	}
	if (flag == 0)
		pwd = ft_join_f("", getcwd(buf, 1024));
	return (pwd);
}

char		*ft_look(char **envp, char *pwd, char *find)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (envp[i])
	{
		if (ft_strnequ(envp[i], find, ft_strlen(find)))
		{
			flag = 1;
			pwd = ft_strdup(ft_strchr(envp[i], '=') + 1);
		}
		i++;
	}
	if (flag == 0)
		ft_not_set(find);
	return (pwd);
}

char		**ft_envp(char **envp, char *home_path, char *pwd)
{
	int		i;
	int		flag1;
	int		flag2;

	ft_default(&i, &flag1, &flag2);
	while (envp[i])
	{
		if (ft_strnequ(envp[i], "PWD", ft_strlen("PWD")) == 1)
		{
			flag1 = 1;
			envp[i] = ft_change(envp[i], "PWD=", home_path);
		}
		if (ft_strnequ(envp[i], "OLDPWD", ft_strlen("OLDPWD")) == 1)
		{
			flag2 = 1;
			envp[i] = ft_change(envp[i], "OLDPWD=", pwd);
		}
		i++;
	}
	(flag1 == 0) ? envp = ft_pwd(envp, "PWD=", home_path) : NULL;
	(flag2 == 0) ? envp = ft_pwd(envp, "OLDPWD=", pwd) : NULL;
	return (envp);
}

char		**ft_change_envp1(char **envp, char *home, char *cur, char *old)
{
	int		ret;
	int		j;
	char	*buf;

	j = 0;
	buf = NULL;
	ret = ft_find(envp, "HOME");
	if (ret == 1)
		envp = ft_envp(envp, home, old);
	else
		envp = ft_envp(envp, cur, cur);
	return (envp);
}
