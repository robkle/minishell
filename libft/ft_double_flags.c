/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:16:05 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 11:28:31 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_double_flags(t_var *id, char *str)
{
	char	*tmp[4];
	int		size;

	size = ft_strlen(str);
	if ((id->sign == '-' || ft_strchr_int(id->flags, '+') ||
				ft_strchr_int(id->flags, ' ')) && ft_strchr_int(id->flags, '0'))
		size++;
	tmp[0] = (ft_strchr_int(id->flags, '0') && !ft_strchr_int(id->flags, '-')) ?
		ft_strmake('0', ft_atoi(id->fld_min) - size) : ft_strnew(0);
	tmp[1] = ft_strjoin(tmp[0], str);
	free(tmp[0]);
	free(str);
	tmp[2] = ft_addsign(id, tmp[1]);
	tmp[3] = !ft_strchr_int(id->flags, '0') ? ft_spacepad(id, tmp[2]) : tmp[2];
	return (tmp[3]);
}
