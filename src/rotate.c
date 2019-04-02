/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:48:18 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:02:36 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ra(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;

	if (ps->a_l > 0)
	{
		temp = ta;
		while (temp->next && temp->next->an)
			temp = temp->next;
		u = temp->a;
		while (temp->prev)
		{
			temp->a = temp->prev->a;
			temp = temp->prev;
		}
		temp->a = u;
	}
	if (i == 1)
	{
		ps->len++;
		ft_putstr("rra\n");
	}
}

void			rr(t_ps *ps, t_a *ta, int i)
{
	ra(ps, ta, 0);
	rb(ps, ta, 0);
	if (i == 1)
	{
		ft_putstr("rr\n");
		ps->len++;
	}
}

void			rb(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;

	if (ps->b_l > 1)
	{
		temp = ta;
		while (temp->next && temp->next->bn)
			temp = temp->next;
		u = temp->b;
		while (temp->prev)
		{
			temp->b = temp->prev->b;
			temp = temp->prev;
		}
		temp->b = u;
	}
	if (i == 1)
	{
		ps->len++;
		ft_putstr("rb\n");
	}
}
