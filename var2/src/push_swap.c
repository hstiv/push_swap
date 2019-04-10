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

static void			sort_four(t_ps *ps, t_a *ta, t_stack *st, int med)
{
	t_a				*temp;
	int				i;

	i = 0;
	st_reboot(st);
	while (med > 1 && ps->a_l > med)
	{
		temp = ta;
		while (temp->next)
		{
			if (temp->an > med)
				i++;
			temp = temp->next;
		}
		while (i)
		{
			temp = st->end_a;
			if (temp->an < med)
				pb(ps, ta, 1);
			else
			{
				ra(ps, ta, 1);
				i--;
			}
			st_reboot(st);
		}
		med /= 2;
		sort_four(ps, ta, st, med);
		st_reboot(st);
	}
}

//static void			

static void			separater(t_ps *ps, t_a *ta, t_stack *st)
{
	int				med;
	int				i;
	int				len;

	len = ps->a_l;
	med = median(ta, ps);
	st_reboot(st);
	i = 1;
	minmax(ps, ta);
	if (!sort_a(ta))
	{
		sort_four(ps, ta, st, med);

	}
	
}

static void			ft_sorter(t_ps *ps, t_a *ta)
{
	t_stack			*st;
	int				i;

	st = ft_stack(ta);
	minmax(ps, ta);
	if (!if_sort(ta))
	{
		i = ps->a_l;
		separater(ps, ta, st);
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
