/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:00:01 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:20:02 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void			min_up(t_ps *ps, t_a *ta, t_stack *st)
{
	int				mid;
	int				i;

	mid = ps->a_l / 2;
	minmax(ps, ta);
	i = ps->min_a->a;
	if (ps->min_a->next && ps->min_a->next->next == NULL)
		swapper(st, ps, ta);
	else if (mid <= ps->min_a->an)
		while (st->end->an && st->end->a != i)
		{
			ra(ps, ta, 1);
			st_reboot(st);
		}
	else if (mid > ps->min_a->an)
		while (st->end->a != i)
		{
			rra(ps, ta, 1);
			st_reboot(st);
		}
//	if (st->end->a == i && ps->a_l > 1)
//		pb(ps, ta, 1);
}
*/
static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_stack			*st;
	t_a				*tmp;
	int				i;

	tmp = ta;
	st = ft_stack(ta);
	minmax(ps, tmp);
	while (!(sort_a(tmp)) || !(sort_b(tmp)))
	{
		i = ps->a_l;
		while (!sort_a(ta) && i)
		{
			pb(ps, ta, 1);
			swapper(st, ps, ta);
			rotater(st, ps, ta);
			rev_rotater(st, ps, ta);
			i--;
		}
		ft_putnbr(i);
//		if (ps->min_a->an == st->end->an && !(sort_a(ta)))
//			pb(ps, ta, 1);
//		else
//			min_up(ps, ta, st);
		swapper(st, ps, ta);
		rotater(st, ps, ta);
		rev_rotater(st, ps, ta);
		minmax(ps, ta);
		st_reboot(st);
	}
	while (ta->bn != 0)
		pa(ps, ta, 1);
	free(st);
}

int					main(int c, char **s)
{
	t_ps			*ps;
	t_a				*ta;
	int				i;

	i = 1;
	if (!(ta = ta_list()))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(ps = ps_list()) || c < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(ta = recorder(s, ta, ps, i)))
		return (0);
	ft_sorter(ps, ta);
	lst_free(ps, ta);
	return (0);
}
