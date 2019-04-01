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
		ta->a = 0;
		ta->b = 0;
		ta->n = 0;
		ta->next = 0;
	}
	return (ta);
}

t_ps        *ps_list(char *s)
{
    t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (ps)
	{
		ps->a_l = 0;
		ps->b_l = 0;
		ps->len = 0;
		ps->max_a = 0;
		ps->min_a = 0;
		ps->max_b = 0;
		ps->min_b = 0;
		ps->flotx = 0;
		ps->flotn = 0;
	}
	return (ps);
}
