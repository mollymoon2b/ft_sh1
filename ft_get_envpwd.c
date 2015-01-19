
#include "libft/libft.h"
#include "ft_minishell.h"

char	*ft_get_envpwd(char **env)
{
	char	*get_pwd_line;
	int		i;

	get_pwd_line = NULL;
	i = 0;
	while (env[i] && get_pwd_line == NULL)
	{
		if (ft_strncmp("PWD", env[i], 2) == 0)
		{
			get_pwd_line = ft_strsub(ft_strdup(env[i]),
										4,
										ft_strlen(env[i]) - 4);
		}
		++i;
	}
	return (get_pwd_line);
}
