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

int			sort_b(t_a *ta)
{
	t_a		*temp;

	temp = ta;
	while (temp->prev)
		temp = temp->prev;
	while (temp->next && temp->bn)
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
	while (temp->next)
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
	while (temp->next)
	{
		if (temp->prev && temp->a > temp->prev->a)
			return (0);
		temp = temp->next;
	}
	return (1);
}
