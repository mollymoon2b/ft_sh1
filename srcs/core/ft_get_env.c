/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envoldpwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:46:42 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/06 15:45:11 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// kind of done

char	**ft_get_envpath(t_env *shell)
{
	char	*path_line;
	char	**path;

	path_line = ft_get_env_value(shell, "PATH");
	path = NULL;
	if (path_line)
	{
		path = ft_strsplit(path_line, ':');
		free(path_line);
	}
	return (path);
}
