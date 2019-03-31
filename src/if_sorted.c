#include "push_swap.h"

int			if_sort(int *a)
{
	int		i;

	i = 0;
	while (a[i])
	{
		if (i > 0 && a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}