/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:00:01 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:20:02 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int				sort_by_in(char *line, t_ps *ps, t_a *ta)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(ps, ta, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(ps, ta, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(ps, ta, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(ps, ta, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(ps, ta, 0);
	else if (ft_strequ(line, "ra") == 1)
		ra(ps, ta, 0);
	else if (ft_strequ(line, "rr") == 1 && (ft_strlen("rr") == ft_strlen(line)))
		rr(ps, ta, 0);
	else if (ft_strequ(line, "rra") == 1)
		rra(ps, ta, 0);
	else if (ft_strequ(line, "rrb") == 1)
		rrb(ps, ta, 0);
	else if (ft_strequ(line, "rrr") == 1)
		rrr(ps, ta, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(ps, ta, 0);
	else
		return (0);
	return (1);
}

static t_a				*min_oper(t_ps *ps, t_a *ta)
{
	t_a					*min;
	t_a					*temp;

	temp = ta;
	min = ta;
	if (ps->b_l > 0)
	{
		while (temp && temp->next->bn)
		{
			if (min->op_b > temp->op_b)
				min = temp;
			temp = temp->next;
		}
	}
	return (min);
}

static void			algo(t_ps *ps, t_a *ta)
{
	t_a				*tmp;
	t_a				*min;
	char			**s;
	int				i;

	i = 0;
	tmp = ta;
	operations(tmp, ps);
	min = min_oper(ps, tmp);
	s = ft_strsplit(min->oper, ' ');
	while (s[i] != NULL)
	{
		sort_by_in(s[i], ps, ta);
		i++;
	}
	ft_arraydel((void **)s);
}

static void			ft_sorter(t_ps *ps, t_a *ta)
{

	minmax(ps, ta);
	if (!if_sort(ta))
	{
		while (ps->a_l > 3)
			pb(ps, ta, 1);
		while (!sort_a(ta))
			rra(ps, ta, 1);
		while (ps->b_l > 0)
			algo(ps, ta);
		if (!sort_a(ta))
		{
			while (!sort_a(ta))
				ra(ps, ta, 1);
		}
	}
}

int					main(int c, char **s)
{
	t_ps			*ps;
	t_a				*ta;
	int				i;

	i = 1;
	if (!(ta = ta_list()))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(ps = ps_list()) || c < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(ta = recorder(s, ta, ps, i)))
		return (0);
	numgive(ps, ta);
	ft_sorter(ps, ta);
	lst_free(ps, ta);
	return (0);
}
