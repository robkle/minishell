/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:04:08 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 12:16:44 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_valid_type(t_var *id, const char *str, int i)
{
	id->type = str[i++];
	if (id->type >= 'b' && id->type <= 'g')
		return (i);
	if (ft_toupper(id->type) == 'E' || ft_toupper(id->type) == 'G' ||
			ft_toupper(id->type) == 'X')
		return (i);
	if (id->type == 'i' || id->type == 'o' || id->type == 'p' ||
			id->type == 's' || id->type == 'u' || id->type == '%')
		return (i);
	return (0);
}

static int		ft_read_id(t_var *id, const char *str)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] && ft_is_flag(str[i[0]]) == 1)
		id->flags[i[1]++] = str[i[0]++];
	i[1] = 0;
	while (str[i[0]] && ft_isdigit(str[i[0]]))
		id->fld_min[i[1]++] = str[i[0]++];
	if (str[i[0]] == '.')
	{
		id->dot = 1;
		i[0]++;
	}
	i[1] = 0;
	while (str[i[0]] && ft_isdigit(str[i[0]]))
		id->prec[i[1]++] = str[i[0]++];
	i[1] = 0;
	if (str[i[0]] && (str[i[0]] == 'l' || str[i[0]] == 'h' || str[i[0]] == 'L'))
	{
		id->type_spec[i[1]++] = str[i[0]++];
		if (str[i[0]] && str[i[0]] == str[i[0] - 1] && str[i[0]] != 'L')
			id->type_spec[i[1]++] = str[i[0]++];
	}
	return (ft_valid_type(id, str, i[0]));
}

static void		ft_direct(t_var *id, va_list args)
{
	if (id->type == 'f')
		ft_double_print(id, args);
	else if (id->type == 'p')
		ft_addr_print(id, args);
	else if (id->type == 'd' || id->type == 'i')
		ft_int_print(id, args);
	else if (id->type == 'o' || id->type == 'u' || id->type == 'x' ||
			id->type == 'X' || id->type == 'b')
		ft_uint_print(id, args);
	else if (id->type == 's' || id->type == 'c' || id->type == '%')
		ft_char_print(id, args);
	else if (ft_toupper(id->type) == 'E')
		ft_e_print(id, args);
	else if (ft_toupper(id->type) == 'G')
		ft_g_print(id, args);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	t_var	*id;
	int		i;

	va_start(args, format);
	id = ft_idalloc();
	i = 0;
	while (format[i] != '\0')
	{
		ft_reset(id);
		if (format[i] == '%')
		{
			i = i + ft_read_id(id, &format[i + 1]);
			ft_direct(id, args);
		}
		else
		{
			write(1, &format[i], 1);
			id->count++;
		}
		i++;
	}
	va_end(args);
	return (ft_free_id(id));
}
