/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   werror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:23:19 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/09 17:23:20 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			werror(t_ps *ps)
{
	(ps->c == 1) ? red() : 0;
	write(1, "Error\n", 6);
	reset();
	return (0);
}