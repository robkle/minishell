/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:40:48 by rklein            #+#    #+#             */
/*   Updated: 2020/07/07 12:31:03 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	type_prompt(int prompt)
{
	char		cwd[PATH_MAX];

	if (prompt == 0)
		write(STDOUT_FILENO, "\e[1;1H\e[2J", 12);
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
	int		count;
	char	buf;
	char	qt;

	count = 0;
	qt = 0;
	read(0, &buf, 1);
	while (1)
	{
		qt = ft_qt_track(buf, qt);
		if (buf == '\n' && qt == 0)
			break ;
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

void		ft_minishell(t_sh *sh)
{
	int		prompt;
	int		bltin;

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
		ft_free_array(sh->par);
	}
}
