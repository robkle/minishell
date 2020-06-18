/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:38:41 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 16:29:34 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cd_path(t_sh *sh, char *str)
{
	int	i;
	char	pwd[PATH_MAX];
	
	i = -1;
	while (sh->env[++i])
	{
		if (strncmp(sh->env[i], str, ft_strlen(str)) == 0)
		{
			free(sh->env[i]);
			getcwd(pwd, PATH_MAX);
			sh->env[i] = ft_strjoin(str, pwd);
			break;
		}
	}
}

void	ft_cd_env(char *path, t_sh *sh)
{
	ft_cd_path(sh, "OLDPWD=");
	chdir(path);
	ft_cd_path(sh, "PWD=");
}
