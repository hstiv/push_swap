#include "push_swap.h"

long long int			median(t_a *ta, t_ps *ps)
{
	long long int		med;

	med = 0;
	while (ta->next)
	{
		med += ta->a;
		ta = ta->next;
	}
	med = med / ps->a_l;
	return (med);
}

void					swapper(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	if (st->end_a->a > st->end_a->prev->a && st->end_b->prev &&
		st->end_b->b < st->end_b->prev->a)
		ss(ps, ta, 1);
	else if (st->end_a->prev && st->end_a->a > st->end_a->prev->a)
			sa(ps, ta, 1);
}

void					rotater(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	if (st->end_a->a > st->begin->a)
	{
		if (st->end_a->prev && st->end_a->a > st->end_a->prev->a)
			ra(ps, ta, 1);
	}
}

void					rev_rotater(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	if (st->end_a && st->end_a->a > st->begin->a && st->end_a && st->end_a->a > st->end_a->prev->a)
		rra(ps, ta, 1);
}