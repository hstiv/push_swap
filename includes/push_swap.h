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

typedef struct		s_a
{
	int				a;
	int				an;
	int				bn;
	int				b;
	struct s_a		*next;
	struct s_a		*prev;
}					t_a;

typedef	struct		s_stack
{
	t_a				*begin;
	t_a				*end;
}					t_stack;

typedef struct		s_ps
{
	int				a_l;
	int				b_l;
	int				len;
	t_a				*max_a;
	t_a				*min_a;
	t_a				*max_b;
	t_a				*min_b;
}					t_ps;

int					not_number(char *s);
int					sort_a(t_a *ta);
void				minmax(t_ps *ps, t_a *ta);
int					if_sort(t_a *ta);
void				ft_beauty(t_ps *ps, t_a *ta, int i);
int					get_next_line(const int fd, char **line);
void				sa(t_ps *ps, t_a *ta, int i);
void				sb(t_ps *ps, t_a *ta, int i);
void				pa(t_ps *ps, t_a *ta, int i);
void				pb(t_ps *ps, t_a *ta, int i);
void				ra(t_ps *ps, t_a *ta, int i);
void				rb(t_ps *ps, t_a *ta, int i);
void				rra(t_ps *ps, t_a *ta, int i);
void				rrb(t_ps *ps, t_a *ta, int i);
void				rrr(t_ps *ps, t_a *ta, int i);
void				rr(t_ps *ps, t_a *ta, int i);
void				ss(t_ps *ps, t_a *ta, int i);
void				lst_free(t_ps *ps, t_a *ta);
t_a					*recorder(char **s, t_a *ta, t_ps *ps, int i);
t_ps				*ps_list();
t_a					*ta_list();
t_stack				*ft_stack(t_a *ta);

#endif
