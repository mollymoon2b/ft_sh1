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
#include "libft/libft.h"

int	ft_add_var_env(t_env *shell, int len, char *var_env)
{
	int		i;
	char	**env;

	env = malloc((len + 2) * sizeof(char *));
	if (env != NULL)
	{
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
		shell->env = env;
		return (0);
	}
	return (-1);
}

int	ft_set_var_env(t_env *shell)
{
	int		i;
	char	*var_env;

	i = 0;
	var_env = ft_strdup(ft_strtoupper(shell->av[1]));
	var_env = ft_strjoin(var_env, "=");
	var_env = ft_strjoin(var_env, shell->av[2]);
	while (shell->env[i])
	{
		if (ft_strncmp(ft_strjoin(ft_strtoupper(shell->av[1]), "="),
			shell->env[i], ft_strlen(shell->av[1])) == 0)
		{
			shell->env[i] = ft_strdup(var_env);
			return (0);
		}
		++i;
	}
	if (ft_add_var_env(shell, i, var_env) == 0)
		return (0);
	return (-1);
}

int	ft_valid_setenv(char **av)
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

int	ft_setenv(t_env *shell)
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
