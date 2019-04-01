#include "push_swap.h"

static void			ft_malloc_maker(t_ps *ps, char *s)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i + 1] == ' ' && s[i] != ' ')
			ps->a_l++;
		i++;
	}
	i = ps->a_l;
	ps->a = (int *)malloc(sizeof(int) * (ps->a_l + 1));
	ps->b = (int *)malloc(sizeof(int) * (ps->a_l + 1));
	while (i >= 0)
	{
		ps->b[i] = 0;
		i--;
	}
}

t_ps        *ps_list(char *s)
{
    t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (ps)
	{
		ft_malloc_maker(ps, s);
		ps->b_l = 0;
		ps->len = 0;
		ps->max_a = 0;
		ps->min_a = 0;
		ps->max_b = 0;
		ps->min_b = 0;
		ps->flotx = 0;
		ps->flotn = 0;
	}
	return (ps);
}
