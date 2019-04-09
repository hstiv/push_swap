#include "push_swap.h"

void			swapper(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	if (ps->min_a->next && ps->min_a->next->next == NULL)
	{
		if (ps->max_b->next && ps->max_b->next->next)
			ss(ps, ta, 1);
		else
			sa(ps, ta, 1);
	}
}

void			rotater(t_stack *st, t_ps *ps, t_a *ta)
{
	int			i;

	st_reboot(st);
	minmax(ps, ta);
	i = ps->min_a->a;
	if (st->end->an && st->end->a != i && ps->max_b && ps->max_b->bn > (ps->b_l / 2))
		rr(ps, ta, 1);
	else if (st->end->an && st->end->a != i)
		ra(ps, ta, 1);
	else if (ps->max_b && ps->max_b->bn > (ps->b_l / 2))
		rb(ps, ta, 1);
}

void			rev_rotater(t_stack *st, t_ps *ps, t_a *ta)
{
	int			mid;
	int			i;

	st_reboot(st);
	minmax(ps, ta);
	mid = ps->a_l / 2;
	i = ps->min_a->a;
	if (mid > ps->min_a->an)
	{
		if (st->end->a != i && ps->max_b && ps->max_b->bn <= (ps->b_l / 2))
			rrr(ps, ta, 1);
		else if (st->end->a != i)
			rra(ps, ta, 1);
		else if (ps->max_b && ps->max_b->bn <= (ps->b_l / 2))
			rrb(ps, ta, 1);
	}
}