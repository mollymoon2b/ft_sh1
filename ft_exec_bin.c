/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:44:47 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:44:59 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_minishell.h"

int			ft_set_binpath(t_env **shell)
{
	int		i;

	i = 0;
	if ((*shell)->path != NULL)
	{
		(*shell)->binpath = (*shell)->av[0];
		if (access((*shell)->binpath, F_OK) == 0)
			return (0);
		while ((*shell)->path[i] && (*shell)->av[0])
		{
			(*shell)->binpath = ft_strjoin((*shell)->path[i], "/");
			(*shell)->binpath = ft_strjoin((*shell)->binpath,
											(*shell)->av[0]);
			if (access((*shell)->binpath, F_OK) == 0)
				return (0);
			++i;
		}
		if ((*shell)->binpath)
			free((*shell)->binpath);
		(*shell)->binpath = NULL;
		ft_error_2char((*shell)->av[0], ":command not found\n");//printf("%s : command not found\n", (*shell)->av[0]);
	}
	else
		printf("bash: %s: Undefined environment PATH\n", (*shell)->av[0]);
	return (-1);
}

int			ft_exec_bin(t_env **shell)
{
	pid_t	cpid;

	if (ft_set_binpath(&(*shell)) == 0)
	{
		cpid = fork();
		if (cpid != -1)
		{
			if (cpid == 0)
				execve((*shell)->binpath, (*shell)->av, (*shell)->env);
			else
				waitpid(cpid, 0, 0);
		}
	}
	return (0);
}
