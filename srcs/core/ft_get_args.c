/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:47:36 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:47:39 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static	char	*ft_get_word(char **str, char quote)
{
	char		*ptr;
	char		*word;

	if (!(word = (char *)ft_memalloc(sizeof(char) * ft_strlen(*str))))
		return (NULL);
	ptr = word;
	while (*(*str))
	{
		if (!quote && *(*str) == '\\')
			*ptr++ = *++(*str);
		else
		{
			if (!quote && (*(*str) == '\'' || *(*str) == '"'))
				quote = *(*str);
			else if (quote && *(*str) == quote)
				quote = '\0';
			else if (!quote && (*(*str) == ' ' || *(*str) == '\t'))
				break ;
			else
				*ptr++ = *(*str);
		}
		(*str)++;
	}
	*ptr = '\0';
	return (word);
}

static size_t	ft_parse_len(char *str)
{
	char		*tmp;
	size_t		v;

	v = 0;
	while (*str)
	{
		tmp = ft_get_word(&str, '\0');
		free(tmp);
		while (*str == ' ' || *str == '\t')
			str++;
		v++;
	}
	return (v);
}

char			**ft_parse_args(char *input)
{
	char		**argv;
	char		**ptr;
	int			len;

	len = ft_parse_len(input);
	if (!(argv = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	ptr = argv;
	while (len-- && *input)
	{
		*ptr = ft_get_word(&input, '\0');
		if (**ptr)
			ptr++;
		else
			free(*ptr);
		while (*input == ' ' || *input == '\t')
			input++;
	}
	*ptr = NULL;
	return (argv);
}