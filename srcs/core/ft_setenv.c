/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:27:07 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 13:27:48 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

//done

static int	ft_valid_setenv(char **av)
{
	int		i;

	i = 0;
	while (av[1][i] != 0)
	{
		if (ft_isalpha(av[1][i]) == 0)
		{
			ft_putstr("usage: setenv VAR value\n");
			ft_putstr("VAR can only have [a-z][A-Z] characters\n");
			return (0);
		}
		++i;
	}
	i = 0;
	while (av[2][i] != 0)
	{
		if (ft_isspace(av[2][i]) == 1)
		{
			ft_putstr("usage: setenv VAR value\n");
			ft_putstr("value cannot have space characters\n");
			return (0);
		}
		++i;
	}
	return (1);
}

int			ft_setenv(t_env *shell)
{
	if (shell->ac == 3)
	{
		if (ft_valid_setenv(shell->av) == 1)
			ft_set_env_value(shell, shell->av[1], shell->av[2]);
	}
	else
		ft_putstr("usage: setenv VAR value\n");
	return (0);
}
