/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:15:31 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 16:36:12 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(t_sh *sh)
{
	char	**tmp;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (sh->env[i])
		i++;
	tmp = (char**)malloc(sizeof(char*) * i);
	len = ft_strlen(sh->par[1]);
	i = 0;
	j = 0;
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], sh->par[1], len) == 0 && sh->env[i][len] == '=')
			i++;
		if (sh->env[i])
			tmp[j++] = ft_strdup(sh->env[i++]);
	}
	tmp[j] = NULL;
	ft_free_array(sh->env);
	sh->env = tmp;
}
