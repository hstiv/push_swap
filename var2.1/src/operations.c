#include "push_swap.h"

static int		cond(t_a *ta, t_a *temp, t_st *st)
{
	if (temp->next != NULL && temp->next->an)
	{
		if (temp->a > ta->b && ta->b > temp->next->a)
			return (1);
	}
	st_reboot(st);
	if (temp->next == NULL)
	{
		if (temp->a > ta->b && ta->b > st->begin->a && st->begin->an == 1)
			return (1);
	}
	return (0);
}

static void		op_clr(t_a *ta)
{
	int			i;

	i = 0;
	ta->op_b = 0;
	while (i < 7000)
	{
		ta->oper[i] = 0;
		i++;
	}
}

static void		op_write(t_a *ta, char *s, int i)
{
	int			l;

	l = i;
	while (l > 0)
	{
		if (ta->oper[0] != '\0')
			ft_strcat(ta->oper, " ");
		ft_strcat(ta->oper, s);
		l--;
	}
}

static void		hard_oper(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*raw;
	
	raw = tmp;
	minmax(ps, tmp);
	st_reboot(st);
	if (ps->max_a->a < tmp->b)
	{
		if ((ps->max_a->an * 2) <= ps->a_l)
		{
			tmp->op_b += ps->max_a->an + 1;
			op_write(tmp, "rra", ps->max_a->an);
			op_write(tmp, "pa", 1);
		}
		else
		{
			tmp->op_b += ps->a_l - ps->max_a->an + 1;
			op_write(tmp, "ra", ps->a_l - ps->max_a->an);
			op_write(tmp, "pa", 1);
		}
	}
	else if (ps->min_a->a > tmp->b)
	{
		if ((ps->min_a->an * 2) <= ps->a_l)
		{
			tmp->op_b += ps->min_a->an + 1;
			op_write(tmp, "rra", ps->min_a->an);
			op_write(tmp, "pa", 1);
		}
		else
		{
			tmp->op_b += ps->a_l - ps->min_a->an + 1;
			op_write(tmp, "ra", ps->a_l - ps->min_a->an);
			op_write(tmp, "pa", 1);
		}
	}
	else
	{
		raw = st->end_a;
		while (raw->prev && (cond(tmp, raw, st) == 0))
			raw = raw->prev;
		if (ps->a_l > raw->an * 2)
		{
			op_write(tmp, "rra", raw->an);
			op_write(tmp, "pa", 1);
			tmp->op_b += raw->an + 1;
		}
		else 
		{
			op_write(tmp, "ra", ps->a_l - raw->an);
			op_write(tmp, "pa", 1);
			tmp->op_b += ps->a_l - raw->an + 1;
		}
	}
}

static void		oper_give(t_a *tmp, t_ps *ps, t_st *st)
{
	t_a			*ta;

	ta = st->begin;
	st_reboot(st);
	if (ps->b_l <= tmp->bn * 2)
	{
		tmp->op_b = ps->b_l - tmp->bn;
		op_write(tmp, "rb", ps->b_l - tmp->bn);
	}
	else
	{
		tmp->op_b = tmp->bn;
		op_write(tmp, "rrb", tmp->bn);
	}
	st_reboot(st);
	if (tmp->b < st->end_a->a && tmp->b > st->begin->a)
	{
		tmp->op_b++;
		op_write(tmp, "pa", 1);
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
	while (temp != NULL)
	{
		st_reboot(st);
		op_clr(temp);
		oper_give(temp, ps, st);
//		ft_putchar(65);
//		ft_putstr("temp=");
//		ft_putnbr(temp->b);
//		ft_putchar(32);
//		ft_putstr("temp->op_b= ");
//		ft_putnbr(temp->op_b);
//		ft_putchar(32);
//		ft_putstr(temp->oper);
//		ft_putchar(65);
		temp = temp->prev;
	}
//	ft_putchar('\n');
	free(st);
}
