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

char 		**ft_envp(char **envp, char *home_path, char *pwd)
{
	int 	i;
	int		flag1;
	int		flag2;
	char	*temp;

	i = 0;
	flag1 = 0;
	flag2 = 0;
	while (envp[i])
	{
		if (ft_strnequ(envp[i], "PWD", ft_strlen("PWD")) == 1)
		{
			flag1 = 1;
			temp = ft_strjoin("PWD=", home_path);
			envp[i] = ft_strcpy(envp[i], temp);
			(temp != NULL) ? free(temp) : NULL;
		}
		if (ft_strnequ(envp[i], "OLDPWD", ft_strlen("OLDPWD")) == 1)
		{
			flag2 = 1;
			temp = ft_strjoin("OLDPWD=", pwd);
			envp[i] = ft_strcpy(envp[i], temp);
			(temp != NULL) ? free(temp) : NULL;
		}
		i++;
	}
	if (flag1 == 0)
		envp = ft_pwd(envp, "PWD=", home_path);
	if (flag2 == 0)
		envp = ft_pwd(envp, "OLDPWD=", pwd);
	return (envp);
}

char		**ft_change_envp1(char **envp, char *home_path, char *cur_pwd, char *old_pwd)
{
	int		ret;
	int		j;
	char	*buf;
	char	*temp;

	j = 0;
	buf = NULL;
	temp = NULL;
	ret = ft_find(envp, "HOME");
	if (ret == 1)
		envp = ft_envp(envp, home_path, old_pwd);
	else
		envp = ft_envp(envp, cur_pwd, cur_pwd);
	return (envp);
}