#include "push_swap.h"

int						median(t_a *ta, t_ps *ps)
{
	t_a					*temp;

	temp = ta;
	while (temp->next && temp->an < (ps->max_a->an / 2))
		temp = temp->next;
	return (temp->an);
}

int						search_if_mid(int mid, t_a *ta)
{
	t_a					*temp;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	while ()
}

void					swapper(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	if ((st->end_a->an + 1) == st->end_a->prev->a && st->end_b->prev &&
		st->end_b->b == (st->end_b->prev->a + 1))
		ss(ps, ta, 1);
	else if (st->end_a->prev && (st->end_a->a + 1) == st->end_a->prev->a)
			sa(ps, ta, 1);
}

void					rotater(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	pa(ps, ta, 1);
	ra(ps, ta, 1);
	st_reboot(st);
	minmax(ps, ta);
}

void					rev_rotater(t_stack *st, t_ps *ps, t_a *ta)
{
	st_reboot(st);
	minmax(ps, ta);
	if (st->end_a && st->end_a->a > st->begin->a && st->end_a && st->end_a->a > st->end_a->prev->a)
		rra(ps, ta, 1);
}