/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:03:25 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 12:35:19 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_prep(t_var *id, long double fl, int pr)
{
	long double	dec;
	int			i;

	if (fl < 0)
	{
		fl = fl * -1.0;
		id->sign = '-';
	}
	dec = 0.5;
	i = pr;
	while (i-- > 0)
		dec /= 10;
	fl = fl + dec;
	return (fl);
}

char		*ft_ftoa(t_var *id, long double fl, int pr)
{
	char		*str[2];
	char		buffer[1024];
	intmax_t	num;
	int			i;

	num = fl;
	str[0] = ft_s_itoa(id, num);
	if (pr == 0 && ft_strchr_int(id->flags, '#') == 0)
		str[1] = ft_strdup(str[0]);
	else
	{
		buffer[0] = '.';
		i = -1;
		while (++i < pr)
		{
			fl = fl * 10;
			num = fl;
			fl = fl - num;
			buffer[i + 1] = (num % 10) + '0';
		}
		buffer[i + 1] = '\0';
		str[1] = ft_strjoin(str[0], buffer);
	}
	free(str[0]);
	return (str[1]);
}

void		ft_double_print(t_var *id, va_list args)
{
	long double	ld;
	int			pr;
	char		*str[2];

	pr = 6;
	if (id->dot)
		pr = ft_atoi(id->prec);
	if (ft_strcmp(id->type_spec, "L") == 0)
		ld = (long double)va_arg(args, long double);
	else
		ld = (long double)va_arg(args, double);
	ld = ft_prep(id, ld, pr);
	str[0] = ft_ftoa(id, ld, pr);
	str[1] = ft_double_flags(id, str[0]);
	free(str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
