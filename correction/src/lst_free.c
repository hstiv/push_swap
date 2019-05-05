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

static void			oper_freeder(t_a *ta)
{
	free(ta->oper);
	free(ta->ra_oper);
	free(ta->rb_oper);
	free(ta->rra_oper);
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
