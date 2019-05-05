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
	int			num;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	u = temp->a;
	num = temp->num_a;
	while (temp->next && temp->next->an)
	{
		temp->a = temp->next->a;
		temp->num_a = temp->next->num_a;
		temp = temp->next;
	}
	temp->a = u;
	temp->num_a = num;
	if (i == 1)
	{
		ps->len++;
		write(1, "rra\n", 4);
	}
}

void			rrr(t_ps *ps, t_a *ta, int i)
{
	rra(ps, ta, 0);
	rrb(ps, ta, 0);
	if (i == 1)
	{
		write(1, "rrr\n", 4);
		ps->len++;
	}
}

void			rrb(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;
	int			num;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	u = temp->b;
	num = temp->num_b;
	while (temp->next && temp->next->bn)
	{
		temp->b = temp->next->b;
		temp->num_b = temp->next->num_b;
		temp = temp->next;
	}
	temp->b = u;
	temp->num_b = num;
	if (i == 1)
	{
		ps->len++;
		write(1, "rrb\n", 4);
	}
}
