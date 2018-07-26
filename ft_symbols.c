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

// void			ft_dollar_c(char **env, char **word, int *count, char **home)
// {
// 	int		i;
// 	char	*var;

// 	i = 0;
// 	var = ft_strdup(ft_strchr(*word, '$') + 1);
// 	while (env[i])
// 	{
// 		if (ft_strnequ(env[i], var, ft_strlen(var)) == 1)
// 		{
// 			count++;
// 			*word = ft_dollar_1(*word, env[i]);
// 		}
// 		if (ft_strnequ(env[i], "HOME", ft_strlen("HOME")) == 1)
// 			*home = ft_strdup(ft_strchr(env[i], '=') + 1);
// 		i++;
// 	}
// 	(var != NULL) ? free(var) : NULL;
// }

char			*ft_home(char **env)
{
	char	*home;
	int		i;

	i = 0;
	if (!(home = (char *)malloc(sizeof(char) * 1024)))
		return (NULL);
	while (env[i])
	{
		if (ft_strnequ(env[i], "HOME", ft_strlen("HOME")) == 1)
			home = ft_strcpy(home, ft_strchr(env[i], '=') + 1);
		i++;
	}
	if (home == NULL)
		ft_bzero(home, ft_strlen(home));
	return (home);
}

char			*ft_environments(char *word, char **new, char **env)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	temp = ft_strnew(1);
	while (new[i])
	{
		j = 0;
		while (env[j])
		{
			if (ft_strnequ(new[i], env[j], ft_strlen(new[i])) == 1)
			{
				temp = ft_join_f2(temp, ft_strchr(env[j], '=') + 1);
			}
			j++;
		}
		if (!(ft_strcmp(new[i], "$")))
			temp = ft_join_f2(temp, "$");
		i++;
	}
	printf("->%s\n", temp);
	// while (env[i])
	// {
	// 	j = 0;
	// 	while (new[j])
	// 	{
	// 		if (ft_strnequ(env[i], new[j], ft_strlen(new[j])) == 1)
	// 		{
	// 			temp = ft_join_f2(temp, ft_strchr(env[i], '=') + 1);
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	if (temp != NULL)
		free(temp);
	return (word);
}

char			*ft_dollar(char **env, char *word)
{
	char	*home;
	int		i;
	int		count;
	char	**new;

	i = 0;
	count = 0;
	home = NULL;
	home = ft_home(env);
	new = str_split(word, '$');
	while (new[i])
	{
		printf("->%s\n", new[i]);
		i++;
	}
	ft_bzero(word, ft_strlen(word));
	word = ft_environments(word, new, env);
	//ft_dollar_c(env, &word, &count, &home);
	// if (count == 0 && (word[1] != '<' && word[1] != '>'))
	// {
	// 	*sign = 0;
	// 	if (home != NULL)
	// 	{
	// 		env = ft_new_envp(word, env, flag);
	// 	}
	// }
	// (home != NULL) ? free(home) : NULL;
	return (word);
}

char		*ft_tilda(char **env, char *word)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], "HOME", ft_strlen("HOME")) == 1)
		{
			count++;
			ft_bzero(word, ft_strlen(word));
			word = ft_join_f2(word, (ft_strchr(env[i], '=') + 1));
			return (word);
		}
		i++;
	}
	if (count == 0)
		ft_bzero(word, ft_strlen(word));
	return (word);
}