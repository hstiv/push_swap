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

void			ra(t_ps *ps, char swap)
{
	int			temp;
	int			i;

	if (ps->a_l <= 1)
	{	
		i = ps->a_l;
		temp = ps->a[ps->a_l - 1];
		while (--i && i > 0)
			ps->a[i] = ps->a[i - 1];
		ps->a[i] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("ra\n");
	}
}

void			rr(t_ps *ps, char swap)
{
	ra(ps, swap);
	rb(ps, swap);
}

void			rb(t_ps *ps, char swap)
{
	int			temp;
	int			i;

	if (ps->b_l <= 1)
	{	
		i = ps->b_l;
		temp = ps->b[ps->b_l - 1];
		while (--i && i > 0)
			ps->b[i] = ps->b[i - 1];
		ps->b[i] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("rb\n");
	}
}
