
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_minishell.h"

int	main(void)
{
	extern const char	**environ;
	t_shell				*shell;

	shell = malloc(sizeof(t_shell));
	if (shell != NULL)
	{
		shell->pid = 1;
		shell->env = ft_dup_environ(environ);
		shell->pwd = ft_get_envpwd(shell->env);
		shell->oldpwd = NULL;
		shell->argv = malloc(sizeof(char *));
		if (shell->argv[0] != NULL)
			shell->argv[0] = NULL;
		signal(SIGINT, SIG_IGN);
		while (shell->pid == 1)
			ft_display_prompt(&shell);
	}
	return (0);
}
