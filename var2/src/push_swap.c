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

static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_stack			*st;
	int				i;
	long long int	med;
	int				a;

	a = 40;
	st = ft_stack(ta);
	minmax(ps, ta);
	med = median(ta, ps);
	while (!if_sort(ta))
	{
		i = ps->a_l - 3;
		while (i && !sort_a(ta))
		{
			if (st->end_a->a > med)
			{
				ra(ps, ta, 1);
				st_reboot(st);
			}
			if (st->end_a->a > st->end_a->prev->a)
				sa(ps, ta, 1);
			pb(ps, ta, 1);
			minmax(ps, ta);
			st_reboot(st);
			if (st->end_b->b > st->begin->b && st->end_b->b > st->end_b->prev->b)
				ra(ps, ta, 1);
			else if (st->end_b->b > st->begin->b && st->end_b->b < st->end_b->prev->b)
				rra(ps, ta, 1);
			st_reboot(st);
			i--;
		}
		if (!sort_a(ta))
		{
			minmax(ps, ta);
			while (ps->max_a->a != st->begin->a)
				ra(ps, ta, 1);
			st_reboot(st);
			if (st->end_a->a > st->end_a->prev->a)
				sa(ps, ta, 1);
		}
		while (st->begin->bn > 0)
		{
			minmax(ps, ta);
			if (ps->max_b->bn >= ps->b_l / 2)
			{
				while (st->end_b->b != ps->max_b->b)
				{
					rb(ps, ta, 1);
					minmax(ps, ta);
					st_reboot(st);
				}
				pa(ps, ta, 1);
			}
			else
			{
				while (st->end_b->b != ps->max_b->b)
				{
					rrb(ps, ta, 1);
					minmax(ps, ta);
					st_reboot(st);
				}
				pa(ps, ta, 1);
			}
			st_reboot(st);
			minmax(ps, ta);
			if (st->end_a->a != ps->min_a->a)
			{
				if (st->end_a->a > st->end_a->prev->a)
					sa(ps, ta, 1);
				else if (st->end_a->a > st->begin->a)
					ra(ps, ta, 1);
				minmax(ps, ta);
				st_reboot(st);
			}
		}
	}
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
