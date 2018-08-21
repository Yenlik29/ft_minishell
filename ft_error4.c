/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybokina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 10:17:34 by ybokina           #+#    #+#             */
/*   Updated: 2018/08/18 10:17:45 by ybokina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void				ft_quote_error(int q)
{
	ft_putstr_fd("minishell: quote error: ", 2);
	ft_putnbr_fd(q, 2);
	ft_putstr_fd(" quantity\n", 2);
}
