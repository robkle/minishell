/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:36:01 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 16:36:19 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_sh *sh)
{
	char	*cmd;

	if (fork() != 0)
		wait(NULL);
	else
	{ 
		cmd = !ft_findslash(sh->par[0]) ? ft_strjoin("/bin/", sh->par[0])
			: ft_strdup(sh->par[0]);
		if (execve(cmd, sh->par, sh->env) == -1)
		{
			ft_printf("minishell: command not found: %s\n", sh->par[0]);
			exit(1);
		}
		free(cmd);
	}
}
