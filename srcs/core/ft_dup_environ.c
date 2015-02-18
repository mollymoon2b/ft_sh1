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

#include "../../includes/ft_sh1.h"

// arthur

char			**ft_dup_environ(char **environ)
{
	char	**ptr;
	char		**bis;
	char		**ptr2;
	size_t		i;

	i = 0;
	ptr = environ;
	while (*ptr++)
		i++;
	if (!(bis = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	ptr = environ;
	ptr2 = bis;
	while (*ptr)
	{
		*ptr2++ = ft_strdup(*ptr++);
		++i;
	}
	*ptr2 = NULL;
	return (bis);
}
