/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:15:31 by rklein            #+#    #+#             */
/*   Updated: 2020/07/07 13:53:52 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_unsetenv_update(t_sh *sh, int size)
{
	char	**tmp;
	int		len;
	int		i;
	int		j;

	tmp = (char**)malloc(sizeof(char*) * size);
	len = ft_strlen(sh->par[1]);
	i = 0;
	j = 0;
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], sh->par[1], len) == 0 &&
				sh->env[i][len] == '=')
			i++;
		if (sh->env[i])
			tmp[j++] = ft_strdup(sh->env[i++]);
	}
	tmp[j] = NULL;
	ft_free_array(sh->env);
	sh->env = tmp;
}

void		ft_unsetenv(t_sh *sh)
{
	int		i;
	int		len;
	_Bool	listed;

	i = -1;
	listed = 0;
	len = ft_strlen(sh->par[1]);
	while (sh->env[++i])
	{
		if (ft_strncmp(sh->env[i], sh->par[1], len) == 0 &&
				sh->env[i][len] == '=')
			listed = 1;
	}
	if (listed)
		ft_unsetenv_update(sh, i);
}
