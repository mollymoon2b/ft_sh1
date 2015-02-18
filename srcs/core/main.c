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

t_env	*ft_call_env(t_env **shell)
{
	static t_env *save;

	if (shell && *shell)
	{
		save = *shell;
		return (NULL);
	}
	else
		return (save);
}

void	ft_error_2char(char *str, char *str2)
{
	ft_putstr("Shell :");
	ft_putstr(str);
	ft_putstr(str2);
}

void ft_ctrl_c(int sig_num)
{
	t_env *shell;

	shell = ft_call_env(NULL);
	if (shell->cpid)
	{
		ft_putstr("^C\n");
		shell->cpid = 0;
	}
	return ;
	sig_num++;
}

int		main(int argc, char **argv, char **envp)
{
	t_env				*shell;
	int					value;

	if (!(shell = ft_get_env(envp)))
		return (0);
	ft_call_env(&shell);
	tputs(tgetstr("ve", (char **)(&shell->p->buf)), 1, ft_putc);
	tputs(tgetstr("vs", (char **)(&shell->p->buf)), 1, ft_putc);
	
	signal(SIGINT, ft_ctrl_c);

	while ((value = ft_get_inputs(shell)))
	{
		ft_display_prompt(shell, value);
		if (!(ft_clean_env(shell)))
			break ;
	}
	return (0);
	argc++;
	argv++;
}
