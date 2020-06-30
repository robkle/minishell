/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:21:04 by rklein            #+#    #+#             */
/*   Updated: 2020/06/29 14:58:36 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_letc(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fr;
	int		x;
	int		y;

	if (!s)
		return (0);
	if (!(fr = (char **)malloc(sizeof(char *) * (ft_strcount(s, c) + 1))))
		return (NULL);
	x = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!(fr[++x] = (char *)malloc(sizeof(char) * (ft_letc(s, c) + 1))))
				return (NULL);
			y = 0;
			while (*s && *s != c)
				fr[x][y++] = *s++;
			fr[x][y] = '\0';
		}
	}
	fr[++x] = NULL;
	return (fr);
}
