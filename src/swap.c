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

	temp = ta;
	if (ps->a_l > 1)
	{
		while (temp->next)
			temp = temp->next;
		n = temp->prev->a;
		temp->prev->a = temp->a;
		temp->a = n;
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

	temp = ta;
	if (ps->a_l > 1)
	{
		while (temp->next)
			temp = temp->next;
		n = temp->prev->b;
		temp->prev->b = temp->b;
		temp->b = n;
	}
	if (i == 1)
	{
		ft_putstr("sb\n");
		ps->len++;
	}
}
