/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:16:47 by rklein            #+#    #+#             */
/*   Updated: 2020/02/03 16:27:39 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(intmax_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_s_itoa(t_var *id, intmax_t n)
{
	int		i;
	char	*str;

	if (n == -9223372036854775807 - 1)
	{
		id->sign = '-';
		return (ft_strdup("9223372036854775808"));
	}
	i = ft_numlen(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		id->sign = '-';
		n = n * -1;
	}
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void		ft_int_print(t_var *id, va_list args)
{
	intmax_t	value;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "l") == 0)
		value = (long int)va_arg(args, intmax_t);
	else if (ft_strcmp(id->type_spec, "ll") == 0)
		value = (long long int)va_arg(args, intmax_t);
	else if (ft_strcmp(id->type_spec, "h") == 0)
		value = (short int)va_arg(args, intmax_t);
	else if (ft_strcmp(id->type_spec, "hh") == 0)
		value = (char)va_arg(args, intmax_t);
	else
		value = (int)va_arg(args, intmax_t);
	str[0] = ft_s_itoa(id, value);
	str[1] = ft_int_flags(id, str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
