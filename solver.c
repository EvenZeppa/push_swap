/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:46 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:46 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ps_sort_3(t_push_swap *ps)
{
	if (ps->a->top->value < ps->a->top->prev->value
		&& ps->a->top->prev->prev->value > ps->a->top->value
		&& ps->a->top->prev->value > ps->a->top->prev->prev->value)
	{
		sa(ps);
		ra(ps);
	}
	else if (ps->a->top->value > ps->a->top->prev->value
		&& ps->a->top->prev->prev->value < ps->a->top->value
		&& ps->a->top->prev->value > ps->a->top->prev->prev->value)
	{
		ra(ps);
		sa(ps);
	}
	else if (ps->a->top->value < ps->a->top->prev->value
		&& ps->a->top->prev->prev->value < ps->a->top->prev->value)
		rra(ps);
	else if (ps->a->top->value > ps->a->top->prev->prev->value
		&& ps->a->top->value > ps->a->top->prev->value)
		ra(ps);
	else if (ps->a->top->value > ps->a->top->prev->value
		&& ps->a->top->value < ps->a->top->prev->prev->value)
		sa(ps);
}

void	ps_sort_4(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i != 1)
	{
		if (ps->a->top->value == 1)
		{
			pb(ps);
			i++;
		}
		else
			ra(ps);
	}
	ps_sort_3(ps);
	pa(ps);
}

void	ps_sort_5(t_push_swap *ps)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		if (ps->a->top->value == 1
			|| ps->a->top->value == 2)
		{
			pb(ps);
			i++;
		}
		else
			ra(ps);
	}
	ps_sort_3(ps);
	pa(ps);
	pa(ps);
	if (ps->a->top->value > ps->a->top->prev->value)
		sa(ps);
}
