/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_beauty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:21:16 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 19:21:28 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_beauty(t_ps *ps)
{
	int				i;
	int				l;

	i = ps->a_l;
	l = ps->b_l;
	while (ps->a[i] || ps->b[l])
	{
		if (ps->a[i])
			ft_putnbr(ps->a[i]);
		else
			ft_putchar(' ');
		ft_putchar('\t');
		if (ps->b[l])
			ft_putnbr(ps->b[l]);
		else
			ft_putchar(' ');		
		ft_putchar('\n');
		i--;
		l--;
	}
	ft_putstr("__________________________________________________________________\n");
}
