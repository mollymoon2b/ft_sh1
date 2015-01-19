
#include "libft/libft.h"
#include "ft_minishell.h"

char	*ft_get_envoldpwd(char **env)
{
	char	*get_oldpwd_line;
	int		i;

	get_oldpwd_line = NULL;
	i = 0;
	while (env[i] && get_oldpwd_line == NULL)
	{
		if (ft_strncmp("OLDPWD", env[i], 5) == 0)
		{
			get_oldpwd_line = ft_strsub(ft_strdup(env[i]),
										7,
										ft_strlen(env[i]) - 7);
		}
		++i;
	}
	return (get_oldpwd_line);
}
