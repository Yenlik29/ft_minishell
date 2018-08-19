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

char		**ft_word(char **word, char **env)
{
	int j;

	j = 0;
	while (word[j])
	{
		if ((word[j][0] == '~' && word[j][1] == '\0') || (word[j][0] == '~' && word[j][1] == '/'))
			word[j] = ft_tilda(env, word[j]);
		if (ft_env_check(word[j]) == 1)
			word[j] = ft_dollar(env, word[j]);
		j++;
	}
	return (word);
}

char		**parsed_word(char **word, char **env)
{
	word = ft_word(word, env);
	return (word);
}

char			**str_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**w;

	i = 0;
	k = 0;
	if (!s || !(w = (char **)malloc(sizeof(char *) * 4096)))
		return (NULL);
	if (s[0] == c && !s[k + 1])
	{
		w[0] = (char*)(malloc(sizeof(char) * 2));
		w[0][0] = c;
		w[0][1] = '\0';
		return (w);
	}
	while (i < word_count(s, c))
	{
		j = 0;
		if (!(w[i] = (char *)malloc(sizeof(char) * 4096)))
			return (NULL);
		while (s[k] == c && s[k + 1])
			k++;
		while (s[k] != c && s[k])
			w[i][j++] = s[k++];
		while (s[k] == c)
			k++;
		if (s[k] == c && s[k + 1] == '\0')
		{
			i++;
			j = 0;
			if (!(w[i] = (char *)malloc(sizeof(char) * 4096)))
				return (NULL);
			w[i][j] = c;
			j++;
			k++;
		}
		w[i][j] = '\0';
		i++;
	}
	w[i] = NULL;
	return (w);
}

char			**split_word(char *word)
{
	char	**command;
	char	*sentence;

	sentence = NULL;
	command = NULL;
	sentence = (char *)malloc(sizeof(char) * 4096);
	sentence = ft_check(sentence, word, '\t');
	command = str_split(sentence, ' ');
	return (command);
}

char			**read_line(char **env)
{
	char			ch;
	ssize_t			ret;
	char			*word;
	int				i;
	char			**w_splited;

	i = 0;
	ret = 0;
	word = ft_strnew(1);
	while ((ret = read(0, &ch, 1) && ch != '\n') > 0)
		word = ft_strncat(word, &ch, 1);
	w_splited = split_word(word);
	w_splited = parsed_word(w_splited, env);
	if (word != NULL)
		free(word);
	return (w_splited);
}