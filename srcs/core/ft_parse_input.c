/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:47:36 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:47:39 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"
//done (edit static lower)

void		ft_print_environ(t_env *shell)
{
	int		i;

	if (shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			ft_putstr(shell->env[i]);
			ft_putstr("\n");
			++i;
		}
	}
}

static int	ft_count_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		++i;
	return (i);
}

char			*ft_get_word(char **str, char quote)
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
	char	*tmp;
	size_t	v;

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



static char		**ft_parse_args(char *input)
{
	char	**argv;
	char	**ptr;
	int		len;
	// int		size;

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

int	ft_commandmatch(char *name, char *test)
{
	while (*name && *name == *test)
	{
		name++;
		test++;
	}
	if (!*name && !*test)
		return (1);
	return (0);
}

void		ft_parse_input(t_env *shell)
{
	if (*shell->str)
	{
		shell->av = ft_parse_args(shell->str);
		if ((shell->ac = ft_count_arg(shell->av)))
		{
			if (ft_commandmatch("env", shell->av[0]))
				ft_print_environ(shell);
			else if (ft_commandmatch("setenv", shell->av[0]))
				ft_setenv(shell);
			else if (ft_commandmatch("unsetenv", shell->av[0]))
				ft_unsetenv(shell);
			else if (ft_commandmatch("exit", shell->av[0]))
				ft_exit(shell);
			else if (ft_commandmatch("cd", shell->av[0]))
				ft_cd(shell);
			else
				ft_exec_bin(shell);
		}
		// if (shell->av)
			ft_free_strarray(&shell->av);
	}
}
