/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:22:04 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 16:32:31 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_change_dir(char *path, char **env)
{
	struct stat	buf;
	char		*errmsg;

	if (path && *path)
	{
		errmsg = "-minishell: cd:";
		if (access(path, F_OK) == -1)
			ft_printf("%s %s: No such file or directory\n", errmsg, path);
		else
		{
			lstat(path, &buf);
			if ((buf.st_mode & S_IFMT) != S_IFDIR) 
				printf("%s %s: Not a directory\n", errmsg, path);
			else if (access(path, R_OK) == -1)
				printf("%s %s: Permission denied\n", errmsg, path);
		}
		ft_cd_env(path, env);
	}
}

static char	*ft_check_space(char **par)
{
	char	path[PATH_MAX];
	int		i;

	ft_strcpy(path, par[1]);
	i = 2;
	while (par[i] && (par[i - 1][ft_strlen(par[i - 1]) - 1] == '\\'))
	{
		ft_strcat(path, par[i]);
		i++;
	}
	i = -1;
	while (path[++i])
	{
		if (path[i] == '\\')
			path[i] = ' ';
	}
	return (ft_strdup(path));
}

static char	*ft_oldpwd(char **env)
{
	int i;

	i= -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD", 6) == 0)
			return (ft_strdup(&env[i][7]));
	}
	return (NULL);
}

static char	*ft_home_path(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "HOME", 4) == 0)
			return (ft_strdup(&env[i][5]));
	}
	return (NULL);
}

void	ft_cd(t_sh *sh)
{
	char	*home;
	char	*path;
	char	env_var[PATH_MAX];

	if (!sh->par[1])
		path = ft_home_path(sh->env);
	else if (sh->par[1][0] == '~')
	{
		home = ft_home_path(sh->env);
		path = ft_strjoin(home, &sh->par[1][1]);
		free(home);
	}
	else if (sh->par[1][0] == '$')
	{
		ft_envcpy(env_var, &sh->par[1][1], sh->env);
		path = ft_strdup(env_var);
	}
	else if (ft_strcmp(sh->par[1], "-") == 0)
		path = ft_oldpwd(sh->env);
	else if (sh->par[2])
		path = ft_check_space(sh->par);
	else
		path = ft_strdup(sh->par[1]);
	ft_change_dir(path, sh->env);
	free(path);
}
