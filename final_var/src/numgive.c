/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numgive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:29:31 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/04 16:29:32 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				numgive(t_ps *ps, t_a *ta)
{
	int				i;
	int				a;
	t_a				*tmp;

	while (ta->prev)
		ta = ta->prev;
	a = 2;
	minmax(ps, ta);
	i = ps->min_a->a + 1;
	ps->min_a->num_a = 1;
	while (i <= ps->max_a->a)
	{
		tmp = ta;
		while (tmp)
		{
			if (tmp->a == i)
			{
				tmp->num_a = a;
				a++;
			}
			tmp = tmp->next;
		}
		i++;
	}
}