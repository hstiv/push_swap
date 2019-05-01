/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:29:57 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/01 21:29:59 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_a			*ta_list(void)
{
	t_a		*ta;

	ta = malloc(sizeof(t_a));
	if (ta)
	{
		ta->prev = NULL;
		ta->a = 0;
		ta->b = 0;
		ta->an = 0;
		ta->bn = 0;
		ta->num_a = 0;
		ta->num_b = 0;
		ta->oper = ft_memalloc(7000);
		ta->op_b = 0;
		ta->next = NULL;
	}
	return (ta);
}

void		st_reboot(t_st *st)
{
	while (st->end_a->an == 0)
		st->end_a = st->end_a->prev;
	while (st->end_a->next && st->end_a->next->an != 0)
		st->end_a = st->end_a->next;
}

t_st		*ft_stack(t_a *ta)
{
	t_st	*stack;
	t_a		*temp;

	stack = malloc(sizeof(t_st));
	if (stack)
	{
		temp = ta;
		while (temp->prev)
			temp = temp->prev;
		stack->begin = temp;
		while (temp->next->an)
			temp = temp->next;
		stack->end_a = temp;
		while (temp->prev)
			temp = temp->prev;
		while (temp->next->bn)
			temp = temp->next;
		stack->end_b = temp;
	}
	return (stack);
}

t_ps		*ps_list(void)
{
	t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (ps)
	{
		ps->a_l = 0;
		ps->b_l = 0;
		ps->len = 0;
		ps->max_a = NULL;
		ps->min_a = NULL;
		ps->max_b = NULL;
		ps->min_b = NULL;
	}
	return (ps);
}
