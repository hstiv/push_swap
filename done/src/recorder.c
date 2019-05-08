/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:47:42 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/04 17:47:44 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					not_number(char *s)
{
	int				n;

	n = 0;
	if (s[n] == '-')
		n++;
	while (s[n] != '\0' && s[n] != ' ')
	{
		if (!ft_isdigit(s[n]))
			return (0);
		n++;
	}
	return (1);
}

static int			smax(char *s)
{
	if (!ft_strcmp(s, "2147483648") || !ft_strcmp(s, "-2147483649") ||
			ft_strchr(s, ',') || ft_strchr(s, '.'))
		return (0);
	return (1);
}

static int			mass_len(char **s)
{
	int				i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

t_a					*sub_rec(char **s, t_a *ta, t_ps *ps)
{
	t_a				*tmp;
	int				i;

	tmp = ta;
	i = mass_len(s);
	while (i--)
	{
		if (!not_number(s[i]) || !smax(s[i]))
		{
			ft_putstr("Error\n");
			return (NULL);
		}
		tmp->a = ft_atoi(s[i]);
		tmp->an = (tmp->prev) ? (tmp->prev->an + 1) : (1);
		ps->a_l++;
		if (tmp->next == NULL && i > 0)
		{
			tmp->next = ta_list();
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
	}
	return (ta);
}

t_a					*recorder(char **s, t_a *ta, t_ps *ps, int i)
{
	t_a				*tmp;
	char			**str;
	int				a;

	tmp = ta;
	a = i;
	i = mass_len(s);
	while (i-- > a)
	{
		str = ft_strsplit(s[i], 32);
		if (!(tmp = sub_rec(str, tmp, ps)))
		{
			ft_dellast(ta);
			ft_arraydel((void **)str);
			return (NULL);
		}
		ft_arraydel((void **)str);
		if (tmp->next == NULL && i >= a)
			next_lst(tmp);
		tmp = tmp->next;
	}
	ft_dellast(ta);
	ft_putchar(66);
	return (ta);
}
