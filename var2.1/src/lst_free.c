/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:59:12 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/04 14:59:14 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					not_number(char *s)
{
	int				n;

	n = 0;
	if (s[n] == '-')
		n++;
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

t_a					*recorder(char **s, t_a *ta, t_ps *ps, int i)
{
	t_a				*tmp;

	tmp = ta;
	while (s[i] != NULL)
	{
		if (not_number(s[i]) == 0 || s[i] )
		{
			ft_putstr("Error");
			lst_free(ps, ta);
			return (NULL);
		}
		tmp->a = ft_atoi(s[i]);
		if (tmp->prev)
			tmp->an = tmp->prev->an + 1;
		else
			tmp->an = 1;
		ps->a_l++;
		if (tmp->next == NULL && s[i + 1] != NULL && s[i] != NULL)
		{
			tmp->next = ta_list();
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	return (ta);
}

void				lst_free(t_ps *ps, t_a *ta)
{
	while (ta && ta->prev)
		ta = ta->prev;
	while (ta && ta->next)
	{
		ta = ta->next;
		if (ta->prev)
		{
			free(ta->prev->oper);
			free(ta->prev);
		}
	}
	if (ta)
	{
		free(ta->oper);
		free(ta);
	}
	if (ps)
		free(ps);
}
