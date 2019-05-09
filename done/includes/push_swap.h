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
# define ABS(x) (x > 0 ? x : -x)

# include "libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 3

typedef struct		s_a
{
	int				a;
	int				an;
	int				bn;
	int				b;
	int				num_a;
	int				op_b;
	int				num_b;
	char			*oper;
	char			*ra_oper;
	char			*rra_oper;
	char			*rb_oper;
	char			*rrb_oper;
	struct s_a		*next;
	struct s_a		*prev;
}					t_a;

typedef	struct		s_st
{
	t_a				*begin;
	t_a				*end_a;
	t_a				*end_b;
}					t_st;

typedef struct		s_ps
{
	int				a_l;
	int				b_l;
	int				len;
	int				i;
	int				v;
	int				c;
	int				s;
	t_a				*max_a;
	t_a				*min_a;
	t_a				*max_b;
	t_a				*min_b;
}					t_ps;

int					val_arg(char **s, int i);
void				next_lst(t_a *tmp);
void				red();
void				blue();
void				green();
void				reset();
int					flag_check(int *i, t_ps *ps, int l);
void				ft_dellast(t_a *ta);
void				sort_three(t_a *ta, t_ps *ps);
t_a					*min_oper(t_ps *ps, t_a *ta);
void				op_clr(t_a *ta);
void				op_write(t_a *ta, char *s, int i);
int					check_all(t_a *ta);
void				operations(t_a *ta, t_ps *ps);
void				numgive(t_ps *ps, t_a *ta);
int					median(t_a *ta, t_ps *ps);
void				rev_rotater(t_st *st, t_ps *ps, t_a *ta);
void				rotater(t_st *st, t_ps *ps, t_a *ta);
void				swapper(t_st *st, t_ps *ps, t_a *ta);
int					not_number(char *s);
int					sort_b(t_a *ta);
int					sort_a(t_a *ta);
void				minmax(t_ps *ps, t_a *ta);
int					if_sort(t_a *ta);
void				ft_beauty(t_ps *ps, t_a *ta);
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
t_st				*ft_stack(t_a *ta);
void				st_reboot(t_st *st);

#endif
