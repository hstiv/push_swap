/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:59:12 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/04 14:59:14 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_dellast(t_a *ta)
{
	t_a				*tmp;
	t_a				*la;

	tmp = ta;
	while (tmp && tmp->an != 0)
		tmp = tmp->next;
	la = (tmp && tmp->prev) ? tmp->prev : NULL;
	if (tmp)
	{
		free(tmp->oper);
		free(tmp->ra_oper);
		free(tmp->rb_oper);
		free(tmp->rra_oper);
		free(tmp->rrb_oper);
		free(tmp);
	}
	if (la)
		la->next = NULL;
}

static void			oper_freeder(t_a *ta)
{
	if (ta->oper)
		free(ta->oper);
	if (ta->ra_oper)
		free(ta->ra_oper);
	if (ta->rb_oper)
		free(ta->rb_oper);
	if (ta->rb_oper)
		free(ta->rra_oper);
	if (ta->rrb_oper)
		free(ta->rrb_oper);
}

void				lst_free(t_ps *ps, t_a *ta)
{
	while (ta && ta->prev)
		ta = ta->prev;
	while (ta && ta->next)
	{
		ta = ta->next;
		if (ta->prev)
		{
			oper_freeder(ta->prev);
			free(ta->prev);
		}
	}
	if (ta)
	{
		if (ta->oper)
			oper_freeder(ta);
		free(ta);
	}
	if (ps)
		free(ps);
}
