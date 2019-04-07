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

	tmp = ta;
	while (tmp->prev)
		tmp = tmp->prev;
	
}

static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_stack			*st;
	t_a				*tmp;

 	tmp = ta;
	st = ft_stack(ta);
	minmax(ps, tmp);
	while (if_sort(ta) == 0)
	{
		if (ps->min_a == st->end)
			pb(ps, ta, 1);
		else
			min_up(ps, ta);
	}
	free(st);
}

int					main(int c, char **s)
{
	t_ps			*ps;
	t_a				*ta;
	int				i;

	i = 1;
	if (!(ta = ta_list()) || !(ps = ps_list()))
	{
		lst_free(ps, ta);
		ft_putstr("Error\n");
		return (0);
	}
	if (!(ta = recorder(s, ta, ps, i)))
		return (0);
	ft_sorter(pa, ta);
	lst_free(ps, ta);
	return (0);
}
