#include "push_swap.h"

static void		op_clr(t_a *ta)
{
	ta->op_b = 0;
	free(ta->oper);
	ta->oper = ft_strnew(1);
}

static void		op_write(t_a *ta, char *s, int i)
{
	int			l;
	char		*str;

	l = i;
	while (l > 0)
	{
		str = ta->oper;
		ta->oper = ft_strjoin(ta->oper, s);
		free(str);
		l--;
	}
}

static void		hard_oper(t_a *ta, t_ps *ps, t_st *st)
{
	t_a			*tmp;
	
	tmp = ta;
	minmax(ps, ta);
	st_reboot(st);
	if (ps->max_a->a <= tmp->b)
	{
		if (ps->max_a->an < ps->a_l / 2)
		{
			ta->op_b += ps->max_a->an + 1;
			op_write(ta, " rra", ps->max_a->an);
			op_write(ta, " pa", 1);
		}
		else
		{
			ta->op_b += ps->a_l - ps->max_a->an + 1;
			op_write(ta, " ra", ps->a_l - ps->max_a->an);
			op_write(ta, " pa", 1);
		}
	}
	else
	{
		st_reboot(st);
		tmp = st->end_a;
		while (tmp && !(tmp->a >= ta->b && ta->b >= ((tmp->next != NULL) ? (tmp->next->a) : (st->begin->a))))
			tmp = tmp->prev;
		if (ps->a_l / 2 > tmp->an)
		{
			op_write(ta, " rra", tmp->an - 1);
			op_write(ta, " pa", 1);
			ta->op_b += tmp->an + 1;
		}
		else 
		{
			op_write(ta, " ra", ps->a_l - tmp->an);
			op_write(ta, " pa", 1);
			ta->op_b += ps->a_l - tmp->an + 1;
		}
	}
}

static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*ta;

	ta = st->begin;
	st_reboot(st);
	if (ps->b_l / 2 <= tmp->bn)
	{
		tmp->op_b = ps->b_l - tmp->bn;
		op_write(tmp, " rb", ps->b_l - tmp->bn);
	}
	else
	{
		tmp->op_b = tmp->bn + 1;
		op_write(tmp, " rrb", tmp->bn + 1);
	}
	minmax(ps, ta);
	if (tmp->b <= st->end_a->a && ta->a >= tmp->b)
	{
		tmp->op_b++;
		op_write(tmp, " pa", 1);
	}
	else
		hard_oper(tmp, ps, st);
}

void			operations(t_a *ta, t_ps *ps)
{
	t_st		*st;
	t_a			*temp;

	st = ft_stack(ta);
	temp = st->end_b;
	minmax(ps, ta);
	while (temp != NULL && temp->bn != 0)
	{
		st_reboot(st);
		op_clr(temp);
		oper_give(temp, ps, st);
		temp = temp->prev;
	}
	free(st);
}
