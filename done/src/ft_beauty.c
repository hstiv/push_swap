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
		write(1, "\t\t\t", 3);
		if (temp->bn)
			ft_putnbr(temp->b);
		else
			write(1, " ", 1);
		if (temp->prev == NULL)
		{
			write(1, "\t       |", 9);
			ft_putnbr(ps->len);
		}
		else
			write(1, "\t        ", 9);
		write(1, "|\n", 2);
		temp = temp->prev;
	}
}

void				ft_beauty(t_ps *ps, t_a *ta)
{
	t_a				*temp;

	temp = ta;
	while (temp->next)
		temp = temp->next;
	if (ps->v != 0)
	{
		(ps->c == 1) ? blue() : 0;
		write(1, "____________________", 20);
		write(1, "_____________________\n", 22);
		ft_data(temp, ps);
		write(1, "|_\t\t\t_\t\t|\n|a\t\t\tb\t\t|\n|", 21);
		ft_putnbr(ps->a_l);
		write(1, "\t\t\t", 3);
		ft_putnbr(ps->b_l);
		write(1, "\t\t|\n|", 5);
		write(1, "____________________", 20);
		write(1, "___________________|\n", 21);
		if (ps->s != 0 && !if_sort(ta))
		{
			usleep((ps->a_l + ps->b_l <= 100) ? 99999 : 99999);
			system("clear");
		}
	}
}
