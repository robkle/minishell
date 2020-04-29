#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../libft/libft.h" //TEMP

typedef struct s_env
{
	char		*var;
	struct s_env	*next;
}			t_env;

void	ft_cd(char **params, t_env *env);
void	ft_cd_env(char *path, t_env *env);
void	ft_env(t_env *env);
void	ft_setenv(char **params, t_env *env);
void	ft_unsetenv(char **params, t_env **env);
char	**ft_param_prep(char const *s);
char	ft_qt_track(char s, char q);
void	ft_echo(char **params, t_env *env);

#endif
