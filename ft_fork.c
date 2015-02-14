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

#include "ft_sh1.h"

// done

int	ft_fork(t_env *shell)
{
	if ((shell->pid = fork()) < 0)
	{
		ft_putstr("Error on fork function.\n");
		return (-1);
	}
	if (shell->pid)
	{
		if (waitpid(shell->pid, 0, 0) < 0)
		{
			ft_putstr("Error on waitpid function\n");
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
