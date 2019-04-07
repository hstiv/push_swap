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
	int					max;
	t_a					*temp;

	temp = ta;
	max = 0;
	if (ps->a_l > 0)
	{
		max = temp->a;
		while (temp->next && temp->next->an)
		{
			if (max < temp->a)
				max = temp->a;
			temp = temp->next;
		}
		while (temp->prev && temp->b != max)
			temp = temp->prev;
	}
	return (temp);
}

static t_a				*max_b(t_ps *ps, t_a *ta)
{
	int					max;
	t_a					*temp;

	temp = ta;
	max = 0;
	if (ps->b_l > 0)
	{
		max = temp->b;
		while (temp->next && temp->next->bn)
		{
			if (max < temp->b)
				max = temp->b;
			temp = temp->next;
		}
		while (temp->prev && temp->b != max)
			temp = temp->prev;
	}
	return (temp);
}

static t_a				*min_a(t_ps *ps, t_a *ta)
{
	int					min;
	t_a					*temp;

	temp = ta;
	min = 0;
	if (ps->a_l > 0)
	{
		min = temp->a;
		while (temp->next && temp->an)
		{
			if (min > temp->a)
				min = temp->a;
			temp = temp->next;
		}
		while (temp->prev && temp->a != min)
			temp = temp->prev;
	}
	return (temp);
}

static t_a				*min_b(t_ps *ps, t_a *ta)
{
	int					min;
	t_a					*temp;

	temp = ta;
	min = 0;
	if (ps->b_l > 0)
	{
		min = temp->b;
		while (temp->next && temp->next->bn)
		{
			if (min > temp->b)
				min = temp->b;
			temp = temp->next;
		}
		while (temp->prev && temp->b != min)
			temp = temp->prev;
	}
	return (temp);
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
