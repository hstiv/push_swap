#include "push_swap.h"

static void		op_clr(char *oper)
{
	int			i;

	i = 7000;
	while (i)
		oper[i--] = 0;
}

static void		op_write(char *oper, char *s, int i)
{
	int			l;

	l = i;
	while (l > 0)
	{
		ft_strcat(oper, s);
		l--;
	}
}

static void		hard_oper(t_a *ta, t_ps *ps, t_st *st, int *i)
{
	t_a			*tmp;
	
	tmp = ta;
	if (ps->max_a->a <= tmp->b)
	{
		*i += 2;
		op_write(ta->oper, " pa", 1);
		op_write(ta->oper, " ra", 1);
	}
	else
	{
		tmp = st->end_a;
		while (tmp->prev && tmp->a < ta->b)
		{
			(*i)++;
			op_write(ta->oper, " ra", 1);
			tmp = tmp->prev;
		}

	}
}

static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	int			i;
	t_a			*ta;

	i = 0;
	ta = st->begin;
	if (ps->b_l / 2 <= tmp->bn)
	{
		i = ps->a_l - tmp->bn;
		op_write(tmp->oper, " ra", i);
	}
	else
	{
		i = tmp->bn + 1;
		op_write(tmp->oper, " rra", i);
	}
	minmax(ps, ta);
	if (tmp->b <= st->end_a->a)
	{
		i++;
		op_write(tmp->oper, " pa", 1);
	}
	else
		hard_oper(tmp, ps, st, &i);
	tmp->op_b = i;
}

void			operations(t_a *ta, t_ps *ps)
{
	t_st		*st;
	t_a			*temp;

	st = ft_stack(ta);
	temp = st->end_b;
	st_reboot(st);
	minmax(ps, ta);
	while (temp->prev && !temp->op_b)
	{
		st_reboot(st);
		op_clr(temp->oper);
		oper_give(temp, ps, st);
		temp = temp->prev;
	}
	free(st);
}
