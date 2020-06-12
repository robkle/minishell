/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_flags.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:16:05 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 11:28:27 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zeropad(t_var *id, int size)
{
	if (ft_strchr_int(id->flags, '0') && !ft_strchr_int(id->flags, '-')
			&& !id->dot)
		return (ft_strmake('0', ft_atoi(id->fld_min) - size));
	if (id->dot)
		return (ft_strmake('0', ft_atoi(id->prec) - size));
	return (ft_strnew(0));
}

char		*ft_addsign(t_var *id, char *str)
{
	char *sstr;

	if (id->sign == '-')
		sstr = ft_strjoin("-", str);
	else if (id->sign == '+' && (ft_strchr_int(id->flags, '+')))
		sstr = ft_strjoin("+", str);
	else if (id->sign == '+' && (ft_strchr_int(id->flags, ' ')))
		sstr = ft_strjoin(" ", str);
	else
		sstr = ft_strdup(str);
	free(str);
	return (sstr);
}

char		*ft_spacepad(t_var *id, char *str)
{
	char	*s_pad;
	char	*tmp;

	s_pad = ft_strmake(' ', (ft_atoi(id->fld_min) - (ft_strlen(str))));
	if (ft_strchr_int(id->flags, '-'))
		tmp = ft_strjoin(str, s_pad);
	else
		tmp = ft_strjoin(s_pad, str);
	free(s_pad);
	return (tmp);
}

static char	*ft_int_spad(t_var *id, char *str)
{
	char	*spad;

	if ((ft_strchr_int(id->flags, '-') || id->dot) &&
			(size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		spad = ft_spacepad(id, str);
	else if (ft_strchr_int(id->flags, '0') == 0 &&
			(size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		spad = ft_spacepad(id, str);
	else
		spad = ft_strdup(str);
	free(str);
	return (spad);
}

char		*ft_int_flags(t_var *id, char *str)
{
	char	*tmp[4];
	int		size;
	int		sn;

	if (ft_atoi(str) == 0 && id->dot && ft_strchr_int(id->prec, '0'))
	{
		tmp[1] = ft_strnew(0);
		free(str);
	}
	else
	{
		size = ft_strlen(str);
		sn = id->sign == '-' || ft_strchr_int(id->flags, '+') ||
			ft_strchr_int(id->flags, ' ') ? 1 : 0;
		if (id->type != 'u' && !id->dot && sn && ft_strchr_int(id->flags, '0'))
			size++;
		tmp[0] = ft_zeropad(id, size);
		tmp[1] = ft_strjoin(tmp[0], str);
		free(tmp[0]);
		free(str);
	}
	tmp[2] = ft_addsign(id, tmp[1]);
	tmp[3] = ft_int_spad(id, tmp[2]);
	return (tmp[3]);
}
