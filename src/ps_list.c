#include "push_swap.h"

t_ps        *ps_list(int c)
{
    t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (ps)
	{
    	int		ps->a[c];
    	int		ps->b[c];

    	ps->a_len = c;
		ps->b_len = 0;
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
