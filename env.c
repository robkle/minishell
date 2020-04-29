#include "minishell.h"

void	ft_env(t_env *env)
{
	int	i;

	while (env)
	{
		ft_putendl(env->var);
		env = env->next;
	}
}
