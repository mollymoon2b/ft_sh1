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

#include "ft_sh1.h"

//done

static void	ft_add_var_env(t_env *shell, int len, char *var_env)
{
	int		i;
	char	**env;

	if (!(env = malloc((len + 2) * sizeof(char *))))
		return ;
	i = 0;
	while (shell->env[i])
	{
		env[i] = ft_strdup(shell->env[i]);
		free(shell->env[i]);
		++i;
	}
	env[i] = ft_strdup(var_env);
	++i;
	env[i] = 0;
	free(shell->env);
	shell->env = env;
}

static void	ft_set_var_env(t_env *shell)
{
	int		i;
	char	*var_env;

	if (!(var_env = (char *)malloc(sizeof(char) * (ft_strlen(shell->av[1]) +
		ft_strlen(shell->av[2]) + 2))))
		return ;
	i = ft_strlen(shell->av[1]);
	ft_strcpy(var_env, shell->av[1]);
	ft_strcpy(var_env + i++, "=");
	ft_strcpy(var_env + i++, shell->av[2]);
	*(var_env + i + ft_strlen(shell->av[2])) = '\0';
	i = 0;
	while (shell->env[i])
	{
		if (ft_namematch(shell->av[1], shell->env[i]))
		{
			free(var_env);
			shell->env[i] = ft_strdup(var_env);
			return ;
		}
		i++;
	}
	ft_add_var_env(shell, i, var_env);
	free(var_env);
}

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
			ft_set_var_env(shell);
	}
	else
		ft_putstr("usage: setenv VAR value\n");
	return (0);
}
