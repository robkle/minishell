/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:40:29 by rklein            #+#    #+#             */
/*   Updated: 2020/07/13 10:56:40 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**commands seperated by semicolon, unless inside quotation marks
*/

static int	ft_cmd_count(char const *s)
{
	int		i;
	int		count;
	char	qt;

	i = 0;
	while (s[i] && s[i] == 59)
		i++;
	if (s[i] == '\0')
		return (0);
	qt = 0;
	count = 1;
	while (s[i])
	{
		qt = ft_qt_track(s[i], qt);
		if (qt == 0 && (s[i] == 59 && s[i + 1] != 59) && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

/*
**counts characters except outer quotation marks
*/

static int	ft_cmd_len(char const *s)
{
	int	i;
	int	qt;

	qt = 0;
	i = 0;
	while (s[i])
	{
		qt = ft_qt_track(s[i], qt);
		if (s[i] == 59 && qt == 0)
			break ;
		i++;
	}
	return (i);
}

char		**ft_semicolon_split(char const *s)
{
	char	**pr;
	int		i[2];
	int		qt;

	if (!s || !(pr = (char **)malloc(sizeof(char *) * (ft_cmd_count(s) + 1))))
		return (NULL);
	i[0] = -1;
	while (*s)
	{
		while (*s && *s == 59)
			s++;
		if (!*s)
			break ;
		pr[++i[0]] = (char *)malloc(sizeof(char) * (ft_cmd_len(s) + 1));
		qt = 0;
		i[1] = 0;
		while (*s && !(*s == 59 && qt == 0))
		{
			qt = ft_qt_track(*s, qt);
			pr[i[0]][i[1]++] = *s++;
		}
		pr[i[0]][i[1]] = '\0';
	}
	pr[++i[0]] = NULL;
	return (pr);
}
