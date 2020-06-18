/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:27:26 by rklein            #+#    #+#             */
/*   Updated: 2020/06/18 16:36:14 by rklein           ###   ########.fr       */
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

typedef struct	s_sh
{
	char	**par;
	char	**env;
}				t_sh;

int				ft_spacetab(char c);
int				ft_builtin(t_sh *sh);
void			ft_execute(t_sh *sh);
char			**ft_arrcpy(char **src);
int				ft_findslash(char *str);
void			ft_cd(t_sh *sh);
void			ft_cd_env(t_sh *sh);
void			ft_env(char **env);
void			ft_setenv(t_sh *sh);
void			ft_unsetenv(t_sh *sh);
char			**ft_param_prep(char const *s);
char			ft_qt_track(char s, char q);
void			ft_echo(t_sh *sh);
void			ft_free_array(char **array);

#endif
