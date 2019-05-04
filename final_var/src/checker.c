/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:15:27 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/07 13:28:21 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

static int				visual(t_ps *ps, t_a *ta, int i)
{
	char				*line;

	ft_beauty(ps, ta, i);
	while (get_next_line(0, &line) > 0)
	{
		if (sort_by_in(line, ps, ta) == 0)
		{
			ft_putstr("Error\n");
			lst_free(ps, ta);
			return (0);
		}
		ps->len++;
		ft_beauty(ps, ta, i);
	}
	free(line);
	return (1);
}

int						main(int c, char **s)
{
	t_ps				*ps;
	t_a					*ta;
	int					i;

	i = 1;
	ps = ps_list();
	if (!ps || !(ta = ta_list()) || c < 2)
		return (0);
	if (ft_strcmp(s[i], "-v") == 0)
		i++;
	if (!(ta = recorder(s, ta, ps, i)))
		return (0);
	numgive(ps, ta);
	if (!(visual(ps, ta, i)) || !check_all(ta))
		return (0);
	if (if_sort(ta) == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	lst_free(ps, ta);
	return (0);
}
