
#include "libft/libft.h"
#include "ft_minishell.h"

void	ft_print_environ(t_shell *shell)
{
	int	i;

	if (shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			printf("%s\n", shell->env[i]);
			++i;
		}
	}
}
