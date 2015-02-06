/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_managechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:14:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/06 14:08:43 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		ft_process_fchar(t_env *e, char *inputs)
{
	char	*tmp;

	tmp = ft_strjoin(e->str, inputs);
	free(e->str);
	e->str = tmp;
	tmp = NULL;
	tputs(inputs, 1, ft_putc);
}

void		ft_process_lchar(t_env *e, char *inputs)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	tputs(tgetstr("cd", (char **)(&e->p->buf)), 1, ft_putc);
	tputs(inputs, 1, ft_putc);
	tputs(e->str + e->index, 1, ft_putc);
	if (((ft_strlen(e->name) + e->index) % tgetnum("co")) == tgetnum("co") - 2)
	{
		tputs(" \0", 1, ft_putc);
		len = e->max - e->index + 1;
	}
	else
		len = e->max - e->index;
	while (len--)
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	tmp2 = ft_strndup(e->str, e->index);
	tmp = ft_strjoin(tmp2, inputs);
	free(tmp2);
	tmp2 = ft_strjoin(tmp, e->str + e->index);
	free(tmp);
	free(e->str);
	e->str = tmp2;
}

int			ft_process_char2(t_env *e, char *inputs)
{
	if (e->index == e->max)
		ft_process_fchar(e, inputs);
	else
		ft_process_lchar(e, inputs);
	e->max++;
	e->index++;
	return (1);
}

int			ft_process_charloop(t_env *e, char *inputs)
{
	int		i;
	char	tmp[2];

	tmp[1] = '\0';
	i = 0;
	while (inputs[i] && i < 5)
	{
		tmp[0] = inputs[i];
		inputs[i] = '\0';
		ft_process_char2(e, tmp);
		i++;
	}
	return (i);
}

int			ft_process_char(t_env *e, char *inputs)
{
	if (ft_process_charloop(e, inputs) == 5)
	{
		while ((read(0, inputs, 5)) != EOF)
		{
			if (inputs[0] == 3 || inputs[0] == 4 || inputs[0] == 10)
				return (ft_quit(e, inputs));
			if (ft_delete(e, inputs))
				return (2);
			if (ft_arrows(e, inputs))
				return (2);
			if (ft_clear(e, inputs))
				return (2);
			ft_process_charloop(e, inputs);
			ft_bzero(inputs, 5);
		}
	}
	return (2);
}
