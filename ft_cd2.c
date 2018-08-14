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

char 		**ft_with_envp(char **envp, char *home_path, char *cur_pwd)
{
	int 	i;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strnequ(envp[i], "PWD", ft_strlen("PWD")) == 1)
		{
			temp = ft_strjoin("PWD=", home_path);
			envp[i] = ft_strcpy(envp[i], temp);
			printf("->%s\n", envp[i]);
			(temp != NULL) ? free(temp) : NULL;
		}
		i++;
	}
	cur_pwd = NULL;
	return (envp);
}

char		**ft_change_envp1(char **envp, char *home_path, char *cur_pwd)
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
		envp = ft_with_envp(envp, home_path, cur_pwd);
	// else if (ret == 0)
	// 	envp = ft_without_envp(cur_pwd);
	// while (envp[j])
	// {
	// 	if (ft_strnequ(envp[j], "PWD", ft_strlen("PWD")) == 1)
	// 	{
	// 		temp = ft_join_f("PWD=", getcwd(buf, 1024));
	// 		envp[j] = ft_strcpy(envp[j], temp);
	// 		if (temp != NULL)
	// 			free(temp);
	// 	}
	// 	if (ft_strnequ(envp[j], "OLDPWD", ft_strlen("OLDPWD")) == 1)
	// 		envp[j] = ft_oldpwd(envp[j], cur_pwd);
	// 	j++;
	// }
	return (envp);
}