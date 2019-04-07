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
    if (!(ta = recorder(s, ta, ps, i)))
		return (0);
    lst_free(ps, ta);
    return (0);
}
