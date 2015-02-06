/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:55:51 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/06 14:17:34 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <sys/param.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <pwd.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <curses.h>
# define MIN_W 10

typedef struct		s_params
{
	char			**av;
	int				ac;
	char			*v_term;
	char			buf[2048];
	struct termios	term;
	char			r_char[4];
	int				height;
	int				print;
	int				width;
	tcflag_t		old_term;
	int				c_pos_x;
	int				c_pos_y;
	int				l_count;
	int				col_count;
	int				max_size;
}					t_params;

typedef struct		s_str
{
	char			*str;
	char			*tmp;
	struct s_str	*next;
	struct s_str	*past;
}					t_str;

typedef struct		s_env
{
	char			**env;
	pid_t			pid;
	char			*input;
	int				ac;
	char			**av;
	char			**path;
	char			*pwd;
	char			*oldpwd;
	char			*binpath;
	char			*name;
	t_params		*p;
	char			*str;
	size_t			index;
	size_t			max;
	t_str			*histo;
	t_str			*phisto;
}					t_env;

char				**ft_dup_environ(const char **environ);
void				ft_display_prompt(t_env *shell, int value);
void				ft_print_environ(t_env *shell);
int					ft_fork(t_env *shell);
void				ft_parse_input(t_env *shell);
int					ft_count_arg(char **argv);
int					ft_setenv(t_env *shell);
int					ft_unsetenv(t_env *shell);
void				ft_exit(t_env *shell);
char				**ft_get_envpath(char **env);
int					ft_exec_bin(t_env *shell);
char				*ft_get_envpwd(char **env);
char				*ft_get_envoldpwd(char **env);
char				*ft_get_envhome(char **env);
int					ft_cd(t_env *shell);
char				*ft_get_pwd(void);
int					ft_cd(t_env *shell);
char				*ft_rel_pwd(char *path);
int					ft_updat_cdpwd(t_env *shell);
int					ft_update_env_pwd(t_env *shell);
int					ft_update_old_pwd(t_env *shell);
void				ft_error_2char(char *str, char *str2);
int					ft_unsetenv(t_env *shell);
int					ft_valid_unsetenv_arg(char *str);
int					ft_unset_from_env(t_env *shell);
int					ft_add_var_env(t_env *shell, int len, char *var_env);
int					ft_setenv(t_env *shell);
int					ft_valid_setenv(char **argv);
int					ft_set_var_env(t_env *shell);

void				ft_shellup(t_env *e);
void				ft_shelldown(t_env *e);
void				ft_leftright(t_env *e, char *inputs);
int					ft_arrows(t_env *e, char *inputs);
char				*ft_chardup(char c);
int					ft_clear_imput(t_env *e);
void				ft_clean_histo(t_env *e);
void				ft_update_imput(t_env *e);
void				ft_endline(t_env *e);
void				ft_cursor_to_end(t_env *e);
int					ft_process_delete(t_env *e);
int					ft_process_back_delete(t_env *e);
int					ft_ctrlk(t_env *e);
int					ft_ctrll(t_env *e);
int					ft_clear(t_env *e, char *inputs);
t_params			*ft_get_params(void);
t_env				*ft_get_env(void);
void				ft_clean_env(t_env *e);
int					ft_quit(t_env *e, char *inputs);
int					ft_delete(t_env *e, char *inputs);
void				ft_lstr_inputsinit(t_env *e);
int					ft_manage_inputs(t_env *e, char *inputs);
int					ft_get_inputs(t_env *e);
void				ft_lststr_add(t_str **lst, t_str *new);
t_str				*ft_lststr_new(char *str);
void				ft_process_fchar(t_env *e, char *inputs);
void				ft_process_lchar(t_env *e, char *inputs);
int					ft_process_char2(t_env *e, char *inputs);
int					ft_process_charloop(t_env *e, char *inputs);
int					ft_process_char(t_env *e, char *inputs);
int					ft_putc(int c);
void				ft_put_histo(t_env *e);

#endif
