/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:36:14 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/17 16:36:23 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char				**ft_new_envp(char **envp, char *new)
{
	envp[len_env(envp)] = ft_strdup(new);
	envp[len_env(envp)] = NULL;
	return (envp);
}