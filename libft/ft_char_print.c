/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 12:34:56 by rklein            #+#    #+#             */
/*   Updated: 2020/02/04 16:19:22 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_char(t_var *id, char c)
{
	char	*spad;

	spad = ft_strmake(' ', ft_atoi(id->fld_min) - 1);
	if (ft_strchr_int(id->flags, '-'))
	{
		write(1, &c, 1);
		ft_putstr(spad);
	}
	else
	{
		ft_putstr(spad);
		write(1, &c, 1);
	}
	id->count += ft_strlen(spad) + 1;
	free(spad);
}

static char	*ft_str_flags(t_var *id, char *str)
{
	char	*tmp;

	if (id->type == 's')
	{
		if (id->dot)
		{
			tmp = ft_strsub(str, 0, ft_atoi(id->prec));
			free(str);
			str = tmp;
		}
	}
	if ((size_t)ft_atoi(id->fld_min) > ft_strlen(str))
		tmp = ft_spacepad(id, str);
	else
		tmp = ft_strdup(str);
	free(str);
	return (tmp);
}

void		ft_char_print(t_var *id, va_list args)
{
	char	c;
	char	*tmp;
	char	*str[2];

	if (id->type == '%')
		ft_char(id, '%');
	else if (id->type == 'c')
	{
		c = va_arg(args, int);
		ft_char(id, c);
	}
	else if (id->type == 's')
	{
		tmp = va_arg(args, char*);
		if (!tmp)
			str[0] = ft_strdup("(null)");
		else
			str[0] = ft_strdup(tmp);
		str[1] = ft_str_flags(id, str[0]);
		ft_putstr(str[1]);
		id->count += ft_strlen(str[1]);
		free(str[1]);
	}
}
