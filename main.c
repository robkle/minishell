/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:26 by rklein            #+#    #+#             */
/*   Updated: 2020/07/01 12:09:38 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_sh	*sh;

	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (0);
	if (argc && argv[0])
	{
		sh->env = ft_arrcpy(envp);
		ft_shellenv(sh, argv[0]);
		ft_minishell(sh);
	}
	return (0);
}
