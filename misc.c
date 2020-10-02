/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 09:49:10 by rklein            #+#    #+#             */
/*   Updated: 2020/07/13 10:56:06 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_findslash(char *str)
{
	while (*str)
	{
		if (*str == 47)
			return (1);
		str++;
	}
	return (0);
}

int		ft_spacetab(char c)
{
	return (c == ' ' || c == '\t' ? 1 : 0);
}

char	**ft_arrcpy(char **src)
{
	char	**dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(dst = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = ft_strdup(src[i]);
	dst[i] = NULL;
	return (dst);
}

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
}
