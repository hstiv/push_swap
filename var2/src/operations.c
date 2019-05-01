#include "push_swap.h"

static void		op_clr(t_a *ta)
{
	int			i;

	i = 0;
	ta->op_b = 0;
	while (i < 7000)
		ta->oper[i++] = 0;
}

static void		op_write(t_a *ta, char *s, int i)
{
	int			l;

	l = i;
	while (l > 0)
	{
		ta->oper = ft_strcat(ta->oper, s);
		l--;
	}
}

static void		hard_oper(t_a *ta, t_ps *ps, t_st *st)
{
	t_a			*tmp;
	
	tmp = ta;
	minmax(ps, ta);
	st_reboot(st);
	if (ps->max_a->a < ta->b)
	{
		if ((ps->max_a->an * 2) <= ps->a_l)
		{
			ta->op_b = ta->op_b + ps->max_a->an + 1;
			op_write(ta, " rra", ps->max_a->an);
			op_write(ta, " pa", 1);
		}
		else
		{
			ta->op_b = ta->op_b + (ps->a_l - ps->max_a->an) + 1;
			op_write(ta, " ra", ps->a_l - ps->max_a->an);
			op_write(ta, " pa", 1);
		}
	}
	else if (ps->min_a->a > ta->b)
	{
		if ((ps->min_a->an * 2) <= ps->a_l)
		{
			ta->op_b = ta->op_b + ps->min_a->an + 1;
			op_write(ta, " rra", ps->min_a->an);
			op_write(ta, " pa", 1);
		}
		else
		{
			ta->op_b = ta->op_b + (ps->a_l - ps->min_a->an) + 1;
			op_write(ta, " ra", ps->a_l - ps->min_a->an - 1);
			op_write(ta, " pa", 1);
		}
	}
	else
	{
		tmp = st->end_a;
		while (tmp && !(tmp->a > ta->b && ta->b > ((tmp->next != NULL) ? (tmp->next->a) : (st->begin->a))))
			tmp = tmp->prev;
		if (ps->a_l >= tmp->an * 2)
		{
			op_write(ta, " rra", tmp->an);
			op_write(ta, " pa", 1);
			ta->op_b = ta->op_b + tmp->an + 1;
		}
		else 
		{
			op_write(ta, " ra", ps->a_l - tmp->an);
			op_write(ta, " pa", 1);
			ta->op_b = ta->op_b + (ps->a_l - tmp->an) + 1;
		}
	}
}

static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*ta;

	ta = st->begin;
	st_reboot(st);
	if (ps->b_l < tmp->bn * 2)
	{
		tmp->op_b = ps->b_l - tmp->bn;
		op_write(tmp, " rb", (ps->b_l - tmp->bn));
	}
	else
	{
		tmp->op_b = tmp->bn + 1;
		op_write(tmp, " rrb", tmp->bn + 1);
	}
	st_reboot(st);
	ta = st->begin;
	if (tmp->b < st->end_a->a && ta->a < tmp->b)
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
