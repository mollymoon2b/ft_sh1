/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:45:24 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:47:19 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <sys/param.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>

typedef struct	s_env
{
	char		**env;
	pid_t		pid;
	char		*input;
	int			ac;
	char		**av;
	char		**path;
	char		*pwd;
	char		*oldpwd;
	char		*binpath;
}				t_env;

char			**ft_dup_environ(const char **environ);
void			ft_display_prompt(t_env **shell);
void			ft_print_environ(t_env *shell);
int				ft_fork(t_env **shell);
void			ft_parse_input(t_env **shell);
int				ft_count_arg(char **argv);
int				ft_setenv(t_env **shell);
int				ft_unsetenv(t_env **shell);
void			ft_exit(t_env **shell);
char			**ft_get_envpath(char **env);
int				ft_exec_bin(t_env **shell);
char			*ft_get_envpwd(char **env);
char			*ft_get_envoldpwd(char **env);
char			*ft_get_envhome(char **env);
int				ft_cd(t_env **shell);
char			*ft_get_pwd(void);

void	ft_error_2char(char *str, char *str2);
#endif
