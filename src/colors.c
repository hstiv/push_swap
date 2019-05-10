/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:12:49 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/08 16:12:51 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		red(void)
{
	write(1, "\033[1;31m", 7);
}

void		green(void)
{
	write(1, "\033[0;32m", 7);
}

void		blue(void)
{
	write(1, "\033[0;34m", 7);
}

void		reset(void)
{
	write(1, "\033[0m", 5);
}

int			flag_check(int *i, t_ps *ps, int l)
{
	if (ps->i + 1 != l)
		return (werror(ps));
	if (ps->v > 1 || ps->c > 1 || ps->s > 1)
		return (werror(ps));
	if (ps->i > 0)
		(*i)++;
	return (1);
}
