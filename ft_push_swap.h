/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:21:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:26:08 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_ps
{
	int			*a;
	int			*b;
	size_t		a_len;
	size_t		b_len;
	size_t		len;
}				t_ps;

void				sa(p_ps *ps, char swap);
void				sb(p_ps *ps, char swap);
void				pa(p_ps *ps, char swap);
void				pb(p_ps *ps, char swap);
void				ra(p_ps *ps, char swap);
void				rb(p_ps *ps, char swap);
void				rra(p_ps *ps, char swap);
void				rrb(p_ps *ps, char swap);

#endif
