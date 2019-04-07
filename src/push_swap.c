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

static void			min_up(t_ps *ps, t_a *ta, t_stack *st)
{
	t_a				*tmp;
	int				mid;
	int				i;

	mid = ps->a_l / 2;
	tmp = ta;
	minmax(ps, ta);
	i = ps->min_a->a;
	while (tmp->prev)
		tmp = tmp->prev;
	if (ps->min_a->next == NULL)
		sa(ps, ta, 1);
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
	if (st->end->a == i && ps->a_l > 1)
		pb(ps, ta, 1);
}

static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_stack			*st;
	t_a				*tmp;
	int				i;

	i = 0;
 	tmp = ta;
	st = ft_stack(ta);
	minmax(ps, tmp);
	while (!(sort_a(ta)) && i < 5)
	{
		if (ps->min_a->an == st->end->an && !(sort_a(ta)))
			pb(ps, ta, 1);
		else
			min_up(ps, ta, st);
		minmax(ps, ta);
		st_reboot(st);
		i++;
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
	if (!(ta = ta_list()) || !(ps = ps_list()) || c < 2)
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
