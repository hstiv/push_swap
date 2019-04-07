/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:00:01 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:20:02 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void         ft_sorter(t_ps *ps, t_a *ta)
{
    t_stack         *st;

    st = ft_stack(ta);
}

int                 main(int c, char **s)
{
    t_ps            *ps;
    t_a             *ta;
    int             i;

    i = 1;
    if (!(ta = ta_list()) || !(ps = ps_list()))
    {
        lst_free(ps, ta);
        ft_putstr("Error\n");
        return (0);
    }
    if (ft_strcmp(s[i] , "-c") == 0)
        i++;
    if (!(ta = recorder(s, ta, ps, i)))
		return (0);
    ft_sorter(pa, ta);
    lst_free(ps, ta);
    if (ft_strcmp(s[1], "-c") == 0)
        ft_putnbr(ps->len);
    return (0);
}
