#include "push_swap.h"

void				numgive(t_ps *ps, t_a *ta)
{
	int				i;
	int				a;
	t_a				*tmp;

	while (ta->prev)
		ta = ta->prev;
	tmp = ta;
	a = 2;
	minmax(ps, ta);
	i = ps->min_a->a + 1;
	ps->min_a->an = 1;
	while (i <= ps->max_a->a)
	{	
		tmp = ta;
		while (tmp)
		{
			if (tmp->a == i)
			{
				tmp->an = a;
				a++;
			}
			tmp = tmp->next;
		}
		i++;
	}
}