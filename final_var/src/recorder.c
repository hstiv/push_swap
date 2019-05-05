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
	while (s[n] != '\0' && s[n] != '\n')
	{
		if (!ft_isdigit(s[n]))
			return (0);
		n++;
	}
	return (1);
}

t_a					*sub_rec(char **s, t_a *ta, t_ps *ps)
{
	t_a				*tmp;
	int				i;

	tmp = ta;
	i = 0;
	while (s[i] != NULL)
	{
		if (not_number(s[i]) == 0)
		{
			ft_putstr("Error");
			lst_free(ps, ta);
			return (NULL);
		}
		tmp->a = ft_atoi(s[i]);
		tmp->an = (tmp->prev) ? (tmp->prev->an + 1) : (1);
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

t_a					*recorder(char **s, t_a *ta, t_ps *ps, int i)
{
	t_a				*tmp;
	char			**str;

	tmp = ta;
	while (s[i] != NULL)
	{
		str = ft_strsplit(s[i], 32);
		if (!(tmp = sub_rec(str, tmp, ps)))
		{
			ft_arraydel((void **)str);
			return (NULL);
		}
		ft_arraydel((void **)str);
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
