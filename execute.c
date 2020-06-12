/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:36:01 by rklein            #+#    #+#             */
/*   Updated: 2020/06/12 11:57:57 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(char **params, char **envp)
{
	char	*cmd;

	if (fork() != 0)
		wait(NULL);
	else
	{ 
		cmd = ft_strjoin("/bin/", params[0]);
		if (execve(cmd, params, envp) == -1)
		{
			ft_printf("minishell: command not found: %s\n", params[0]);
			exit(1);
		}
	}
}
