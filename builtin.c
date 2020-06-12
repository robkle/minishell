/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:19:29 by rklein            #+#    #+#             */
/*   Updated: 2020/06/12 14:32:05 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_builtin(char **params, t_env **env)
{
	if (ft_strcmp(params[0], "cd") == 0)
		ft_cd(params, *env);
	else if (ft_strcmp(params[0], "env") == 0)
		ft_env(*env);
	else if (ft_strcmp(params[0], "setenv") == 0)
		ft_setenv(params, *env);
	else if (ft_strcmp(params[0], "unsetenv") == 0)
		ft_unsetenv(params, env);
	else if (ft_strcmp(params[0], "echo") == 0)
		ft_echo(params, *env);
	else if (strcmp(params[0], "exit") == 0)
		exit(1);
	else
		return (1);
	return (0);
}
