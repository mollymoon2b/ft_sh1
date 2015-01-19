
#include "libft/libft.h"
#include "ft_minishell.h"
#include "get_next_line.h"

void	ft_display_prompt(t_shell **shell)
{
	write (1, "$>", 2);
	if (get_next_line(0, &(*shell)->input) > 0)
	{
		(*shell)->path = ft_get_envpath((*shell)->env);
		ft_parse_input(&(*shell));
	}
	else
		ft_exit(&(*shell));
}
