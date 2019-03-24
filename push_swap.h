/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:21:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 17:39:50 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_ps
{
	int				*a;
	int				*b;
	size_t			a_len;
	size_t			b_len;
	size_t			len;
	int				max_a;
	int				min_a;
	int				max_b;
	int				min_b;
}					t_ps;

void				sa(t_ps *ps, char swap);
void				sb(t_ps *ps, char swap);
void				pa(t_ps *ps, char swap);
void				pb(t_ps *ps, char swap);
void				ra(t_ps *ps, char swap);
void				rb(t_ps *ps, char swap);
void				rra(t_ps *ps, char swap);
void				rrb(t_ps *ps, char swap);
void				rrr(t_ps *ps, char swap);
void				rr(t_ps *ps, char swap);
void				ss(t_ps *ps, char swap);

#endif
