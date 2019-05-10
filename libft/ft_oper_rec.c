/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper_rec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 16:33:30 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/04 16:33:32 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_oper(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i + 1] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != 32)
	{
		s[i] = '\0';
		i--;
	}
	if (s[i] != '\0')
		s[i] = '\0';
}

void		ft_operclr(char *s)
{
	int		i;

	i = 0;
	while (i < 7000)
	{
		s[i] = 0;
		i++;
	}
}

void		ft_oper_rec(char *s1, char *s2, int l)
{
	while (l > 0)
	{
		if (s1[0] != '\0')
			ft_strcat(s1, " ");
		ft_strcat(s1, s2);
		l--;
	}
	if (ft_count_char(s2, 32) > 1)
		ft_operclr(s2);
}
