/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:15:27 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/01 14:28:38 by hstiv            ###   ########.fr       */
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
	while (s[n] != '\0' && s[n] != '\n')
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
	int				l;
	int				i;
	int				j;
	char			num[99999];
	char			*line;

	i = 0;
	l = 0;
	j = 0;
	if (!(ps = ps_list(s[1])))
		return (0);
	if (c == 1)
		return (0);
	while (s[1][i] != '\0' && l <= ps->a_l)
	{
		ft_strclr(num);
		j = 0;
		while (s[1][i] != ' ' && s[1][i] != '\0')
			num[j++] = s[1][i++];
		while (s[1][i] <= 32 && s[1][i] != '\0')
			i++;
		num[j] = '\0';
		if (not_number(num) == 0)
			return (0);
		ps->a[l] = ft_atoi(num);
		l++;
	}
	ft_beauty(ps);
	while (get_next_line(0, &line) > 0)
	{
		if (sorting_by_instruction(line, ps) == 0)
		{
			ft_putstr("Error");
			return (0);
		}
		ft_beauty(ps);
	}
	if (if_sort(ps->a) == 0)
		ft_putstr("KO");
	else
		ft_putstr("OK");
	return (0);
}
