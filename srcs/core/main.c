/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:48:01 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:48:05 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static char			**ft_get_envpath(t_env *shell)
{
	char			*path_line;
	char			**path;

	if (!(path_line = ft_get_env_value(shell, "PATH")))
	{
		path_line = ft_strdup(shell->path);
		ft_set_env_value(shell, "PATH", path_line);
	}
	path = NULL;
	if (path_line)
	{
		path = ft_strsplit(path_line, ':');
		free(path_line);
	}
	return (path);
}


static void			ft_ctrl_c(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (shell->cpid)
	{
		ft_putstr("^C\n");
		shell->cpid = 0;
	}
	return ;
	sig_num++;
}

void			ft_launch(t_env *shell)
{
	char			**imputs;
	char			**ptr;

	if (!(imputs = ft_strsplit(shell->str, ';')))
		return ;
	free(shell->str);
	ptr = imputs;
	while (ptr && *ptr)
	{
		shell->str = *ptr++;
		shell->paths = ft_get_envpath(shell);
		ft_parse_input(shell);
		ft_free_strarray(&shell->paths);
	}
	ft_free_strarray(&imputs);
	shell->str = NULL;
}

int					main(int argc, char **argv, char **envp)
{
	t_env			*shell;
	int				value;

	if (!(shell = ft_get_env(envp)))
		return (0);
	ft_call_env(&shell);
	tputs(tgetstr("ve", (char **)(&shell->p->buf)), 1, ft_putc);
	tputs(tgetstr("vs", (char **)(&shell->p->buf)), 1, ft_putc);
	signal(SIGINT, ft_ctrl_c);
	while ((value = ft_get_inputs(shell)))
	{
		if (value == 0)
			ft_exit(shell);
		if (shell->str && *shell->str)
			ft_launch(shell);
		if (!(ft_clean_env(shell)))
			break ;
	}
	return (0);
	argc++;
	argv++;
}
