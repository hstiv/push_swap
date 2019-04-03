/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:24:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 17:14:11 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			pa(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	t_a			*temp_b;
	int			n;

	if (ps->b_l > 0)
	{
		temp = ta;
		temp_b = ta;
		while (temp->next && temp->next->bn != 0)
			temp = temp->next;
		n = temp->b;
		temp->b = 0;
		temp->bn = 0;
		while (temp_b->next && temp_b->next->an != 0)
			temp_b = temp_b->next;
		temp_b->a = n;
		if (temp_b->prev)
			temp_b->an = temp_b->prev->an + 1;
		else
			temp_b->an = 1;		
		ps->a_l++;
		ps->b_l--;
	}
	if (i == 1)
	{
		ft_putstr("pa\n");
		ps->len++;
	}
}

void			pb(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	t_a			*temp_b;
	int			n;

	if (ps->a_l > 0)
	{
		temp = ta;
		temp_b = ta;
		while (temp->next && temp->next->an != 0)
			temp = temp->next;
		n = temp->a;
		temp->a = 0;
		temp->an = 0;
		while (temp_b->next && temp_b->next->bn != 0)
			temp_b = temp_b->next;
		temp_b->b = n;
		if (temp_b->prev)
			temp_b->bn = temp_b->prev->bn + 1;
		else
			temp_b->bn = 1;
		ps->a_l--;
		ps->b_l++;
	}
	if (i == 1)
	{
		ft_putstr("pb\n");
		ps->len++;
	}
}
