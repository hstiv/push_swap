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
	t_a				*temp;

	temp = ta;
	while (temp->next)
		temp = temp->next;
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	while (temp != NULL && (temp->an || temp->bn))
	{
		if (temp->an)
			ft_putnbr(temp->a);
		else
			ft_putchar(' ');
		ft_putstr("\t\t");
		if (temp->bn)
			ft_putnbr(temp->b);
		else
			ft_putchar(' ');
		ft_putchar('\n');
		temp = temp->prev;
	}
	ft_putstr("-\t\t-\na\t\tb\n");
	ft_putnbr(ps->a_l);
	ft_putstr("\t\t");
	ft_putnbr(ps->b_l);
	ft_putchar('\n');
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
	ft_putstr("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
}
