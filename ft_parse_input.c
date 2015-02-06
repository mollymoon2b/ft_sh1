/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:47:36 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:47:39 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_sh1.h"

void	ft_print_environ(t_env *shell)
{
	int	i;

	if (shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			ft_putstr(shell->env[i]);
			ft_putstr("\n");
			++i;
		}
	}
}

int		ft_count_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		++i;
	return (i);
}

char	**ft_parse_args(char *input)
{
	char	**av;

	input = ft_strdel_double_sp(ft_strdup_tabtosp(input));
	av = ft_strsplit(input, ' ');
	return (av);
}

void	ft_parse_input(t_env *shell)
{

	if (*shell->str)
	{
		shell->av = ft_parse_args(shell->str);
		shell->ac = ft_count_arg(shell->av);
		if (shell->ac != 0)
		{
			if (ft_strcmp(ft_strtolower(shell->av[0]), "env") == 0)
				ft_print_environ(shell);
			else if (ft_strcmp(ft_strtolower(shell->av[0]), "setenv") == 0)
				ft_setenv(shell);
			else if (ft_strcmp(ft_strtolower(shell->av[0]),
								"unsetenv") == 0)
				ft_unsetenv(shell);
			else if (ft_strcmp(ft_strtolower(shell->av[0]), "exit") == 0)
				ft_exit(shell);
			else if (ft_strcmp(ft_strtolower(shell->av[0]), "cd") == 0)
				ft_cd(shell);
			else
				ft_exec_bin(shell);
		}
	}
}
