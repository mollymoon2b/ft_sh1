
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_minishell.h"

int			ft_set_binpath(t_shell **shell)
{
	int		i;

	i = 0;
	if ((*shell)->path != NULL)
	{
		(*shell)->binpath = (*shell)->argv[0];
		if (access((*shell)->binpath, F_OK) == 0)
			return (0);
		while ((*shell)->path[i] && (*shell)->argv[0])
		{
			(*shell)->binpath = ft_strjoin((*shell)->path[i], "/");
			(*shell)->binpath = ft_strjoin((*shell)->binpath,
											(*shell)->argv[0]);
			if (access((*shell)->binpath, F_OK) == 0)
				return (0);
			++i;
		}
		if ((*shell)->binpath)
			free((*shell)->binpath);
		(*shell)->binpath = NULL;
		printf("%s : command not found\n", (*shell)->argv[0]);
	}
	else
		printf("bash: %s: Undefined environment PATH\n", (*shell)->argv[0]);
	return (-1);
}

int			ft_exec_bin(t_shell **shell)
{
	pid_t	cpid;

	if (ft_set_binpath(&(*shell)) == 0)
	{
		cpid = fork();
		if (cpid != -1)
		{
			if (cpid == 0)
				execve((*shell)->binpath, (*shell)->argv, (*shell)->env);
			else
				waitpid(cpid, 0, 0);
		}
	}
	return (0);
}
