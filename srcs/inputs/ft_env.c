/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:27:30 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:27:30 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// arthur

t_params		*ft_get_params(void)
{
	t_params	*p;

	if (!(p = (t_params *)ft_memalloc(sizeof(t_params))))
		return (NULL);
	p->c_pos_x = 0;
	p->c_pos_y = 0;
	p->print = 0;
	if (!(p->v_term = getenv("TERM")))
		return (NULL);
	if (tgetent(p->buf, p->v_term) < 1)
		return (NULL);
	tcgetattr(0, &p->term);
	p->term.c_lflag &= ~(ICANON);
	p->term.c_lflag &= ~(ECHO);
	p->term.c_cc[VMIN] = 1;
	p->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p->term) == -1)
		return (NULL);
	p->max_size = 1;
	p->col_count = 1;
	return (p);
}

static void		ft_update_shlvl(t_env *e)
{
	char		**shlvl;
	char		*v;

	if ((shlvl = ft_get_env_addr(e, "SHLVL")))
	{
		v = ft_itoa(ft_atoi(*shlvl + 6) + 1);
		ft_set_env_value(e, "SHLVL", v);
		free(v);
	}
	else
		ft_set_env_value(e, "SHLVL", "1");
}

t_env			*ft_get_env(char **envp)
{
	t_env		*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	e->name = ft_strdup("Shell > ");
	if (!(e->p = ft_get_params()))
		return (NULL);
	if (!(e->str = ft_strdup("")))
		return (NULL);
	e->max = 0;
	e->index = 0;
	if (!(e->histo = (t_str *)ft_memalloc(sizeof(t_str))))
		return (NULL);
	e->env = ft_dup_environ(envp);
	e->pwd = ft_get_env_value(e, "PWD");
	e->home = ft_get_env_value(e, "HOME");
	e->oldpwd = ft_get_env_value(e, "OLDPWD");
	ft_update_shlvl(e);
	e->binpath = NULL;
	return (e);
}

int				ft_clean_env(t_env *e)
{
	if (e->str)
		free(e->str);
	if (!(e->str = ft_strdup("")))
		return (0);
	e->index = 0;
	e->max = 0;
	return (1);
}
