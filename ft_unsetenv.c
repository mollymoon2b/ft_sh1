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

#include "ft_sh1.h"
#include "libft/libft.h"

int	ft_unset_from_env(t_env *shell)
{
	int		line_to_remove;
	int		i;

	i = 0;
	line_to_remove = -1;
	while (shell->env[i] && line_to_remove == -1)
	{
		if (ft_strncmp(ft_strjoin(ft_strtoupper(shell->av[1]), "="),
			shell->env[i], ft_strlen(shell->av[1])) == 0)
			line_to_remove = i;
		++i;
	}
	i = 0;
	while (shell->env[i])
		++i;
	shell->env[line_to_remove] = ft_strdup(shell->env[i - 1]);
	shell->env[i - 1] = 0;
	return (0);
}

int	ft_valid_unsetenv_arg(char *str)
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

int	ft_unsetenv(t_env *shell)
{
	if (shell->ac == 2)
	{
		if (ft_valid_unsetenv_arg(shell->av[1]) == 1)
			ft_unset_from_env(shell);
	}
	return (0);
}
