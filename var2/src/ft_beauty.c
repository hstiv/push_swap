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

static void			ft_data(t_a *temp, t_ps *ps)
{
	while (temp != NULL)
	{
		ft_putchar('|');
		(temp->a >= 0) ? (ft_putchar(' ')) : 0;
		if (temp->an)
		{
			ft_putnbr(temp->a);
	//		ft_putchar('-');
	//		ft_putnbr(temp->an);
		}
		else
			ft_putchar(' ');
		ft_putstr("\t\t");
		if (temp->bn)
		{
			ft_putnbr(temp->b);
	//		ft_putchar('-');
	//		ft_putnbr(temp->bn);
		}
		else
			ft_putchar(' ');
		if (temp->prev == NULL)
		{
			ft_putstr("\t\t\t       |");
			ft_putnbr(ps->len);
		}
		else
			ft_putstr("\t\t\t        ");
		ft_putstr("|\n");
		temp = temp->prev;
	}
}

void				ft_beauty(t_ps *ps, t_a *ta, int i)
{
	t_a				*temp;

	temp = ta;
	while (temp->next)
		temp = temp->next;
	if (i == 2)
	{
		ft_putstr("________________________");
		ft_putstr("_________________________\n");
		ft_data(temp, ps);
		ft_putstr("|_\t\t_\t\t\t\t|\n|a\t\tb\t\t\t\t|\n|");
		ft_putnbr(ps->a_l);
		ft_putstr("\t\t");
		ft_putnbr(ps->b_l);
		ft_putstr("\t\t\t\t|\n|");
		ft_putstr("________________________");
		ft_putstr("_______________________|\n");
	}
}
