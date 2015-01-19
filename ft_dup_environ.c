/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:44:38 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:44:39 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_minishell.h"

char	**ft_dup_environ(const char **environ)
{
	char	**bis;
	size_t	i;

	i = 0;
	while (environ[i])
		i++;
	bis = (char **)malloc((i + 1) * sizeof(char *));
	if (bis == NULL)
		return (NULL);
	i = 0;
	while (environ[i])
	{
		bis[i] = ft_strdup(environ[i]);
		++i;
	}
	bis[i] = 0;
	return (bis);
}
