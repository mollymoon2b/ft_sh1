
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_minishell.h"

void	ft_exit(t_shell **shell)
{
	int	i;

	i = 0;
	while ((*shell)->env[i])
		free((*shell)->env[i++]);
	if ((*shell)->env)
		free((*shell)->env);
	if ((*shell)->input)
		free((*shell)->input);
	i = 0;
	while ((*shell)->argv[i])
		free((*shell)->argv[i++]);
	if ((*shell)->argv)
		free((*shell)->argv);
	(*shell)->pid = 0;
}
