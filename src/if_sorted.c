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

int			if_sort(t_a *ta)
{
	t_a		*temp;

	temp = ta;
	while (temp->next)
	{
		if (temp->prev && temp->a < temp->prev->a)
			return (0);
		temp = temp->next;
	}
	return (1);
}
