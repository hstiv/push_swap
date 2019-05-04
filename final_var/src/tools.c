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
		i++;
	}
}

void					op_write(t_a *ta, char *s, int i)
{
	int					l;

	l = i;
	ta->op_b += i;
	while (l > 0)
	{
		if (ta->oper[0] != '\0')
			ft_strcat(ta->oper, " ");
		ft_strcat(ta->oper, s);
		l--;
	}
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
