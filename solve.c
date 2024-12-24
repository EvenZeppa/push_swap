#include "push_swap.h"

void	qsort_ps_a(t_push_swap *ps, int pivot)
{
	while (ps->a->top > ps->size - pivot)
	{
		if (ps->a->data[ps->a->top] < pivot)
			pb(ps);
		else
			ra(ps);
	}
}

void	qsort_ps_b(t_push_swap *ps, int pivot)
{
	while (ps->b->top > pivot)
	{
		if (ps->b->data[ps->b->top] > pivot)
			pa(ps);
		else
			rb(ps);
	}
}