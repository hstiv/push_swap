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
		i = ps->a_l;
		while (ps->max_a->next->an != 0)
			pb(ps, ta, 1);
		
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
