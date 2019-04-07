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

static void			min_up(t_ps *ps, t_a *ta)
{
	t_a				*tmp;
	int				mid;

	mid = ps->a_l / 2;
	tmp = ta;
	while (tmp->prev)
		tmp = tmp->prev;
	if (ps->min_a->next == NULL)
		sa(ps, ta, 1);
	else if (mid <= ps->min_a->an)
		while (ps->min_a->an < ps->a_l)
		{
			ra(ps, ta, 1);
			minmax(ps, ta);
		}
	else if (mid > ps->min_a->an)
		while (ps->min_a->an < ps->a_l)
		{
			rra(ps, ta, 1);
			minmax(ps, ta);
		}
	if (ps->min_a->next == NULL)
		pb(ps, ta, 1);
}

static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_stack			*st;
	t_a				*tmp;

 	tmp = ta;
	st = ft_stack(ta);
	minmax(ps, tmp);
	while (!(sort_a(ta)))
	{
		if (ps->min_a->an == st->end->an && !(sort_a(ta)))
			pb(ps, ta, 1);
		else
			min_up(ps, ta);
		minmax(ps, ta);
	}
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
