#include "push_swap.h"

t_ps        ps_list(void)
{
    t_ps	*ps;

	ps = malloc(sizeof(t_ps));
	if (ps)
	{
    	ps->a = 0;
    	ps->b = 0;
    	ps->a_len = 0;
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