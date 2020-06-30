/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:36:01 by rklein            #+#    #+#             */
/*   Updated: 2020/06/30 15:09:15 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_findpath(t_sh *sh)
{
	int		i;
	int		j;
	char	*cmd;
	char	**options;
	char	*path;

	cmd = ft_strjoin("/", sh->par[0]);
	i = -1;
	while (sh->env[++i])
	{
		if (!ft_strncmp(sh->env[i], "PATH=", 5))
		{
			options = ft_strsplit(&sh->env[i][5], 58);
			j = -1;
			while (options[++j])
			{
				path = ft_strjoin(options[j], cmd);
				if (access(path, F_OK) == 0)
				{
					free(cmd);
					ft_free_array(options);
					return (path);
				}
				free(path);
			}
		}
	}
	free(cmd);
	ft_free_array(options);
	return (sh->par[0]);
}

void		ft_execute(t_sh *sh)
{
	char	*cmd;

	if (fork() != 0)
		wait(NULL);
	else
	{
		cmd = !ft_findslash(sh->par[0]) ? ft_findpath(sh) :
			ft_strdup(sh->par[0]);
		if (execve(cmd, sh->par, sh->env) == -1)
		{
			ft_printf("minishell: command not found: %s\n", sh->par[0]);
			exit(1);
		}
		free(cmd);
	}
}
