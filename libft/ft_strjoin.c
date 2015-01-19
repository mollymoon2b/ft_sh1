/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:38:23 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/11 11:39:10 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ft_strnew(len1 + len2 + 1);
	if (s3)
	{
		ft_memcpy(s3, s1, len1);
		ft_memcpy(s3 + len1, s2, len2);
		s3[len1 + len2] = '\0';
		return (s3);
	}
	return (NULL);
}
