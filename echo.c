#include "minishell.h"

static char	*ft_envcpy(char *dst, char *var, t_env *env)
{
	int	len;
	int	i;

	len = ft_strlen(var);
	while (env)
	{
		if (ft_strncmp(var, env->var, len) == 0 && env->var[len] == '=')
			return (ft_strcpy(dst, &env->var[len + 1]));
		env = env->next;
	}
	dst[1] = '\0';
	return (dst);
}

static void	ft_write(char **params, t_env *env, int x)
{
	int	fd;
	int	i;
	char	env_var[PATH_MAX];
	_Bool	space;
	
	fd = open(params[x + 1], O_CREAT | O_WRONLY | O_APPEND, 0644); //if fd == -1 etc.
	i = 0;
	space = 0;
	while (params[++i])
	{
		if (i != x && i != x + 1)
		{
			if (space)
				write(fd, " ", 1);
			space = 1;
			if (params[i][0] == '$')
			{
				ft_envcpy(env_var, &params[i][1], env);
				write(fd, env_var, ft_strlen(env_var));
			}
			else
				write(fd, params[i], ft_strlen(params[i]));
		}
	}
	write(fd, "\n", 1);
	close (fd);
}

static void	ft_trunc(char **params, t_env *env, int x)
{
	int	fd;

	fd = open(params[x + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644); //if fd == -1 etc.
	write(fd, NULL, 0);
	close (fd);
	ft_write(params, env, x);
} 

static void	ft_print_echo(char **params, t_env *env)
{
	int	i;
	char	env_var[PATH_MAX];
	_Bool	space;
	
	i = 0;
	space = 0;
	while (params[++i])
	{
		if (space)
			write(1, " ", 1);
		space = 1;
		if (params[i][0] == '$')
		{
			ft_envcpy(env_var, &params[i][1], env);
			ft_putstr(env_var);
		}
		else
			ft_putstr(params[i]);
	}
	write(1, "\n", 1);
}

void	ft_echo(char **params, t_env *env)
{
	int	i;

	i = 0;
	while (params[++i])
	{
		if (ft_strcmp(params[i], ">") == 0)
		{
			ft_trunc(params, env, i);
			return ;
		}
		if (ft_strcmp(params[i], ">>") == 0)
		{
			ft_write(params, env, i);
			return;
		}
	}
	ft_print_echo(params, env);
}
