/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 09:49:10 by rklein            #+#    #+#             */
/*   Updated: 2020/06/17 10:53:49 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_findslash(char *str)
{
	while (*str)
	{
		if (*str == 47)
			return (1);
		str++;
	}
	return (0);
}

int	ft_spacetab(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

