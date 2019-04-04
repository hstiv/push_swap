/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:59:12 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/04 14:59:14 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				lst_free(t_ps *ps, t_a *ta)
{
	while (ta->prev)
		ta = ta->prev;
	while (ta->next)
	{
		ta = ta->next;
		if (ta->prev)
			free(ta->prev);
	}
	free(ta);
	free(ps);
}
