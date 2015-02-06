#include "ft_sh1.h"

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
}

void ft_goleft(t_env *e)
{
	int n;

	if (e->str[e->index - 1] == '\t')
		n = 8;
	else
		n = 1;
	while (n-- > 0)
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	e->index--;
}

void ft_goright(t_env *e)
{
	int n;
	
	if (e->str[e->index] == '\t')
		n = 8;
	else
		n = 1;
	while (n-- > 0)
		ft_trucbidule(e);
	e->index++;
}