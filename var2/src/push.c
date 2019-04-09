/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:24:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/07 13:22:10 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		pa_maker(t_ps *ps, t_a *temp, t_a *temp_b)
{
	int			n;
	int			nb;

	while (temp->next && temp->next->bn != 0)
		temp = temp->next;
	n = temp->b;
	nb = temp->bn;
	temp->b = 0;
	temp->bn = 0;
	while (temp_b->next && temp_b->an != 0)
		temp_b = temp_b->next;
	temp_b->a = n;
	temp_b->an = nb;
	ps->a_l++;
	ps->b_l--;
}

void			pa(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	t_a			*temp_b;

	temp = ta;
	temp_b = ta;
	if (ps->b_l > 0)
		pa_maker(ps, temp, temp_b);
	if (i == 1)
	{
		ft_putstr("pa\n");
		ps->len++;
	}
}

static void		pb_maker(t_ps *ps, t_a *temp, t_a *temp_b)
{
	int			n;
	int			nb;

	while (temp->next && temp->next->an != 0)
		temp = temp->next;
	n = temp->a;
	nb = temp->an;
	temp->a = 0;
	temp->an = 0;
	while (temp_b->next && temp_b->bn != 0)
		temp_b = temp_b->next;
	temp_b->b = n;
	temp_b->bn = nb;
	ps->a_l--;
	ps->b_l++;
}

void			pb(t_ps *ps, t_a *ta, int i)
{
	t_a			*temp;
	t_a			*temp_b;

	temp = ta;
	temp_b = ta;
	if (ps->a_l > 0)
		pb_maker(ps, temp, temp_b);
	if (i == 1)
	{
		ft_putstr("pb\n");
		ps->len++;
	}
}
