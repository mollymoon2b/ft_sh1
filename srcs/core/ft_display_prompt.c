/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispay_propmt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:42:56 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:43:26 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// arthur

void	ft_display_prompt(t_env *shell, int value)
{
	if (value == 1)
	{
		shell->path = ft_get_envpath(shell);
		ft_parse_input(shell);
		// printf("\tCall1 on :\n");
		// ft_free_strarray(&shell->path);
		shell->path = NULL;
		// printf("\tCall1 off :\n");
	}
	else if (value == 0)
		ft_exit(shell);
}
