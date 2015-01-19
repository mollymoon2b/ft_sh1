
#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_minishell.h"

char	**ft_dup_environ(const char **environ)
{
	char	**copie;
	size_t	i;

	i = 0;
	while (environ[i])
		i++;
	copie = (char **)malloc((i + 1) * sizeof(char *));
	if (copie == NULL)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		copie[i] = ft_strdup(environ[i]);
		++i;
	}
	copie[i] = 0;
	return (copie);
}
