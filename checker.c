/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:49:54 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:50:40 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				(char **s)
{
	t_ps		*ps;
	int			i;

	i = 1;
	ps = ps_list();
	while (s[i] != NULL)
	{
		if (ft_strisdig(s[i]) == 0)
			return (-1);
		ps->a[ps->a_len] = ft_atoi(s[i]);
		ps->a_len++;
		i++;
	}
	find_mm_a(ps);
	where_close_to(ps);
}

int				main(int c, char **s)
{
	int			i;

	i = -1;
	if (c > 1)
		i = checker(s);
	if (i == -1)
		ft_putstr("Error\n");
	else if (i == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");	
}