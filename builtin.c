/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:19:29 by rklein            #+#    #+#             */
/*   Updated: 2020/06/30 15:03:55 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtin(t_sh *sh)
{
	if (ft_strcmp(sh->par[0], "cd") == 0)
		ft_cd(sh);
	else if (ft_strcmp(sh->par[0], "env") == 0)
		ft_env(sh->env);
	else if (ft_strcmp(sh->par[0], "setenv") == 0)
		ft_setenv(sh);
	else if (ft_strcmp(sh->par[0], "unsetenv") == 0)
		ft_unsetenv(sh);
	else if (ft_strcmp(sh->par[0], "echo") == 0)
		ft_echo(sh);
	else if (strcmp(sh->par[0], "exit") == 0)
		exit(1);
	else
		return (1);
	return (0);
}
