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

char		*ft_linkpath(char *s1, char *s2, char c)
{
	char	*str;
	char	*ptr;
	char	*p1;
	char	*p2;

	p1 = s1;
	p2 = s2;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	ptr = str;
	while (*p1)
		*ptr++ = *p1++;
	*ptr++ = c;
	while (*p2)
		*ptr++ = *p2++;
	*ptr = '\0';
	return (str);
}

int			ft_set_binpath(t_env *shell)
{
	int		i;

	i = 0;
	shell->binpath = NULL;
	if (shell->path != NULL)
	{
		if (access(shell->av[0], X_OK) == 0)
		{
			shell->binpath = ft_strdup(shell->av[0]);
			return (0);
		}
		while (shell->path[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->path[i], shell->av[0], '/')))
			{
	 			if (access(shell->binpath, X_OK) == 0)
	 				return (0);
				free(shell->binpath);
			}
			++i;
		}
		ft_error_2char(shell->av[0], ": command not found\n");
	}
	else
		ft_error_2char(shell->av[0], ": Undefined environment PATH\n");
	return (-1);
}

void		ft_exec_bin(t_env *shell)
{
	if (ft_set_binpath(shell) == 0)
	{
		shell->cpid = fork();
		if (shell->cpid != -1)
		{
			if (shell->cpid == 0)
				execve(shell->binpath, shell->av, shell->env);
			else
				waitpid(shell->cpid, 0, 0);
		}
		free(shell->p);
		if (!(shell->p = ft_get_params()))
			return ;
		free(shell->binpath);
	}
	return ;
}
