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

char			*ft_join_f2(char *s1, char *s2)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	return (tmp);
}

size_t			word_count(char const *s, char c)
{
	size_t i;
	size_t wd;

	i = 0;
	wd = 0;
	while (s[i])
	{
		if (s[i] != c)	
			wd++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (wd);
}