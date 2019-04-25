#include "push_swap.h"

static void		hard_oper(t_a *tmp, t_ps *ps, t_st *st, int *i)
{

}
static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	int			i;
	t_a			*ta;

	i = 0;
	ta = st->begin;
	if (ps->a_l / 2 <= tmp->bn)
		i = ps->a_l - tmp->bn;
	else
		i = tmp->bn + 1;
	minmax(ps, ta);
	if (tmp->b <= st->end_a)
		i++;
	else
	{
		if (ps->max_a <= tmp->b)
			i += 2;
		else
			hard_oper(ta, ps, st, &i);
	}
	tmp->op_b = i;
}

void			operations(t_a *ta, t_ps *ps)
{
	int			i;
	t_st		*st;
	t_a			*temp;

	temp = ta;
	st = ft_stack(ta);
	minmax(ps, ta);
	while (temp->bn && !temp->op_b)
	{
		st_reboot(st);
		oper_give(temp, ps, st);
		temp = temp->next;
	}
	free(st);
}
