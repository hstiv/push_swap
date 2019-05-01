/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:02:57 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/07 13:05:54 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rra(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	u = temp->a;
	while (temp->next && temp->next->an)
	{
		temp->a = temp->next->a;
		temp = temp->next;
	}
	temp->a = u;
	if (i == 1)
	{
		ps->len++;
		ft_putstr("rra\n");
	}
}

void			rrr(t_ps *ps, t_a *ta, int i)
{
	rra(ps, ta, 0);
	rrb(ps, ta, 0);
	if (i == 1)
	{
		ft_putstr("rrr\n");
		ps->len++;
	}
}

void			rrb(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	u = temp->b;
	while (temp->next && temp->next->bn)
	{
		temp->b = temp->next->b;
		temp = temp->next;
	}
	temp->b = u;
	if (i == 1)
	{
		ps->len++;
		ft_putstr("rrb\n");
	}
}
