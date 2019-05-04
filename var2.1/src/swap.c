/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:51:18 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 16:37:26 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_ps *ps, t_a *ta, int i)
{
	t_a		*temp;
	int		n;
	int		num;

	temp = ta;
	if (ps->a_l > 1)
	{
		while (temp->next && temp->next->an)
			temp = temp->next;
		n = temp->prev->a;
		num = temp->prev->num_a;
		temp->prev->a = temp->a;
		temp->prev->num_a = temp->num_a;
		temp->a = n;
		temp->num_a = num;
	}
	if (i == 1)
	{
		ft_putstr("sa\n");
		ps->len++;
	}
}

void		ss(t_ps *ps, t_a *ta, int i)
{
	sa(ps, ta, 0);
	sb(ps, ta, 0);
	if (i == 0)
	{
		ps->len++;
		ft_putstr("ss\n");
	}
}

void		sb(t_ps *ps, t_a *ta, int i)
{
	t_a		*temp;
	int		n;
	int		num;

	temp = ta;
	if (ps->b_l > 1)
	{
		while (temp->next && temp->next->bn)
			temp = temp->next;
		n = temp->prev->b;
		num = temp->prev->num_b;
		temp->prev->b = temp->b;
		temp->prev->num_b = temp->num_b;
		temp->num_b = num;
		temp->b = n;
	}
	if (i == 1)
	{
		ft_putstr("sb\n");
		ps->len++;
	}
}
