/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:40:48 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 16:36:21 by rklein           ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_sh	*sh;
	int		bltin;
	int		prompt;
	
	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (0);
	if (argc && argv[0])
	{
		sh->env = ft_arrcpy(envp);
		prompt = 0;
		while (1)
		{
			type_prompt(prompt++);
			sh->par = read_command();
			if (sh->par && sh->par[0])
			{
				bltin = ft_builtin(sh);
				if (bltin == 1)
					ft_execute(sh);
			}
		}
	}
	return (0);
}
