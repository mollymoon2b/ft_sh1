/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:46:49 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:46:50 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_minishell.h"

char	**ft_get_envpath(char **env)
{
	char	*path_line;
	char	**path;
	int		i;

	path_line = NULL;
	path = NULL;
	i = 0;
	while (env[i] && path_line == NULL)
	{
		if (ft_strncmp("PATH", env[i], 3) == 0)
			path_line = ft_strsub(ft_strdup(env[i]),
				5, ft_strlen(env[i]) - 5);
		++i;
	}
	if (path_line != NULL)
		path = ft_strsplit(path_line, ':');
	return (path);
}
