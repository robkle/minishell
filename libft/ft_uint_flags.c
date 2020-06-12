/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:38:21 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 12:35:26 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_b_prefix(t_var *id, char *str)
{
	char *s;

	if (ft_strcmp(id->type_spec, "hh") == 0)
		s = ft_strmake('0', 8 - ft_strlen(str));
	else if (ft_strcmp(id->type_spec, "h") == 0)
		s = ft_strmake('0', 16 - ft_strlen(str));
	else if (ft_strcmp(id->type_spec, "l") == 0 ||
			ft_strcmp(id->type_spec, "ll") == 0)
		s = ft_strmake('0', 64 - ft_strlen(str));
	else
		s = ft_strmake('0', 32 - ft_strlen(str));
	return (s);
}

static char	*ft_prefix(t_var *id, char *str)
{
	if (ft_strlen(str) != 0 && !(ft_strlen(str) == 1 && str[0] == '0'))
	{
		if (id->type == 'b')
			return (ft_b_prefix(id, str));
		if (id->type == 'x')
			return (ft_strdup("0x"));
		if (id->type == 'X')
			return (ft_strdup("0X"));
	}
	if (id->type == 'o' && !(ft_strlen(str) == 1 && str[0] == '0'))
		return (ft_strdup("0"));
	return (ft_strnew(0));
}

char		*ft_spad_uint(t_var *id, char *str)
{
	char	*tmp;

	if ((ft_strchr_int(id->flags, '-') || id->dot)
			&& (size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		tmp = ft_spacepad(id, str);
	else if (ft_strchr_int(id->flags, '0') == 0
			&& (size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		tmp = ft_spacepad(id, str);
	else
		tmp = ft_strdup(str);
	free(str);
	return (tmp);
}

char		*ft_zpad_uint(t_var *id, int size)
{
	if (ft_strchr_int(id->flags, '0') && !ft_strchr_int(id->flags, '-')
			&& !id->dot)
		return (ft_strmake('0', ft_atoi(id->fld_min) - size));
	if (id->dot)
	{
		if (ft_toupper(id->type) == 'X' && ft_strchr_int(id->flags, '#'))
			size = size - 2;
		return (ft_strmake('0', ft_atoi(id->prec) - size));
	}
	return (ft_strnew(0));
}

char		*ft_uint_flags(t_var *id, char *str)
{
	char	*tmp[3];
	int		size;

	size = ft_strlen(str);
	if (ft_strchr_int(id->flags, '#') && id->type != 'u')
	{
		tmp[0] = ft_prefix(id, str);
		size += ft_strlen(tmp[0]);
	}
	if (ft_strlen(str) != 0)
	{
		tmp[1] = ft_zpad_uint(id, size);
		tmp[2] = ft_strjoin(tmp[1], str);
		free(tmp[1]);
		free(str);
		str = tmp[2];
	}
	if (ft_strchr_int(id->flags, '#') && id->type != 'u')
	{
		tmp[1] = ft_strjoin(tmp[0], str);
		free(tmp[0]);
		free(str);
		str = tmp[1];
	}
	return (ft_spad_uint(id, str));
}
