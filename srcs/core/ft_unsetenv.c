/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:27:56 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 13:28:24 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

//done

static void	ft_remove_from_env(t_env *shell, int pos, int size)
{
	char	**ne;
	char	**ptr;
	char	**penv;

	if (!(ne = (char **)malloc(sizeof(char *) * size + 1)))
		return ;
	ptr = ne;
	penv = shell->env;
	while (size--)
	{
		if (pos-- == 0)
			penv++;
		*ptr++ = *penv++;
	}
	*ptr = '\0';
	free(shell->env);
	shell->env = ne;
}

static void	ft_unset_from_env(t_env *shell)
{
	int		line_to_remove;
	int		i;

	i = 0;
	line_to_remove = -1;
	while (shell->env[i])
	{
		if (ft_namematch(shell->av[1], shell->env[i]))
			line_to_remove = i;
		++i;
	}
	if (line_to_remove != i)
		ft_remove_from_env(shell, line_to_remove, i);
}

static int	ft_valid_unsetenv_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			return (0);
		++i;
	}
	return (1);
}

int			ft_unsetenv(t_env *shell)
{
	if (shell->ac == 2)
	{
		if (ft_valid_unsetenv_arg(shell->av[1]) == 1)
			ft_unset_from_env(shell);
	}
	return (0);
}
