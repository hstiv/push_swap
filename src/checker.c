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

static int			sort_by_in(char	*line, t_ps *ps, t_a *ta)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(ps, ta, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(ps, ta, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(ps, ta, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(ps, ta, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(ps, ta, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(ps, ta, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(ps, ta, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(ps, ta, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(ps, ta, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(ps, ta, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(ps, ta, 0);
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

static t_a			*recorder(char *s, t_a *ta, t_ps *ps)
{
	char			num[11];
	int				i;
	int				j;
	t_a				*tmp;

	i = 0;
	j = 0;
	tmp = ta;
	while (s[i] != '\0')
	{
		if (!tmp)
			tmp = ta_list();
		ft_strclr(num);
		j = 0;
		while (s[i] != ' ' && s[i] != '\0')
			num[j++] = s[i++];
		while (s[i] <= ' ' && s[i] != '\0')
			i++;
		num[j] = '\0';
		if (not_number(num) == 0)
			return (0);
		tmp->a = ft_atoi(num);
		ps->a_l++;
		tmp->an = ps->a_l;
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return (ta);
}

int					main(int c, char **s)
{
	t_ps			*ps;
	t_a				*ta;
	char			*line;

	if (!(ps = ps_list()) || !(ta = ta_list()))
		return (0);
	if (c < 2)
		return (0);
	ta = recorder(s[1], ta, ps);
	ft_beauty(ps, ta);
	while (get_next_line(0, &line) > 0)
	{
		if (sort_by_in(line, ps, ta) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_beauty(ps, ta);
	}
	if (if_sort(ta) == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (0);
}
