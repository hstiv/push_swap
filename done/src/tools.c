/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:33:30 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/04 16:33:32 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					op_clr(t_a *ta)
{
	int					i;

	i = 0;
	ta->op_b = 0;
	while (i < 7000)
	{
		ta->oper[i] = 0;
		ta->ra_oper[i] = 0;
		ta->rb_oper[i] = 0;
		ta->rra_oper[i] = 0;
		ta->rrb_oper[i] = 0;
		i++;
	}
}

static void				optim_oper(t_a *ta)
{
	while (ft_count_char(ta->ra_oper, 32) > 0
			&& ft_count_char(ta->rb_oper, 32) > 0)
	{
		ft_oper_rec(ta->oper, "rr", 1);
		del_oper(ta->ra_oper);
		del_oper(ta->rb_oper);
	}
	while (ft_count_char(ta->rra_oper, 32) > 0
			&& ft_count_char(ta->rrb_oper, 32) > 0)
	{
		ft_oper_rec(ta->oper, "rrr", 1);
		del_oper(ta->rra_oper);
		del_oper(ta->rrb_oper);
	}
}

void					op_write(t_a *ta, char *s, int i)
{
	ta->op_b += i;
	if (ft_strequ(s, "ra") == 1)
		ft_oper_rec(ta->ra_oper, "ra", i);
	else if (ft_strequ(s, "rb") == 1)
		ft_oper_rec(ta->rb_oper, "rb", i);
	else if (ft_strequ(s, "rra") == 1)
		ft_oper_rec(ta->rra_oper, "rra", i);
	else if (ft_strequ(s, "rrb") == 1)
		ft_oper_rec(ta->rrb_oper, "rrb", i);
	else if (ft_strequ(s, "pa") == 1)
	{
		optim_oper(ta);
		if (ta->rb_oper[0] != '\0')
			ft_oper_rec(ta->oper, ta->rb_oper, 1);
		else if (ta->rrb_oper[0] != '\0')
			ft_oper_rec(ta->oper, ta->rrb_oper, 1);
		if (ta->ra_oper[0] != '\0')
			ft_oper_rec(ta->oper, ta->ra_oper, 1);
		else if (ta->rra_oper[0] != '\0')
			ft_oper_rec(ta->oper, ta->rra_oper, 1);
		ft_oper_rec(ta->oper, "pa", i);
	}
	optim_oper(ta);
}

void					sort_three(t_a *ta, t_ps *ps)
{
	t_st				*st;

	st = ft_stack(ta);
	minmax(ps, ta);
	while (ps->max_a->an != 1 && !sort_a(ta))
	{
		ra(ps, ta, 1);
		minmax(ps, ta);
		st_reboot(st);
	}
	if (st->end_a->a > st->end_a->prev->a)
		sa(ps, ta, 1);
	free(st);
}

t_a						*min_oper(t_ps *ps, t_a *ta)
{
	t_a					*min;
	t_a					*temp;

	temp = ta;
	min = ta;
	while (temp->prev)
		temp = temp->prev;
	if (ps->b_l > 0)
	{
		while (temp->bn > 0 && temp)
		{
			if (min->op_b > temp->op_b && temp->op_b > 0)
				min = temp;
			temp = temp->next;
		}
	}
	return (min);
}
