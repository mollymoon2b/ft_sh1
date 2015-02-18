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

void			ft_len_word(char *ptr, int *len, int *size)
{
	char		quote;

	quote = '\0';
	while (*ptr)
	{
		if (!quote && *ptr == '\\')
		{
			ptr++;
			(*size)++;
		}
		else
		{
			if (!quote && (*ptr == '\'' || *ptr == '"'))
			{
				quote = *ptr;
				*size += 2;
				*len -= 2;
			}
			else if (quote)
				quote = (*ptr == quote) ? '\0' : quote;
			else if (*ptr == ' ' || *ptr == '\t')
				break ;
		}
		(*ptr && (*len)++) ? ptr += 1 : ptr;
	}
	(*(ptr - 1) == '\\') ? (*len)-- : *len;
}

void			ft_copy_word(char **word, char *str)
{
	char		quote;
	char		*ptr;

	quote = '\0';
	ptr = *word;
	while (*str)
	{
		if (!quote && *str == '\\')
			*ptr++ = *++str;
		else
		{
			if (!quote && (*str == '\'' || *str == '"'))
				quote = *str;
			else if (quote && *str == quote)
				quote = '\0';
			else if (*str == ' ' || *str == '\t')
				break ;
			else
				*ptr++ = *str;
		}
		str++;
	}
	*ptr = '\0';
}

char			*ft_get_word(char **str)
{
	char		*word;
	int 		len;
	int 		size;

	len = 0;
	size = 0;
	ft_len_word(*str, &len, &size);
	// printf("The length of the word = %i, %i\n", len, size);
	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_copy_word(&word, (**str == '\'' || **str == '"') ? *str + 1 : *str);
	*str += len + size;
	return (word);
}

static size_t	ft_parse_len(char *str)
{
	/*char	*ptr;
	char	quote;
	size_t	size;
	int		in;

	quote = '\0';
	in = 0;
	size = 0;
	ptr = input;
	while (*ptr)
	{
		if (*ptr == '\\')
			ptr++;
		else
		{
			if (quote)
			{
				if (*ptr == quote)
					quote = '\0';
			}
			else if (*ptr == '\'' || *ptr == '"')
				quote = *ptr;
			else
			{
				if (in)
				{
					if (*ptr == ' ' || *ptr == '\t')
						in = 0;
				}
				else if (*ptr != ' ' && *ptr != '\t')
				{
					in = 1;
					size++;
				}
			}
		}
		ptr++;
	}
	return (size);*/
	int		len;
	int		size;
	size_t	v;

	v = 0;
	// printf("\nInit : '%s'\n", str);
	while (*str)
	{
		len = 0;
		size = 0;
		ft_len_word(str, &len, &size);
		str += len + size;
		// printf("Len = %i, size = %i\n", len, size);
		// printf("Newptr : '%s'\n", str);
		while (*str == ' ' || *str == '\t')
			str++;
		v++;
	}
	// printf("\nV = %i\n\n", (int)v);
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
	while (len--)
	{
		*argv++ = ft_get_word(&input);
		while (*input == ' ' || *input == '\t')
			input++;
		printf("Adding word : '%s'\n", *(argv - 1));
	}
	*argv = NULL;
	return (argv);
	// str = ft_strdup(input);
	// printf("Len = %i\n", len);
	// printf("\tGENERATED WORD = '%s'\n", ft_get_word(&input));
	// return (ft_strasplit(input, " \t"));
	// free(str);
	// return (output);
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
			// ft_free_strarray(&shell->av);
	}
}
