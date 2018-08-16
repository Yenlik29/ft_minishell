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

void			free_3var(char *var1, char *var2, char *var3)
{
	if (var1 != NULL)
		free(var1);
	if (var2 != NULL)
		free(var2);
	if (var3 != NULL)
		free(var3);
}

void			free_2var(char *home_path, char *cur_pwd)
{
	if (home_path != NULL)
		free(home_path);
	if (cur_pwd != NULL)
		free(cur_pwd);
}

void			free_2darray(char ***str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		++i;
	}
	free(*str);
	**str = NULL;
}
