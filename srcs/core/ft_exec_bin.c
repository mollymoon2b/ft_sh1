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

char	*ft_linkpath(char *s1, char *s2)
{
	char	*str;
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(l1 + l2 + 2))))
		return (NULL);
	ft_strcpy(str, s1);
	*(str + l1++) = '/';
	ft_strcpy(str + l1, s2);
	*(str + l1 + l2 + 1) = '\0';
	return (str);
}

int			ft_set_binpath(t_env *shell)
{
	int		i;

	i = 0;
	if (shell->path != NULL)
	{
		if (access(shell->av[0], F_OK) == 0)
		{
			shell->binpath = ft_strdup(shell->av[0]);
			return (0);
		}
		while (shell->path[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->path[i], shell->av[0])))
		 		if (access(shell->binpath, F_OK) == 0)
		 			return (0);
		 		printf("Free number 1 on : '%s'\n", shell->binpath);
	 			// free(shell->binpath);
	 			// shell->binpath = NULL;
		 		printf("Free number 1 off : '%s'\n", shell->binpath);
			++i;
		}
		shell->binpath = NULL;
		// ft_putstr("av[0] = '");
		// ft_putstr(shell->av[0]);
		// ft_putstr("'\n");
//		printf("\n\nAv[0] = '%s'\n", shell->av[0]);
		ft_error_2char(shell->av[0], ": command not found\n");
		write(1, "a", 1);
	}
	else
		ft_error_2char(shell->av[0], ": Undefined environment PATH\n");
	return (-1);
}

int			ft_exec_bin(t_env *shell)
{
	 pid_t	cpid;

	if (ft_set_binpath(shell) == 0)
	{
		cpid = fork();
		if (cpid != -1)
		{
			if (cpid == 0)
				execve(shell->binpath, shell->av, shell->env);
			else
				waitpid(cpid, 0, 0);
		}
		printf("Free number 2 on : '%s'\n", shell->binpath);
		// free(shell->binpath);
		// shell->binpath = NULL;
		printf("Free number 2 off : '%s'\n", shell->binpath);
	}
	return (0);
}
