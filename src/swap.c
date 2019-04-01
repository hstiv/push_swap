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

void		sa(t_ps *ps, t_a *ta)
{
	int		temp;

	if (ps->a_l > 1)
	{
		temp = ps->a[ps->a_l - 1];
		ps->a[ps->a_l - 1] = ps->a[ps->a_l - 2];
		ps->a[ps->a_l - 2] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("sa\n");
	}
}

void		ss(t_ps *ps, t_a *ta)
{
	sa(ps, swap);
	sb(ps, swap);
}

void		sb(t_ps *ps, char swap)
{
	int		temp;

	ps->b_l = ft_stacklen(ps->b);
	if (ps->b_l> 1)
	{
		temp = ps->b[ps->b_l - 1];
		ps->b[ps->b_l - 1] = ps->b[ps->b_l - 2];
		ps->b[ps->b_l - 2] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("sb\n");
	}
}
