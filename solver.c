#include "push_swap.h"

void	ps_qsort(t_push_swap *ps)
{
	int	median_a;
	int	median_b;
	int	s_size;

	median_a = (ps->a->min->value + ps->a->max->value) / 2;
	median_b = ps->a->min->value + (median_a - ps->a->min->value) / 2;
	s_size = ps->a->size / 2;
	while (ps->a->size > s_size)
	{
		if (ps->a->top->value > median_a)
		{
			if (ps->b->top && ps->b->top->value < median_b)
				rr(ps);
			else
				ra(ps);
		}
		else
		{
			if (ps->b->top && ps->b->top->value < median_b)
				rb(ps);
			pb(ps);
		}
	}
}

void	ps_turkish_sort(t_push_swap *ps)
{
	t_move	bm;
	t_move	tmp_m;
	t_elem	*current;

	while (ps->b->size)
	{
		bm.count = -1;
		move_elem_r(ps, ps->b->top, &bm);
		move_elem_rr(ps, ps->b->top, &bm);
		current = ps->b->top->next;
		while (current && current != ps->b->top)
		{
			tmp_m.count = -1;
			move_elem_r(ps, current, &tmp_m);
			move_elem_rr(ps, current, &tmp_m);
			if (tmp_m.count < bm.count)
				bm = tmp_m;
			current = current->next;
		}
		do_move_r(ps, &bm);
		do_move_rr(ps, &bm);
		pa(ps);
	}
}

void	solve(t_push_swap *ps)
{
	while (ps->a->size > 2)
		ps_qsort(ps);
	ps_turkish_sort(ps);
	if (ps->a->top->value > ps->a->size / 2)
		while (ps->a->top != ps->a->min)
			ra(ps);
	else
		while (ps->a->top != ps->a->min)
			rra(ps);
}
