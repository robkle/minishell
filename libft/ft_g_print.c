/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:40:29 by rklein            #+#    #+#             */
/*   Updated: 2020/02/06 12:35:20 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_snum(long double d, int pr)
{
	intmax_t	n;
	int			i;

	n = d;
	i = 0;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		i++;
	}
	return (pr - i);
}

static int	ft_sdigits(long double d, int pr)
{
	int			i;
	intmax_t	n;
	long double	tmp;

	n = d;
	if (n == 0)
	{
		tmp = d;
		i = pr;
		while (i-- > 0)
			tmp = tmp * 10;
		i = 0;
		n = tmp;
		if (n == 0)
		{
			while (n == 0)
			{
				tmp = tmp * 10;
				n = tmp;
				i++;
			}
		}
		return (pr + i);
	}
	return (ft_snum(d, pr));
}

char		*ft_cut_zero(char *str)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	i = ft_strlen(tmp) - 1;
	while (tmp[i] == '0' && i > 0)
		tmp[i--] = '\0';
	if (tmp[i] == '.' && i > 0)
		tmp[i] = '\0';
	return (tmp);
}

static char	*ft_g_direct(t_var *id, long double fl)
{
	int		pr;
	char	*str[3];

	str[0] = ft_enum(id, fl);
	pr = id->dot ? ft_atoi(id->prec) : 6;
	pr = ft_sdigits(fl, pr);
	fl = ft_prep(id, fl, pr);
	if (pr >= 0)
	{
		str[1] = ft_ftoa(id, fl, pr);
		if (pr == 0 && ft_strchr_int(id->flags, '#'))
			str[2] = ft_strjoin(str[1], ".");
		else
			str[2] = ft_cut_zero(str[1]);
		free(str[1]);
		str[1] = ft_strlen(str[0]) < ft_strlen(str[2]) ? ft_strdup(str[0])
			: ft_strdup(str[2]);
		free(str[2]);
	}
	else
		str[1] = ft_strdup(str[0]);
	free(str[0]);
	return (str[1]);
}

void		ft_g_print(t_var *id, va_list args)
{
	long double	ld;
	char		*str[2];

	if (ft_strcmp(id->type_spec, "L") == 0)
		ld = (long double)va_arg(args, long double);
	else
		ld = (long double)va_arg(args, double);
	str[0] = ft_g_direct(id, ld);
	str[1] = ft_double_flags(id, str[0]);
	free(str[0]);
	ft_putstr(str[1]);
	id->count += ft_strlen(str[1]);
	free(str[1]);
}
