/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispay_propmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:42:56 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:43:26 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_minishell.h"
#include "get_next_line.h"

void	ft_display_prompt(t_env **shell)
{
	write (1, "$>", 2);
	if (get_next_line(0, &(*shell)->input) > 0)
	{
		(*shell)->path = ft_get_envpath((*shell)->env);
		ft_parse_input(&(*shell));
	}
	else
		ft_exit(&(*shell));
}
