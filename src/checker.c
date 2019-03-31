/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:15:27 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 18:02:30 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int			sorting_by_instruction(char	*line, t_ps *ps)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(ps, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(ps, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(ps, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(ps, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(ps, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(ps, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(ps, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(ps, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(ps, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(ps, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(ps, 0);
	else
		return (0);
	return (1);

}

static int			not_number(char *s)
{
	int				n;

	n = 0;
	while (s[n] != 0)
	{
		if (!ft_isdigit(s[n]))
		{
			ft_putstr("Error");
			return (0);
		}
		n++;
	}
	return (1);
}

int					main(int c, char **s)
{
	t_ps			*ps;
	int				i;
	int				l;
	char			*line;

	i = 1;
	l = 0;
	if (!(ps = ps_list(c - 1)))
		return (0);
	if (c < 3)
		return (0);
	while (s[i] != NULL)
	{
		if (not_number(s[i]) == 0)
			return (0);
		ps->a[l++] = ft_atoi(s[i++]);
	}
	while (get_next_line(0, &line))
		if (sorting_by_instruction(line, ps) == 0)
		{
			ft_putstr("Error");
			return (0);
		}
	if (if_sort(ps->a) == 0)
		ft_putstr("KO");
	else
		ft_putstr("OK");
}
