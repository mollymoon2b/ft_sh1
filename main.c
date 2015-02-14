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

#include "ft_sh1.h"

void	ft_error_2char(char *str, char *str2)
{
	ft_putstr("Shell :");
	ft_putstr(str);
	ft_putstr(str2);
}

int			ft_exec_pwd_test(t_env *shell)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid != -1)
	{
		if (cpid == 0)
			execve("/bin/pwd", ft_strsplit("pwd", ' '), shell->env);
		else
			waitpid(cpid, 0, 0);
	}
	return (0);
}

int			ft_exec_ls_test(t_env *shell)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid != -1)
	{
		if (cpid == 0)
			execve("/bin/ls", ft_strsplit("ls .", ' '), shell->env);
		else
			waitpid(cpid, 0, 0);
	}
	return (0);
}

int		main(void)
{
	extern const char	**environ;
	t_env				*shell;
	int					value;
	char *test;

	if (!(shell = ft_get_env()))
		return (0);
	tputs(tgetstr("ve", (char **)(&shell->p->buf)), 1, ft_putc);
	tputs(tgetstr("vs", (char **)(&shell->p->buf)), 1, ft_putc);
	shell->env = ft_dup_environ(environ);
	while ((value = ft_get_inputs(shell)))
	{
		if (shell != NULL)
		{
			shell->pid = 1;
			shell->oldpwd = NULL;
			signal(SIGINT, SIG_IGN);
		}
		ft_display_prompt(shell, value);
		ft_clean_env(shell);
	}
	return (0);

shell->env = ft_dup_environ(environ);
ft_exec_pwd_test(shell);
test = ft_strdup("/nfs/zfs-student-2/users/2014/achazal/");
if (access(test, F_OK) == 0)
	chdir(test);
ft_exec_pwd_test(shell);
ft_exec_ls_test(shell);
	return (0);
	environ++;
	value++;
	shell++;
}
