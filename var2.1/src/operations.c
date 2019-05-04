/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:28:55 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/04 16:29:24 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_a		*magic_raw(t_a *raw, t_a *tmp, t_st *st, t_ps *ps)
{
	t_a			*temp;
	int			i;

	raw = st->end_a;
	temp = raw;
	i = tmp->num_b + 1;
	while (i <= ps->b_l + ps->a_l)
	{
		while (temp)
		{
			if (temp->num_a == i)
			{
				raw = temp;
				return (raw);
			}
			temp = temp->prev;
		}
		temp = raw;
		i++;
	}
	return (raw);
}

static void		mid_op(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*raw;

	raw = st->end_a;
	raw = magic_raw(raw, tmp, st, ps);
	if (ps->a_l > raw->an * 2)
		op_write(tmp, "rra", raw->an);
	else
		op_write(tmp, "ra", ps->a_l - raw->an);
}

static void		hard_oper(t_a *tmp, t_ps *ps, t_st *st)
{
	minmax(ps, tmp);
	st_reboot(st);
	if (ps->max_a->a < tmp->b)
	{
		if ((ps->min_a->an * 2) <= ps->a_l)
			op_write(tmp, "rra", ps->min_a->an);
		else
			op_write(tmp, "ra", ps->a_l - ps->min_a->an);
	}
	else if (ps->min_a->a > tmp->b)
	{
		if ((ps->min_a->an * 2) <= ps->a_l)
			op_write(tmp, "rra", ps->min_a->an);
		else
			op_write(tmp, "ra", ps->a_l - ps->min_a->an);
	}
	else
		mid_op(tmp, ps, st);
	op_write(tmp, "pa", 1);
}

static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*ta;

	ta = st->begin;
	st_reboot(st);
	if (ps->b_l <= tmp->bn * 2)
		op_write(tmp, "rb", ps->b_l - tmp->bn);
	else
		op_write(tmp, "rrb", tmp->bn);
	st_reboot(st);
	hard_oper(tmp, ps, st);
}

void			operations(t_a *ta, t_ps *ps)
{
	t_st		*st;
	t_a			*temp;

	st = ft_stack(ta);
	temp = st->end_b;
	minmax(ps, ta);
	while (temp != NULL)
	{
		st_reboot(st);
		op_clr(temp);
		oper_give(temp, ps, st);
		temp = temp->prev;
	}
	free(st);
}
