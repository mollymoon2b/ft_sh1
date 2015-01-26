/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:48:01 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:48:05 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_sh1.h"

void	ft_error_2char(char *str, char *str2)
{
	write (1, "Shell: ", 7);
	write (1, str, ft_strlen(str));
	write (1, str2, ft_strlen(str2));
}

int		main(void)
{
	extern const char	**environ;
	t_env				*shell;
	int					value;

	if (!(shell = ft_get_env()))
		return (0);
	tputs(tgetstr("ve", (char **)(&shell->p->buf)), 1, ft_putc);
	tputs(tgetstr("vs", (char **)(&shell->p->buf)), 1, ft_putc);
	shell->env = ft_dup_environ(environ);
	while ((value = ft_get_inputs(shell)))
	{
		if (shell != NULL)
		{
			shell->pid = 1;
			shell->oldpwd = NULL;
			signal(SIGINT, SIG_IGN);
		}
		ft_display_prompt(&shell, value);
		ft_clean_env(shell);
	}
	return (0);
}
