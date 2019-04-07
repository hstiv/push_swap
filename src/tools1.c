/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:21:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:39:50 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		find_mm_a(t_ps *ps, t_a *ta)
{
	int		i;

	i = 0;
	while (i < ps->a_l)
	{
		if (ps->min_a > ps->a[i])
			ps->min_a = ps->a[i];
		i++;
	}
	i = 0;
	while (i < ps->a_l)
	{
		if (ps->max_a < ps->a[i])
			ps->max_a = ps->a[i];
		i++;
	}
	i = 0;
	while (i < ps->a_l)
	{
		if (ps->min_a == ps->a[i])
			ps->min_a = i;
		if (ps->max_a == ps->a[i])
			ps->max_a = i;
		i++;
	}
}

void		find_mm_b(t_ps *ps, t_a *ta)
{
	int		i;

	i = 0;
	while (i < ps->b_l)
	{
		if (ps->min_b > ps->b[i])
			ps->min_b = ps->b[i];
		i++;
	}
	i = 0;
	while (i < ps->b_l)
	{
		if (ps->max_b < ps->b[i])
			ps->max_b = ps->b[i];
		i++;
	}
	i = 0;
	while (i < ps->b_l)
	{
		if (ps->min_b == ps->b[i])
			ps->min_b = i;
		if (ps->max_b == ps->b[i])
			ps->max_b = i;
		i++;
	}
}

void		where_close_to(t_ps *ps, t_a *ta)
{
	int		i;

	i = ps->a_l / 2;
	ps->flotx = (ps->max_a * 10) / ps->a_l;
	ps->flotn = (ps->min_a * 10) / ps->a_l;
	if ((ps->flotx >= 7 && ps->flotn <= 3) || (ps->flotx <= 3 && ps->flotn >= 7))
	{
		while(i--)
			pb(ps, ta, 1);
	}
	else if (ps->flotx >=7 && ps->flotn >= 7 && ps->flotx > ps->flotn)
	{
		while (ps->flotn <= 9 && 10 >= ps->flotx++)
			ra(ps, ta, 1);
		while (i--)
			pb(ps, ta, 1);
	}
	else if ((ps->flotx < 4 && ps->flotn < 4) && (ps->flotx > ps->flotn))
	{
		while (ps->flotx > 0 && 0 <= ps->flotn--)
			rra(ps, ta, 1);
		while (i--)
			pb(ps, ta, 1);
	}
}