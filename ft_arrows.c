/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:16:08 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/06 14:16:09 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_shellup(t_env *e)
{
	if (e->phisto->next)
	{
		ft_clear_imput(e);
		free(e->phisto->tmp);
		e->phisto->tmp = ft_strdup(e->str);
		e->phisto = e->phisto->next;
		if (!e->phisto->tmp)
			e->phisto->tmp = ft_strdup(e->phisto->str);
		free(e->str);
		e->str = ft_strdup(e->phisto->tmp);
		e->max = ft_strlen(e->str);
		e->index = e->max;
		tputs(e->str, 1, ft_putc);
	}
}

void	ft_shelldown(t_env *e)
{
	if (e->phisto != e->histo)
	{
		ft_clear_imput(e);
		free(e->phisto->tmp);
		e->phisto->tmp = ft_strdup(e->str);
		e->phisto = e->phisto->past;
		if (!e->phisto->tmp)
			e->phisto->tmp = ft_strdup(e->phisto->str);
		free(e->str);
		e->str = ft_strdup(e->phisto->tmp);
		e->max = ft_strlen(e->str);
		e->index = e->max;
		tputs(e->str, 1, ft_putc);
	}
}

void 	ft_trucbidule(t_env *e)
{
	char tmp[2];

	if (((ft_strlen(e->name) + e->index) % tgetnum("co"))
			!= tgetnum("co") - 1)
		tputs(tgetstr("nd", (char **)(&e->p->buf)), 1, ft_putc);
	else
	{
		tmp[1] = '\0';
		tmp[0] = e->str[e->index];
		tputs(tmp, 1, ft_putc);
		tmp[0] = e->str[e->index + 1];
		tputs(tmp, 1, ft_putc);
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	}
	e->index++;
}

void	ft_leftright(t_env *e, char *inputs)
{
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 68)
	{
		if (e->index > 0)
		{
			tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
			e->index--;
		}
		else
			tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	}
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 67)
	{
		if (e->max > e->index)
		{
			ft_trucbidule(e);
		}
		else
			tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	}
}

int		ft_arrows(t_env *e, char *inputs)
{
	ft_leftright(e, inputs);
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 66)
		ft_shelldown(e);
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 65)
		ft_shellup(e);
	if ((inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 68) ||
		(inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 67) ||
		(inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 66) ||
		(inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 65))
		return (1);
	return (0);
}
