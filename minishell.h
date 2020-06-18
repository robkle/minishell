/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:27:26 by rklein            #+#    #+#             */
/*   Updated: 2020/06/17 14:57:35 by rklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct	s_env
{
	char			*var;
	struct s_env	*next;
}				t_env;

int				ft_spacetab(char c);
int				ft_builtin(char **params, t_env **env);
void			ft_execute(char **params, char **env);
int				ft_findslash(char *str);
void			ft_cd(char **params, t_env *env);
void			ft_cd_env(char *path, t_env *env);
void			ft_env(t_env *env);
char			*ft_envcpy(char *dst, char *var, t_env *env);
void			ft_setenv(char **params, t_env *env);
void			ft_unsetenv(char **params, t_env **env);
char			**ft_param_prep(char const *s);
char			ft_qt_track(char s, char q);
void			ft_echo(char **params, t_env *env);

#endif
