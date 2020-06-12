/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:17:22 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 12:35:24 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_u_numlen(uintmax_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_u_itoa(uintmax_t n)
{
	int		i;
	char	*str;

	i = ft_u_numlen(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

void		ft_uint_print(t_var *id, va_list args)
{
	uintmax_t	value;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "l") == 0)
		value = (unsigned long int)va_arg(args, uintmax_t);
	else if (ft_strcmp(id->type_spec, "ll") == 0)
		value = (unsigned long long)va_arg(args, uintmax_t);
	else if (ft_strcmp(id->type_spec, "h") == 0)
		value = (unsigned short int)va_arg(args, uintmax_t);
	else if (ft_strcmp(id->type_spec, "hh") == 0)
		value = (unsigned char)va_arg(args, uintmax_t);
	else
		value = (unsigned int)va_arg(args, uintmax_t);
	str[0] = (id->type == 'u') ? ft_u_itoa(value) : ft_base(value, id);
	if (id->type == 'u' && value == 0 && id->dot &&
			ft_strchr_int(id->prec, '0'))
	{
		str[1] = ft_spad_uint(id, ft_strnew(0));
		free(str[0]);
	}
	else
		str[1] = ft_uint_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
