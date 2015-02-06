/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:09:40 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:09:40 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int			ft_process_delete(t_env *e)
{
	char	*tmp;

	if (e->index > 0)
	{
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
		tputs(tgetstr("sc", (char **)(&e->p->buf)), 1, ft_putc);
		e->str[e->index - 1] = '\0';
		tmp = ft_strjoin(e->str, e->str + e->index);
		free(e->str);
		e->str = tmp;
		e->max--;
		e->index--;
		tputs(e->str + e->index, 1, ft_putc);
		tputs(" \0", 1, ft_putc);
		tputs(tgetstr("rc", (char **)(&e->p->buf)), 1, ft_putc);
	}
	return (0);
}

int			ft_process_back_delete(t_env *e)
{
	char	*tmp;

	if (e->index < e->max)
	{
		tputs(tgetstr("sc", (char **)(&e->p->buf)), 1, ft_putc);
		e->str[e->index] = '\0';
		tmp = ft_strjoin(e->str, e->str + e->index + 1);
		free(e->str);
		e->str = tmp;
		e->max--;
		tputs(e->str + e->index, 1, ft_putc);
		tputs(" \0", 1, ft_putc);
		tputs(tgetstr("rc", (char **)(&e->p->buf)), 1, ft_putc);
	}
	return (0);
}

int			ft_ctrlk(t_env *e)
{
	char	*tmp;

	if (e->index < e->max)
	{
		ft_clear_imput(e);
		tputs(tgetstr("cd", (char **)(&e->p->buf)), 1, ft_putc);
		e->str[e->index] = '\0';
		tmp = ft_strdup(e->str);
		free(e->str);
		e->str = tmp;
		e->max = ft_strlen(e->str);
		tputs(e->str, 1, ft_putc);
	}
	return (1);
}

int			ft_ctrll(t_env *e)
{
	int		len;

	tputs(tgetstr("cl", (char **)(&e->p->buf)), 1, ft_putc);
	tputs(e->name, 1, ft_putc);
	tputs(e->str, 1, ft_putc);
	len = ft_strlen(e->name) + ft_strlen(e->str);
	tputs(tgoto(tgetstr("cm", (char **)(&e->p->buf)),
		len % tgetnum("co"), len / tgetnum("co")), 1, ft_putc);
	len = ft_strlen(e->str) - e->index + ft_strlen(e->name);
	while (len--)
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	return (1);
}

int			ft_clear(t_env *e, char *inputs)
{
	if (inputs[0] == 11 && inputs[1] == 0 && inputs[2] == 0)
		return (ft_ctrlk(e));
	if (inputs[0] == 12 && inputs[1] == 0 && inputs[2] == 0)
		return (ft_ctrll(e));
	return (0);
}
