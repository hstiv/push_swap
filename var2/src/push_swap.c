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

static void			ft_algo(t_ps *ps, t_a *ta, t_st *st)
{
	
}

static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_st			*st;

	st = ft_stack(ta);
	minmax(ps, ta);
	if (!if_sort(ta))
	{
		while (ps->a_l > 3)
			pb(ps, ta, 1);
		while (!sort_a(ta))
			rra(ps, ta, 1);
		while (!if_sort(ta));
			algo_p(ps, ta, st);
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
	numgive(ps, ta);
	ft_sorter(ps, ta);
	lst_free(ps, ta);
	return (0);
}
