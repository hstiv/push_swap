/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:48:02 by hstiv             #+#    #+#             */
/*   Updated: 2019/05/09 13:48:04 by hstiv            ###   ########.fr       */
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

static int			after(int nb, char *s)
{
	char			*str;

	str = ft_itoa(nb);
	if (ft_strcmp(str, s))
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}

static int			check_str(char **str, t_ps *ps)
{
	int				i;

	i = 0;
	while (str[i] != NULL)
	{
		if (!not_number(str[i]) || !smax(str[i]) ||
						!after(atoi(str[i]), str[i]))
			return (werror(ps));
		if (ft_strcmp(str[i], "0") && ft_atoi(str[i]) == 0)
			return (werror(ps));
		if (ft_strcmp(str[i], "-1") && ft_atoi(str[i]) == -1)
			return (werror(ps));
		i++;
	}
	return (1);
}

int					val_arg(char **s, int i, t_ps *ps)
{
	char			**str;

	while (s[i] != NULL)
	{
		str = ft_strsplit(s[i], 32);
		if (!(check_str(str, ps)))
		{
			ft_arraydel((void **)str);
			return (0);
		}
		ft_arraydel((void **)str);
		i++;
	}
	return (1);
}
