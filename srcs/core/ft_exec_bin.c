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
	char	*ptr;
	char	*p1;
	char	*p2;

	p1 = s1;
	p2 = s2;
	printf("Before : '%s' + '%s'\n", s1, s2);
	if (!(str = (char *)malloc(sizeof(ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	ptr = str;
	while (*p1)
		*ptr++ = *p1++;
	*ptr++ = '/';
	while (*p2)
		*ptr++ = *p2++;
	*ptr = '\0';
	printf("After : '%s' + '%s' = '%s'\n", s1, s2, str);
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
			if ((shell->binpath = ft_linkpath(ft_strdup(shell->path[i]), shell->av[0])))
	 		{
	 			// if (access(shell->binpath, F_OK) == 0)
	 				// return (1);
	 			printf("Before : '%s'\n", shell->path[i]);
	 			free(shell->binpath);
	 			printf("After : '%s'\n", shell->path[i]);
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
