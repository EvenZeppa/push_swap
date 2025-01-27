/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:32 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:32 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *ps)
{
	push(ps->a, pop(ps->b));
	add_op(ps, OP_PA);
}

void	pb(t_push_swap *ps)
{
	push(ps->b, pop(ps->a));
	add_op(ps, OP_PB);
}

void	ra(t_push_swap *ps)
{
	rotate(ps->a);
	add_op(ps, OP_RA);
}

void	rb(t_push_swap *ps)
{
	rotate(ps->b);
	add_op(ps, OP_RB);
}

void	rr(t_push_swap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	add_op(ps, OP_RR);
}
