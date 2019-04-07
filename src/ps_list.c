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

t_a			*ta_list()
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
		ta->next = NULL;
	}
	return (ta);
}

t_stack		*ft_stack(t_a *ta)
{
	t_stack *stack;
	t_a		*temp;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		temp = ta;
		while (temp->prev)
			temp = temp->prev;
		stack->begin = temp;
		while (temp->next)
			temp = temp->next;
		stack->end = temp;
	}
	return (stack);
}

t_ps        *ps_list()
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
