/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:22:04 by rklein            #+#    #+#             */
/*   Updated: 2020/06/12 13:29:00 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_change_dir(char *path, t_env *env)
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

static char	*ft_check_space(char **params)
{
	char	path[PATH_MAX];
	int		i;

	ft_strcpy(path, params[1]);
	i = 2;
	while (params[i] && (params[i - 1][ft_strlen(params[i - 1]) - 1] == '\\'))
	{
		ft_strcat(path, params[i]);
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

static char	*ft_oldpwd(t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->var, "OLDPWD", 6) == 0)
			return (ft_strdup(&env->var[7]));
		env = env->next;
	}
	return (NULL);
}

static char	*ft_home_path(t_env *env)
{
	while (env)
	{
		if (ft_strncmp(env->var, "HOME", 4) == 0)
			return (ft_strdup(&env->var[5]));
		env = env->next;
	}
	return (NULL);
}

void	ft_cd(char **params, t_env *env)
{
	char	*home;
	char	*path;
	char	env_var[PATH_MAX];

	if (!params[1])
		path = ft_home_path(env);
	else if (params[1][0] == '~')
	{
		home = ft_home_path(env);
		path = ft_strjoin(home, &params[1][1]);
		free(home);
	}
	else if (params[1][0] == '$')
	{
		ft_envcpy(env_var, &params[1][1], env);
		path = ft_strdup(env_var);
	}
	else if (ft_strcmp(params[1], "-") == 0)
		path = ft_oldpwd(env);
	else if (params[2])
		path = ft_check_space(params);
	else
		path = ft_strdup(params[1]);
	ft_change_dir(path, env);
	free(path);
}
