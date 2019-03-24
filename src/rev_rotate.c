/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:02:57 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:13:18 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			rra(t_ps *ps, char swap)
{
	int			i;
	int			temp;

	if (ps->a_len > 1)
	{
		i = 0;
		temp = ps->a[i];
		while (i < (ps->a_len - 1))
		{
			ps->a[i] = ps->a[i + 1];
			i++;
		}
		ps->a[ps->a_len - 1] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("rra\n");
	}
}

void			rrb(t_ps *ps, char swap)
{
	int			i;
	int			temp;

	if (ps->b_len > 1)
	{
		i = 0;
		temp = ps->b[i];
		while (i < (ps->b_len - 1))
		{
			ps->b[i] = ps->b[i + 1];
			i++;
		}
		ps->b[ps->b_len - 1] = temp;
	}
	if (swap)
	{
		ps->len++;
		if (swap == 1)
			ft_putstr("rrb\n");
	}
}
