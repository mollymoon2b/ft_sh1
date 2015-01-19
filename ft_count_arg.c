
#include "libft/libft.h"
#include "ft_minishell.h"

int	ft_count_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		++i;
	return (i);
}
