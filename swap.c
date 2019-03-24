/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:51:18 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:38:23 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_ps *ps, char swap)
{
	int		temp;

	ps->a_len = ft_stacklen(ps->a);
	if (ps->a_len > 1)
	{
		temp = ps->a[a_len - 1];
		ps->a[ps->a_len - 1] = ps->a[ps->a_len - 2];
		ps->a[ps->a_len - 2] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("sa\n");
	}
}

void		sb(t_ps *ps, char swap)
{
	int		temp;

	ps->b_len = ft_stacklen(ps->b);
	if (ps->b_len > 1)
	{
		temp = ps->b[b_len - 1];
		ps->b[ps->b_len - 1] = ps->b[ps->b_len - 2];
		ps->b[ps->b_len - 2] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("sb\n");
	}
}
