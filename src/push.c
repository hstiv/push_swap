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

void			pa(t_ps *ps, char swap)
{
	if (ps->b_len > 0)
	{
		ps->a[ps->a_len] = ps->b[ps->b_len - 1];
		ps->b[ps->b_len - 1] = 0;
		ps->a_len++;
		ps->b_len--;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("pa\n");
	}
}

void			pb(t_ps *ps, char swap)
{
	if (ps->a_len > 0)
	{
		ps->b[ps->b_len] = ps->a[ps->a_len - 1];
		ps->a[ps->a_len - 1] = 0;
		ps->b_len++;
		ps->a_len--;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("pb\n");
	}
}
