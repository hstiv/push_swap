/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:21:20 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/31 17:46:26 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 20

typedef struct		s_ps
{
	int				*a;
	int				*b;
	int				a_l;
	int				b_l;
	int				len;
	int				max_a;
	int				min_a;
	int				max_b;
	int				min_b;
	float			flotx;
	float			flotn;
}					t_ps;

int					if_sort(int *a);
void				ft_beauty(t_ps *ps);
int					get_next_line(const int fd, char **line);
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
void				find_mm_a(t_ps *ps);
void				find_mm_b(t_ps *ps);
t_ps				*ps_list(int c);

#endif
