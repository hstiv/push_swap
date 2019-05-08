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

static int				visual(t_ps *ps, t_a *ta)
{
	char				*line;

	if (!ps->a_l)
		return (0);
	ft_beauty(ps, ta);
	while (get_next_line(0, &line) > 0)
	{
		if (sort_by_in(line, ps, ta) == 0)
		{
			(ps->c == 1) ? red() : 0;
			ft_putstr("Error\n");
			(line) ? free(line) : 0;
			return (0);
		}
		if (line && *line)
			free(line);
		ps->len++;
		ft_beauty(ps, ta);
	}
	(ps->i == 2) ? ft_beauty(ps, ta) : 0;
	return (1);
}

static int				flags(t_ps *ps, char **s, int *i)
{
	int					l;

	l = 0;
	if (s[1] != NULL && s[1][l] == '-')
		while (s[1][++l] != '\0')
		{
			if (s[1][l] == 'v')
			{
				ps->v++;
				ps->i++;
			}
			else if (s[1][l] == 's')
			{
				ps->s++;
				ps->i++;
			}
			else if (s[1][l] == 'c')
			{
				ps->i++;
				ps->c++;
			}
		}
	if (s[1][0] == '-' && !flag_check(i, ps, l))
		return (0);
	return (1);
}

static void				p_ko(t_ps *ps, t_a *ta)
{
	if (if_sort(ta) == 0)
	{
		reset();
		(ps->c == 1) ? red() : 0;
		ft_putstr("KO\n");
	}
	else
	{
		reset();
		(ps->c == 1) ? green() : 0;
		ft_putstr("OK\n");
	}
}

int						main(int c, char **s)
{
	t_ps				*ps;
	t_a					*ta;
	int					i;

	i = 1;
	if (c < 2 || (c == 2 && s[1][0] == '-' &&
		!ft_isdigit(s[1][1])) || !(ps = ps_list()))
		return (0);
	if (!(ta = ta_list()) || !flags(ps, s, &i))
	{
		lst_free(ps, ta);
		return (0);
	}
	if (!(ta = recorder(s, ta, ps, i)) || !check_all(ta)
					|| !(visual(ps, ta)))
	{
		lst_free(ps, ta);
		return (0);
	}
	numgive(ps, ta);
	p_ko(ps, ta);
	lst_free(ps, ta);
	return (0);
}
