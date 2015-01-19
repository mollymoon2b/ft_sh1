
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_minishell.h"

char	**ft_parse_get_args(char *input)
{
	char	**argv;

	input = ft_strdel_double_sp(ft_strdup_tabtosp(input));
	argv = ft_strsplit(input, ' ');
	return (argv);
}

void	ft_parse_input(t_shell **shell)
{
	if (*(*shell)->input)
	{
		(*shell)->argv = ft_parse_get_args((*shell)->input);
		(*shell)->argc = ft_count_arg((*shell)->argv);
		if ((*shell)->argc != 0)
		{
			if (ft_strcmp(ft_strtolower((*shell)->argv[0]), "env") == 0)
				ft_print_environ(*shell);
			//else if (ft_strcmp(ft_strtolower((*shell)->argv[0]), "setenv") == 0)
			//	ft_setenv(&(*shell));
			//else if (ft_strcmp(ft_strtolower((*shell)->argv[0]),
			//					"unsetenv") == 0)
			//	ft_unsetenv(&(*shell));
			else if (ft_strcmp(ft_strtolower((*shell)->argv[0]), "exit") == 0)
				ft_exit(&(*shell));
			//else if (ft_strcmp(ft_strtolower((*shell)->argv[0]), "cd") == 0)
			//	ft_cd(&(*shell));
			else
				ft_exec_bin(&(*shell));
		}
	}
}
