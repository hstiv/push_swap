/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:48:18 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/07 13:20:04 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		condition(t_ps *ps, int i)
{
	ps->len++;
	if (i == 1)
		write(1, "ra\n", 3);
	if (i == 2)
		write(1, "rb\n", 3);
}

void			ra(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			num;
	int			u;

	if (ps->a_l > 0)
	{
		temp = ta;
		while (temp->next && temp->next->an)
			temp = temp->next;
		u = temp->a;
		num = temp->num_a;
		while (temp->prev)
		{
			temp->a = temp->prev->a;
			temp->num_a = temp->prev->num_a;
			temp = temp->prev;
		}
		temp->a = u;
		temp->num_a = num;
	}
	if (i == 1)
		condition(ps, 1);
}

void			rr(t_ps *ps, t_a *ta, int i)
{
	ra(ps, ta, 0);
	rb(ps, ta, 0);
	if (i == 1)
	{
		write(1, "rr\n", 3);
		ps->len++;
	}
}

void			rb(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;
	int			num;

	if (ps->b_l > 0)
	{
		temp = ta;
		while (temp->next && temp->next->bn)
			temp = temp->next;
		u = temp->b;
		num = temp->num_b;
		while (temp->prev)
		{
			temp->b = temp->prev->b;
			temp->num_b = temp->prev->num_b;
			temp = temp->prev;
		}
		temp->b = u;
		temp->num_b = num;
	}
	if (i == 1)
		condition(ps, 2);
}
