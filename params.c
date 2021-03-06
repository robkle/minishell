/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:43:55 by rklein            #+#    #+#             */
/*   Updated: 2020/07/13 10:56:24 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		ft_qt_track(char s, char q)
{
	if (s == 34 || s == 39)
	{
		if (q == 0)
			q = s;
		else if (q == s)
			q = 0;
	}
	return (q);
}

/*
**params seperated by spaces, unless inside quotation marks
*/

static int	ft_param_count(char const *s)
{
	int		i;
	int		count;
	char	qt;

	i = 0;
	while (s[i] && ft_spacetab(s[i]))
		i++;
	if (s[i] == '\0')
		return (0);
	qt = 0;
	count = 1;
	while (s[i])
	{
		qt = ft_qt_track(s[i], qt);
		if (qt == 0 && (ft_spacetab(s[i]) && !ft_spacetab(s[i + 1]) &&
					s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

/*
**counts characters except outer quotation marks
*/

static int	ft_char_count(char const *s)
{
	int	i;
	int	qt;

	qt = 0;
	i = 0;
	while (s[i])
	{
		qt = ft_qt_track(s[i], qt);
		if (ft_spacetab(s[i]) && qt == 0)
			break ;
		i++;
	}
	return (i + 1);
}

static char	**ft_qt_trim(char **pr)
{
	char	*tmp;
	int		len;
	int		i;

	i = -1;
	while (pr[++i])
	{
		if (pr[i][0] == 34 || pr[i][0] == 39)
		{
			len = ft_strlen(pr[i]) - 2;
			tmp = ft_strnew(len);
			ft_strncpy(tmp, &pr[i][1], len);
			free(pr[i]);
			pr[i] = tmp;
		}
	}
	return (pr);
}

char		**ft_param_prep(char const *s)
{
	char	**pr;
	int		i[2];
	int		qt;

	if (!s || !(pr = (char **)malloc(sizeof(char *) * (ft_param_count(s) + 1))))
		return (NULL);
	i[0] = -1;
	while (*s)
	{
		while (*s && ft_spacetab(*s))
			s++;
		if (!*s)
			break ;
		pr[++i[0]] = (char *)malloc(sizeof(char) * (ft_char_count(s) + 1));
		qt = 0;
		i[1] = 0;
		while (*s && !(ft_spacetab(*s) && qt == 0))
		{
			qt = ft_qt_track(*s, qt);
			pr[i[0]][i[1]++] = *s++;
		}
		pr[i[0]][i[1]] = '\0';
	}
	pr[++i[0]] = NULL;
	return (ft_qt_trim(pr));
}
