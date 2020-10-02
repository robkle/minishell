/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 10:02:01 by rklein            #+#    #+#             */
/*   Updated: 2020/07/13 10:58:20 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_shellenv(t_sh *sh, char *av)
{
	char	cwd[PATH_MAX];
	char	*tmp[2];
	int		i;

	getcwd(cwd, sizeof(cwd));
	tmp[0] = ft_strcmp(cwd, "/") ? ft_strjoin(cwd, "/") : ft_strdup("/");
	i = -1;
	while (sh->env[++i])
	{
		if (!ft_strncmp(sh->env[i], "SHELL=", 6))
		{
			free(sh->env[i]);
			tmp[1] = ft_strjoin("SHELL=", tmp[0]);
			sh->env[i] = ft_strjoin(tmp[1], av);
			free(tmp[1]);
			break ;
		}
	}
	free(tmp[0]);
}
