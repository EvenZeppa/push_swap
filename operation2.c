/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:37 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:37 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	add_op(ps, OP_RRA);
}

void	rrb(t_push_swap *ps)
{
	reverse_rotate(ps->b);
	add_op(ps, OP_RRB);
}

void	rrr(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	add_op(ps, OP_RRR);
}
