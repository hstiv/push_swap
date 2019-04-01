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

void				ft_beauty(t_ps *ps, t_a *ta)
{
	int				i;
	int				l;
	t_a				*tmp;

	tmp = ta;
	i = ps->a_l;
	l = ps->b_l;
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	while (i > 0 || l > 0 )
	{
		if (i > 0)
			ft_putnbr(tmp->a);
		else
			ft_putchar(' ');
		ft_putstr("\t\t");
		if (l > 0)
			ft_putnbr(tmp->b);
		else
			ft_putchar(' ');
		ft_putchar('\n');
		i--;
		l--;
		tmp = tmp->next;
	}
	ft_putstr("-\t\t-\n");
	ft_putstr("a\t\tb\n");
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
}
