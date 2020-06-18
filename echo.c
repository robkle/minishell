#include "minishell.h"

char	*ft_envcpy(char *dst, char *var, char **env)
{
	int	len;
	int	i;

	len = ft_strlen(var);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(var, env[i], len) == 0 && env[i][len] == '=')
			return (ft_strcpy(dst, &env[i][len + 1]));
	}
	dst[0] = '\0';
	return (dst);
}

static void	ft_write(t_sh *sh, int x)
{
	int	fd;
	int	i;
	char	env_var[PATH_MAX];
	_Bool	space;
	
	fd = open(sh->par[x + 1], O_CREAT | O_WRONLY | O_APPEND, 0644); //if fd == -1 etc.
	i = 0;
	space = 0;
	while (sh->par[++i])
	{
		if (i != x && i != x + 1)
		{
			if (space)
				write(fd, " ", 1);
			space = 1;
			if (sh->par[i][0] == '$')
			{
				ft_envcpy(env_var, &sh->par[i][1], sh->env);
				write(fd, env_var, ft_strlen(env_var));
			}
			else
				write(fd, sh->par[i], ft_strlen(sh->par[i]));
		}
	}
	write(fd, "\n", 1);
	close (fd);
}

static void	ft_trunc(t_sh *sh, int x)
{
	int	fd;

	fd = open(sh->par[x + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644); //if fd == -1 etc.
	write(fd, NULL, 0);
	close (fd);
	ft_write(sh, x);
} 

static void	ft_print_echo(t_sh *sh)
{
	int	i;
	char	env_var[PATH_MAX];
	_Bool	space;
	
	i = 0;
	space = 0;
	while (sh->par[++i])
	{
		if (space)
			write(1, " ", 1);
		space = 1;
		if (sh->par[i][0] == '$')
		{
			ft_envcpy(env_var, &sh->par[i][1], sh->env);
			ft_putstr(env_var);
		}
		else
			ft_putstr(sh->par[i]);
	}
	write(1, "\n", 1);
}

void	ft_echo(t_sh *sh)
{
	int	i;

	i = 0;
	while (sh->par[++i])
	{
		if (ft_strcmp(sh->par[i], ">") == 0)
		{
			ft_trunc(sh, i);
			return ;
		}
		if (ft_strcmp(sh->par[i], ">>") == 0)
		{
			ft_write(sh, i);
			return;
		}
	}
	ft_print_echo(sh);
}
