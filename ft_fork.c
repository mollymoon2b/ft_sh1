
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "libft/libft.h"
#include "ft_minishell.h"

int	ft_fork(t_shell **shell)
{
	if (((*shell)->pid = fork()) < 0)
	{
		printf("Error on fork function.\n");
		return (-1);
	}
	if ((*shell)->pid)
	{
		if (waitpid((*shell)->pid, 0, 0) < 0)
		{
			printf("Error on waitpid function\n");
			return (-1);
		}
		return (0);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		return (0);
	}
	return (-1);
}
