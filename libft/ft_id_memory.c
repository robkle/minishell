/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:15:35 by rklein            #+#    #+#             */
/*   Updated: 2020/02/04 15:12:18 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_var	*ft_idalloc(void)
{
	t_var	*id;

	if (!(id = malloc(sizeof(t_var))))
		return (NULL);
	id->count = 0;
	id->flags = ft_strnew(6);
	id->fld_min = ft_strnew(11);
	id->prec = ft_strnew(3);
	id->type_spec = ft_strnew(3);
	return (id);
}

void	ft_reset(t_var *id)
{
	id->sign = '+';
	ft_strclr(id->flags);
	ft_strclr(id->fld_min);
	id->dot = 0;
	ft_strclr(id->prec);
	id->prec[0] = '0';
	ft_strclr(id->type_spec);
	id->type = 0;
}

int		ft_free_id(t_var *id)
{
	int	count;

	count = id->count;
	free(id->flags);
	free(id->fld_min);
	free(id->prec);
	free(id->type_spec);
	free(id);
	return (count);
}
