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

void	ft_cd_env(char *path, char **env)//REWRITE COMPLETELY. "MANUALLY" UPDATE ENV NOT VIA SETENV!! 
{
	char	*oldpwd[3];
	char	*pwd[3];
	
	oldpwd[1] = ft_strdup("OLDPWD");
	oldpwd[2] = ft_strnew(PATH_MAX);
	getcwd(oldpwd[2], PATH_MAX);
	ft_setenv(oldpwd, env);
	chdir(path);
	pwd[1] = ft_strdup("PWD");
	pwd[2] = ft_strnew(PATH_MAX);
	getcwd(pwd[2] , PATH_MAX);
	if (ft_strcmp(path, ".") != 0)
		ft_setenv(pwd, env);
	free(oldpwd[1]);
	free(oldpwd[2]);
	free(pwd[1]);
	free(pwd[2]);
}
