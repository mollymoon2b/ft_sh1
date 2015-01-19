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
#include "ft_minishell.h"

void	ft_error_2char(char *str, char *str2)
{
	write (1, str, ft_strlen(str));
	write (1, str2, ft_strlen(str2));
}

int	main(void)
{
	extern const char	**environ;
	t_env			*shell;

	shell = malloc(sizeof(t_env));
	if (shell != NULL)
	{
		shell->pid = 1;
		shell->env = ft_dup_environ(environ);
		shell->pwd = ft_get_envpwd(shell->env);
		shell->oldpwd = NULL;
		shell->av = malloc(sizeof(char *));
		if (shell->av[0] != NULL)
			shell->av[0] = NULL;
		signal(SIGINT, SIG_IGN);
		while (shell->pid == 1)
			ft_display_prompt(&shell);
	}
	return (0);
}
