/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:15:31 by rklein            #+#    #+#             */
/*   Updated: 2020/06/17 16:40:40 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(char **params, t_env **env)
{
	t_env	*del;
	t_env	*begin;
	int	len;

	len = ft_strlen(params[1]);
	if (ft_strncmp((*env)->var, params[1], len) == 0 && (*env)->var[len] == '=')
	{
		del = *env;
		*env = (*env)->next;
		free(del->var);
		free(del);
	}
	else
	{
		begin = (*env);
		del = (*env)->next;
		while (del)
		{
			if (ft_strncmp(del->var, params[1], len) == 0 && del->var[len] == '=')
				{
					(*env)->next = del->next;
					free(del->var);
					free(del);
					break ;
				}
			del = del->next;
			(*env) = (*env)->next;
		}
		*env = begin;
	}							
}
