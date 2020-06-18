/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:40:48 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 10:09:11 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	type_prompt(int prompt)
{
	const char *CLEAR_SCREEN_ANSI;
	char		cwd[PATH_MAX];

	if (prompt == 0)
	{
		CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";//interprets as commmand not character code
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	}
	if (prompt == -1)
		write(1, "> ", 2);
	else
	{
		getcwd(cwd, sizeof(cwd));
		write(1, "minishell: ", 11);
		ft_putstr(cwd);
		write(1, ">> ", 3);
	}
}

static char	**read_command(void)
{
	char	line[1024];
	int	count;
	char	buf;
	char	qt;

	count = 0;
	qt = 0;
	read(0, &buf, 1);
	while (1)
	{
		qt = ft_qt_track(buf, qt);
		if (buf == '\n' && qt == 0)
			break;
		else if (buf == '\n' && qt != 0)
			type_prompt(-1);
		line[count++] = buf;
		read(0, &buf, 1);
	}
	if (count == 0)
		return (NULL);
	line[count] = '\0';
	return (ft_param_prep(line));
}

static	t_env	*ft_create_env(char **envp)
{
	t_env	*env;
	t_env	*begin;
	int	i;

	i = -1;
	env = malloc(sizeof(t_env));
	env->var = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	ft_strcpy(env->var, envp[++i]);
	begin = env;
	while (envp[++i])
	{
		env->next = malloc(sizeof(t_env));
		env = env->next;
		env->var = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
		ft_strcpy(env->var, envp[i]);
	}
	env->next = NULL;
	return (begin);
}

static void	ft_free_params(char **params)
{
	int	i;

	i = -1;
	if (params)
	{
		while (params[++i])
			free(params[i]);
		free(params);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**params;
	t_env	*env;
	int	bltin;
	int	prompt;
	
	if (argc && argv[0])
	{
		env = ft_create_env(envp);
		prompt = 0;
		while (1)
		{
			type_prompt(prompt++);
			params = read_command();
			if (params && *params)
			{
				bltin = ft_builtin(params, &env);
				if (bltin == 1)
					ft_execute(params, envp);
			}
			ft_free_params(params);
		}
	}
	return (0);
}
