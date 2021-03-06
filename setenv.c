/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:30:42 by rklein            #+#    #+#             */
/*   Updated: 2020/07/13 10:57:07 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_setenv_new(t_sh *sh)
{
	char	**tmp;
	int		i;

	i = 0;
	while (sh->env[i])
		i++;
	tmp = (char**)malloc(sizeof(char*) * (i + 2));
	i = -1;
	while (sh->env[++i])
		tmp[i] = ft_strdup(sh->env[i]);
	tmp[i] = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	ft_strcpy(tmp[i], sh->par[1]);
	ft_strcat(tmp[i], "=");
	if (sh->par[2])
		ft_strcat(tmp[i], sh->par[2]);
	tmp[++i] = NULL;
	ft_free_array(sh->env);
	sh->env = tmp;
}

void		ft_setenv(t_sh *sh)
{
	int		i;
	char	*tmp;

	if (!sh->par[1])
	{
		ft_env(sh->env);
		return ;
	}
	i = -1;
	while (sh->env[++i])
	{
		if (strncmp(sh->env[i], sh->par[1], ft_strlen(sh->par[1])) == 0)
		{
			free(sh->env[i]);
			tmp = ft_strjoin(sh->par[1], "=");
			if (sh->par[2])
				sh->env[i] = ft_strjoin(tmp, sh->par[2]);
			free(tmp);
			break ;
		}
	}
	if (sh->env[i] == NULL)
		ft_setenv_new(sh);
}
