/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:41:21 by rklein            #+#    #+#             */
/*   Updated: 2019/10/30 15:40:57 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	d = (char*)malloc(sizeof(*d) * (ft_strlen((char*)s1)
				+ ft_strlen((char*)s2) + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (*s1)
	{
		d[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		d[i] = *s2;
		i++;
		s2++;
	}
	d[i] = '\0';
	return (d);
}
