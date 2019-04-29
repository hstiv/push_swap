#include "push_swap.h"

static void		op_clr(char *oper,int *l)
{
	int			i;

	*l = 0;
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

static void		hard_oper(t_a *ta, t_ps *ps, t_st *st)
{
	t_a			*tmp;
	
	tmp = ta;
	minmax(ps, ta);
	if (ps->max_a->a <= tmp->b)
	{
		if (ps->max_a->an <= ps->a_l / 2)
		{
			ta->op_b += ps->max_a->an + 2;
			op_write(ta->oper, " rra", ps->max_a->an);
			op_write(ta->oper, " pa", 1);
			op_write(ta->oper, "ra", 1);
		}
		else
		{
			ta->op_b += ps->a_l - ps->max_a->an + 1;
			op_write(ta->oper, " ra", ps->a_l - ps->max_a->an);
			op_write(ta->oper, " pa", 1);
		}
	}
	else
	{
		tmp = st->end_a;
		while (tmp->prev && !(tmp->a < ta->b && ta->b > st->begin->a))
		{
			ta->op_b++;
			op_write(ta->oper, " ra", 1);
			tmp = tmp->prev;
			st_reboot(st);
		}
		op_write(ta->oper, " pa", 1);
		op_write(ta->oper, " ra", 1);
	}
}

static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*ta;

	ta = st->begin;
	if (ps->b_l / 2 <= tmp->bn)
	{
		tmp->op_b = ps->b_l - tmp->bn;
		op_write(tmp->oper, " rb", ps->b_l - tmp->bn);
	}
	else
	{
		tmp->op_b = tmp->bn + 1;
		op_write(tmp->oper, " rrb", tmp->bn + 1);
	}
	minmax(ps, ta);
	if (tmp->b <= st->end_a->a && st->begin->a > tmp->b)
	{
		tmp->op_b++;
		op_write(tmp->oper, " pa", 1);
	}
	else
		hard_oper(tmp, ps, st);
}

void			operations(t_a *ta, t_ps *ps)
{
	t_st		*st;
	t_a			*temp;

	st = ft_stack(ta);
	st_reboot(st);
	temp = st->end_b;
	minmax(ps, ta);
	while (temp != NULL && temp->bn != 0)
	{
		st_reboot(st);
		op_clr(temp->oper, &(temp->op_b));
		oper_give(temp, ps, st);
		temp = temp->prev;
	}
	free(st);
}
