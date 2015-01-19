/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:46:07 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:46:11 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_minishell.h"

int	ft_fork(t_env **shell)
{
	if (((*shell)->pid = fork()) < 0)
	{
		write(1, "Error on fork function.\n", 25);
		return (-1);
	}
	if ((*shell)->pid)
	{
		if (waitpid((*shell)->pid, 0, 0) < 0)
		{
			write(1, "Error on waitpid function\n", 28);
			return (-1);
		}
		return (0);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		return (0);
	}
	return (-1);
}
