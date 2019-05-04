/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:20:17 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 19:20:19 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_all(t_a *ta)
{
	t_a		*tmp1;
	t_a		*tmp2;

	tmp1 = ta;
	while (tmp1)
	{
		tmp2 = ta;
		while (tmp2)
		{
			if ((tmp2->a == tmp1->a && tmp1->an != tmp2->an) || (long)tmp2->a >= 2147483649)
			{
				ft_putstr("Error\n");
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int			sort_b(t_a *ta)
{
	t_a		*temp;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	while (temp && temp->bn)
	{
		if (temp->prev && temp->bn && temp->b < temp->prev->b)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			sort_a(t_a *ta)
{
	t_a		*temp;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	while (temp)
	{
		if (temp->prev && temp->a > temp->prev->a)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			if_sort(t_a *ta)
{
	t_a		*temp;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	if (temp->bn != 0)
		return (0);
	while (temp)
	{
		if (temp->prev && temp->a > temp->prev->a)
			return (0);
		temp = temp->next;
	}
	return (1);
}
