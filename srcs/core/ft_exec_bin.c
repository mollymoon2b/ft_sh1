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

char		*ft_linkpath(char *s1, char *s2)
{
	char	*str;
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(l1 + l2 + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	*(str + l1) = '/';
	ft_strcpy(str + l1 + 1, s2);
	*(str + l1 + l2 + 1) = '\0';
	printf("'%s' + '%s' = '%s'\n", s1, s2, str);
	return (str);
}

int			ft_set_binpath(t_env *shell)
{
	int		i;

	i = 0;
	if (shell->path != NULL)
	{
		if (ft_strlen(shell->av[0]) > 3 && shell->av[0][0] == '.' &&
			shell->av[0][1] == '/' && access(shell->av[0] + 2, F_OK) == 0)
		{
			shell->binpath = ft_strdup(shell->av[0] + 2);
			return (1);
		}
		while (shell->path[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->path[i], shell->av[0])))
	 		{
	 			// if (access(shell->binpath, F_OK) == 0)
	 				// return (1);
	 			free(shell->binpath);
	 		}
			++i;
		}
	}
	return (0);
}

int			ft_exec_bin(t_env *shell)
{
	pid_t	cpid;

	if (ft_set_binpath(shell))
	{
		cpid = fork();
		if (cpid != -1)
		{
			if (cpid == 0)
			{
				if (execve(shell->binpath, shell->av, shell->env) == -1)
					ft_putstr("\nERROR\n"); //make re && ./ft_minishell1
			}
			else
				waitpid(cpid, 0, 0);
		}
		free(shell->binpath);
	}
	return (0);
	cpid++;
}
