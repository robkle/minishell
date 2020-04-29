#include "minishell.h"

void	ft_cd_env(char *path, t_env *env)
{
	char	*oldpwd[3];
	char	*pwd[3];
	
	oldpwd[1] = ft_strdup("OLDPWD");
	oldpwd[2] = ft_strnew(PATH_MAX);
	getcwd(oldpwd[2], PATH_MAX);
	printf("oldpwd: %s\n", oldpwd[2]);
	ft_setenv(oldpwd, env);
	chdir(path);
	pwd[1] = ft_strdup("PWD");
	pwd[2] = ft_strnew(PATH_MAX);
	getcwd(pwd[2] , PATH_MAX);
	printf("pwd: %s\n", pwd[2]);
	if (ft_strcmp(path, ".") != 0)
		ft_setenv(pwd, env);
}
