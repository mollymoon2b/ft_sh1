
#include "libft/libft.h"
#include "ft_minishell.h"

char	*ft_get_envhome(char **env)
{
	char	*get_home_line;
	int		i;

	get_home_line = NULL;
	i = 0;
	while (env[i] && get_home_line == NULL)
	{
		if (ft_strncmp("HOME", env[i], 3) == 0)
			get_home_line = ft_strsub(ft_strdup(env[i]),
										5,
										ft_strlen(env[i]) - 5);
		++i;
	}
	return (get_home_line);
}
