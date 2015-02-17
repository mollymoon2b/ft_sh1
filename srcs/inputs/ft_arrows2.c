/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:16:08 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/06 14:16:09 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// arthur

void		ft_cursorup(t_env *e)
{
	size_t	len;

	len = tgetnum("co");
	if (!e->index)
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	else if ((ft_strlen(e->name) + e->index) < len)
	{
		while (e->index)
			ft_goleft(e);
	}
	else
	{
		while (e->index && len--)
			ft_goleft(e);
	}
}

void		ft_cursordown(t_env *e)
{
	size_t	len;

	len = tgetnum("co");
	if (e->index == e->max)
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	else if ((ft_strlen(e->name) + e->index) / len == e->max / len)
	{
		while (e->index != e->max)
			ft_goright(e);
	}
	else
	{
		while (e->index != e->max && len--)
			ft_goright(e);
	}
}

void		ft_cursorleft(t_env *e)
{
	if (!e->index)
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	else
	{
		if (e->index && e->str[e->index] != ' ')
			ft_goleft(e);
		while (e->index && e->str[e->index] == ' ')
			ft_goleft(e);
		while (e->index && e->str[e->index] != ' ')
			ft_goleft(e);
		if (e->index != e->max && e->str[e->index] == ' ')
			ft_goright(e);
	}
}

void		ft_cursorright(t_env *e)
{
	if (e->index == e->max)
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	else
	{
		if (e->index && e->str[e->index] != ' ')
			ft_goleft(e);
		while (e->str[e->index] && e->str[e->index] == ' ')
			ft_goright(e);
		while (e->str[e->index] && e->str[e->index] != ' ')
			ft_goright(e);
		if (e->index != e->max && e->str[e->index] == ' ')
			ft_goright(e);
	}
}

void		ft_arrows2(t_env *e, char kind)
{
	if (kind == 65)
		ft_cursorup(e);
	if (kind == 66)
		ft_cursordown(e);
	if (kind == 68)
		ft_cursorleft(e);
	if (kind == 67)
		ft_cursorright(e);
	return ;
}
