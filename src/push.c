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
	if (ps->b_l > 0)
	{
		ps->a[ps->a_l] = ps->b[ps->b_l - 1];
		ps->b[ps->b_l - 1] = 0;
		ps->a_l++;
		ps->b_l--;
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
	if (ps->a_l > 0)
	{
		ps->b[ps->b_l] = ps->a[ps->a_l - 1];
		ps->a[ps->a_l - 1] = 0;
		ps->b_l++;
		ps->a_l--;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("pb\n");
	}
}
