/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 13:30:42 by rklein            #+#    #+#             */
/*   Updated: 2020/06/12 13:42:56 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_setenv_new(char **params, t_env *env)
{
	t_env	*tmp;
	
	tmp = env->next;
	while (tmp)
	{
		tmp = tmp->next;
		env = env->next;
	}
	env->next = malloc(sizeof(t_env));
	env = env->next;
	env->var = (char*)malloc(sizeof(char) * (PATH_MAX + 1));
	ft_strcpy(env->var, params[1]);
	ft_strcat(env->var, "=");
	if (params[2])
		ft_strcat(env->var, params[2]);
}

void	ft_setenv(char **params, t_env *env)
{
	t_env	*new;
	
	if (!params[1])
	{
		ft_env(env);
		return ;
	}
	new = env;
	while (env)
	{
		if (strncmp(env->var, params[1], ft_strlen(params[1])) == 0)
		{
			ft_strclr(env->var);
			ft_strcat(env->var, params[1]);
			ft_strcat(env->var, "=");
			if (params[2])
				ft_strcat(env->var, params[2]); 
			break;
		}
		env = env->next;
	}
	if (env == NULL)
		ft_setenv_new(params, new);
}
