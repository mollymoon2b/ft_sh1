/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:45:32 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:45:58 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

void	ft_exit(t_env *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
		free(shell->env[i++]);
	if ((shell)->env)
		free(shell->env);
	i = 0;
	while (shell->av[i])
		free(shell->av[i++]);
	if (shell->av)
		free(shell->av);
	shell->pid = 0;
	exit(shell->pid);
}
