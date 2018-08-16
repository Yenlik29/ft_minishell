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
	if (home[0] == '\0')
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
				temp = ft_join_f2(temp, ft_strchr(env[j], '=') + 1);
			j++;
		}
		if (!(ft_strcmp(new[i], "$")))
			temp = ft_join_f2(temp, "$");
		if (!(ft_strcmp(new[i], "<")) || !(ft_strcmp(new[i], ">")))
			ft_parse_error();
		i++;
	}
	word = ft_strcpy(word, temp);
	(temp != NULL) ? free(temp) : NULL;
	return (word);
}

char			*ft_dollar(char **env, char *word)
{
	int		i;
	char	**new;

	i = 0;
	new = str_split(word, '$');
	ft_bzero(word, ft_strlen(word));
	word = ft_environments(word, new, env);
	return (word);
}

char		*ft_tilda(char **env, char *word)
{
	int		i;
	int		count;
	char	*home;
	char	*temp;

	i = 0;
	count = 0;
	home = NULL;
	while (env[i])
	{
		if (ft_strnequ(env[i], "HOME", ft_strlen("HOME")) == 1)
		{
			count++;
			home = ft_strdup(ft_strchr(env[i], '=') + 1);
		}
		i++;
	}
	if (count == 0)
	{
		home = (char *)malloc(sizeof(char) * 1024);
		ft_bzero(home, ft_strlen(home));
	}
	temp = ft_strjoin(home, ft_strchr(word, '~') + 1);
	word = ft_strcpy(word, temp);
	return (word);
}