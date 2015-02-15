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

static t_params	*ft_get_params(void)
{
	t_params	*p;

	p = (t_params *)ft_memalloc(sizeof(t_params));
	p->c_pos_x = 0;
	p->c_pos_y = 0;
	p->print = 0;
	p->v_term = getenv("TERM");
	if (tgetent(p->buf, p->v_term) < 1)
		return (NULL);
	tcgetattr(0, &p->term);
	p->term.c_lflag &= ~(ICANON);
	p->term.c_lflag &= ~(ECHO);
	p->term.c_cc[VMIN] = 1;
	p->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p->term) == -1)
		return (NULL);
	p->height = tgetnum ("li");
	p->width = tgetnum ("co");
	p->max_size = 1;
	p->col_count = 1;
	return (p);
}

t_env			*ft_get_env(void)
{
	static t_env	*e = NULL;

	if (!e)
	{
		e = (t_env *)ft_memalloc(sizeof(t_env));
		e->name = ft_strdup("Shell > ");
		if (!(e->p = ft_get_params()))
			return (NULL);
		e->str = ft_strdup("");
		e->max = 0;
		e->index = 0;
		e->histo = (t_str *)ft_memalloc(sizeof(t_str));
	}
	return (e);
}

void			ft_clean_env(t_env *e)
{
	free(e->str);
	e->str = ft_strdup("");
	e->index = 0;
	e->max = 0;
}
