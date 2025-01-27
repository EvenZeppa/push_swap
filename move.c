/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:27 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:27 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move_r(t_push_swap *ps, t_move *bm)
{
	while (bm->ra > 0 || bm->rb > 0)
	{
		if (bm->ra > 0 && bm->rb > 0)
		{
			rr(ps);
			bm->ra--;
			bm->rb--;
		}
		else if (bm->ra > 0)
		{
			ra(ps);
			bm->ra--;
		}
		else
		{
			rb(ps);
			bm->rb--;
		}
	}
}

void	do_move_rr(t_push_swap *ps, t_move *bm)
{
	while (bm->rra > 0 || bm->rrb > 0)
	{
		if (bm->rra > 0 && bm->rrb > 0)
		{
			rrr(ps);
			bm->rra--;
			bm->rrb--;
		}
		else if (bm->rra > 0)
		{
			rra(ps);
			bm->rra--;
		}
		else
		{
			rrb(ps);
			bm->rrb--;
		}
	}
}

void	move_elem_r(t_push_swap *ps, t_elem *elem, t_move *move)
{
	t_move	tmp;
	t_elem	*tmp_elem;

	tmp.rrb = 0;
	tmp.rra = 0;
	tmp.rb = itterate_prev_to_elem(ps->b, elem);
	if (elem->value > ps->a->max->value || elem->value < ps->a->min->value)
		tmp_elem = ps->a->min;
	else
		tmp_elem = find_next_elem(ps->a, elem->value);
	tmp.ra = itterate_prev_to_elem(ps->a, tmp_elem);
	if (tmp.rb > tmp.ra)
		tmp.count = tmp.rb;
	else
		tmp.count = tmp.ra;
	if (tmp.rb + itterate_next_to_elem(ps->a, tmp_elem) < tmp.count)
	{
		tmp.rra = itterate_next_to_elem(ps->a, tmp_elem);
		tmp.count = tmp.rb + tmp.rra;
		tmp.ra = 0;
	}
	if (move->count == -1 || tmp.count < move->count)
		*move = tmp;
}

void	move_elem_rr(t_push_swap *ps, t_elem *elem, t_move *move)
{
	t_move	tmp;
	t_elem	*tmp_elem;

	tmp.rb = 0;
	tmp.ra = 0;
	tmp.rrb = itterate_next_to_elem(ps->b, elem);
	if (elem->value > ps->a->max->value || elem->value < ps->a->min->value)
		tmp_elem = ps->a->min;
	else
		tmp_elem = find_next_elem(ps->a, elem->value);
	tmp.rra = itterate_next_to_elem(ps->a, tmp_elem);
	if (tmp.rrb > tmp.rra)
		tmp.count = tmp.rrb;
	else
		tmp.count = tmp.rra;
	if (tmp.rrb + itterate_prev_to_elem(ps->a, tmp_elem) < tmp.count)
	{
		tmp.ra = itterate_prev_to_elem(ps->a, tmp_elem);
		tmp.count = tmp.rrb + tmp.ra;
		tmp.rra = 0;
	}
	if (move->count == -1 || tmp.count < move->count)
		*move = tmp;
}
