/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:44:47 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/15 14:15:17 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

t_env				*ft_call_env(t_env **shell)
{
	static t_env	*save;

	if (shell && *shell)
	{
		save = *shell;
		return (NULL);
	}
	else
		return (save);
}

static int			ft_set_binpath(t_env *shell)
{
	int				i;

	i = 0;
	if (shell->path != NULL)
	{
		if (access(shell->av[0], X_OK) == 0)
		{
			shell->binpath = ft_strdup(shell->av[0]);
			return (0);
		}
		while (shell->paths[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->paths[i++],\
									shell->av[0], '/')))
			{
				if (access(shell->binpath, X_OK) == 0)
					return (0);
				free(shell->binpath);
			}
		}
		ft_error_2char("shell: no such file or directory: ", shell->av[0]);
	}
	else
		ft_error_2char("Undefined environment PATH :", shell->av[0]);
	return (-1);
}

void				ft_exec_bin(t_env *shell)
{
	if (ft_set_binpath(shell) == 0)
	{
		ft_restore_signals(shell);
		dprintf(1, "Forking '%s'\n", shell->binpath);
		shell->cpid = fork();
		if (shell->cpid != -1)
		{
			if (shell->cpid == 0)
				execve(shell->binpath, shell->av, shell->env);
			else
				waitpid(shell->cpid, 0, 0);
		}
		free(shell->p);
		free(shell->binpath);
		shell->p = ft_get_params();
		shell->cpid = 0;
		ft_init_signals();
	}
}
