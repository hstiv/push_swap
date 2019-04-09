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

void			ra(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	int			u;
	int			nb;

	if (ps->a_l > 0)
	{
		temp = ta;
		while (temp->next && temp->next->an)
			temp = temp->next;
		u = temp->a;
		nb = temp->an;
		while (temp->prev)
		{
			temp->a = temp->prev->a;
			temp->an = temp->prev->an;
			temp = temp->prev;
		}
		temp->a = u;
		temp->an = nb;
	}
	if (i == 1)
	{
		ps->len++;
		ft_putstr("ra\n");
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
	int			nb;

	if (ps->b_l > 0)
	{
		temp = ta;
		while (temp->next && temp->next->bn)
			temp = temp->next;
		u = temp->b;
		nb = temp->bn;
		while (temp->prev)
		{
			temp->b = temp->prev->b;
			temp->bn = temp->prev->bn;
			temp = temp->prev;
		}
		temp->b = u;
		temp->bn = nb;
	}
	if (i == 1)
	{
		ps->len++;
		ft_putstr("rb\n");
	}
}
