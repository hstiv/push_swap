/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:51:18 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/07 14:51:20 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_a				*max_a(t_ps *ps, t_a *ta)
{
	t_a					*temp;
	t_a					*max;

	temp = ta;
	max = temp;
	if (ps->a_l > 0)
	{
		while (temp && temp->an)
		{
			if (max->a < temp->a)
				max = temp;
			temp = temp->next;
		}
	}
	return (max);
}

static t_a				*max_b(t_ps *ps, t_a *ta)
{
	t_a					*max;
	t_a					*temp;

	temp = ta;
	max = ta;
	if (ps->b_l > 0)
	{
		while (temp && temp->bn)
		{
			if (max->b < temp->b)
				max = temp;
			temp = temp->next;
		}
	}
	return (max);
}

static t_a				*min_a(t_ps *ps, t_a *ta)
{
	t_a					*min;
	t_a					*temp;

	temp = ta;
	min = ta;
	if (ps->a_l > 0)
	{
		while (temp && temp->an)
		{
			if (min->a > temp->a)
				min = temp;
			temp = temp->next;
		}
	}
	return (min);
}

static t_a				*min_b(t_ps *ps, t_a *ta)
{
	t_a					*min;
	t_a					*temp;

	temp = ta;
	min = ta;
	if (ps->b_l > 0)
	{
		while (temp && temp->next->bn)
		{
			if (min->a > temp->b)
				min = temp;
			temp = temp->next;
		}
	}
	return (min);
}

void					minmax(t_ps *ps, t_a *ta)
{
	t_a					*begin;

	begin = ta;
	while (begin->prev)
		begin = begin->prev;
	if (ps->a_l > 0)
	{
		ps->max_a = max_a(ps, begin);
		ps->min_a = min_a(ps, begin);
	}
	if (ps->b_l > 0)
	{
		ps->max_b = max_b(ps, begin);
		ps->min_b = min_b(ps, begin);
	}
}
