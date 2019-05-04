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
		write(1, "|", 1);
		(temp->a >= 0) ? (write(1, " ", 1)) : 0;
		if (temp->an)
			ft_putnbr(temp->a);
		else
			write(1, " ", 1);
		write(1, "\t\t", 2);
		if (temp->bn)
			ft_putnbr(temp->b);
		else
			write(1, " ", 1);
		if (temp->prev == NULL)
		{
			write(1, "\t\t\t       |", 11);
			ft_putnbr(ps->len);
		}
		else
			write(1, "\t\t\t        ", 11);
		write(1, "|\n", 2);
		temp = temp->prev;
	}
}

void				ft_beauty(t_ps *ps, t_a *ta, int i)
{
	t_a				*temp;

	temp = ta;
	while (temp->next)
		temp = temp->next;
	if (i == 2 || i == 3)
	{
		write(1, "________________________", 24);
		write(1, "_________________________\n", 26);
		ft_data(temp, ps);
		write(1, "|_\t\t_\t\t\t\t|\n|a\t\tb\t\t\t\t|\n|", 23);
		ft_putnbr(ps->a_l);
		write(1, "\t\t", 2);
		ft_putnbr(ps->b_l);
		write(1, "\t\t\t\t|\n|", 7);
		write(1, "________________________", 24);
		write(1, "_______________________|\n", 25);
		if (i == 2)
			system("clear");
	}
}
