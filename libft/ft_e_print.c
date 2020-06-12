/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:28:41 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 12:35:17 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_suffix(char type, char sign, int e)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = ft_toupper(type) == 'E' ? type : type - 2;
	str[1] = sign;
	str[3] = e % 10 + '0';
	e /= 10;
	str[2] = e % 10 + '0';
	return (str);
}

static long double	ft_epower(long double f, int *e)
{
	int	i;

	while ((f > 0 && !(f < 10.0 && f >= 1.0)) ||
			(f < 0 && !(f > -10.0 && f <= -1.0)))
	{
		if ((f < 1.0 && f > 0.0) || (f > -1.0 && f < 0.0))
			f = f * 10;
		if (f >= 10.0 || f <= -10.0)
			f = f / 10;
		*e = *e + 1;
	}
	i = f > 0 ? f + 0.5 : f - 0.5;
	if (i >= 10 || i <= -10)
	{
		f = f / 10;
		*e = *e - 1;
		if (*e == 0)
		{
			f = f * 10;
			*e = *e + 1;
		}
	}
	return (f);
}

char				*ft_enum(t_var *id, long double f)
{
	int		e;
	int		pr;
	char	sign;
	char	*str[4];

	pr = id->dot == 1 ? ft_atoi(id->prec) : 6;
	pr = ft_toupper(id->type) == 'G' && pr > 0 ? pr - 1 : pr;
	sign = ((f < 1.0 && f > 0.0) || (f > -1.0 && f < 0.0)) ? '-' : '+';
	e = 0;
	f = ft_epower(f, &e);
	f = ft_prep(id, f, pr);
	str[0] = ft_ftoa(id, f, pr);
	if (pr == 0 && ft_strchr_int(id->flags, '#'))
		str[1] = ft_strjoin(str[0], ".");
	else
		str[1] = ft_toupper(id->type) == 'G' ? ft_cut_zero(str[0]) :
			ft_strdup(str[0]);
	free(str[0]);
	str[2] = ft_suffix(id->type, sign, e);
	str[3] = ft_strjoin(str[1], str[2]);
	free(str[1]);
	free(str[2]);
	return (str[3]);
}

void				ft_e_print(t_var *id, va_list args)
{
	long double	ld;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "L") == 0)
		ld = (long double)va_arg(args, long double);
	else
		ld = (long double)va_arg(args, double);
	str[0] = ft_enum(id, ld);
	str[1] = ft_double_flags(id, str[0]);
	free(str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
