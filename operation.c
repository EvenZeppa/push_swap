#include "push_swap.h"

void	add_op(t_push_swap *ps, t_operation op)
{
	if (!ps->ops || ps->op_count == ps->op_capacity)
	{
		ps->op_capacity *= 2;
		ps->ops = ft_realloc(ps->ops, ps->op_capacity * sizeof(int));
	}

	ps->ops[ps->op_count] = op;
	ps->op_count++;
}

void	pop_op(t_push_swap *ps)
{
	if (ps->op_count > 0)
		ps->op_count--;
}

void	sa(t_push_swap *ps)
{
	swap(ps->a);
	add_op(ps, OP_SA);
}

void	sb(t_push_swap *ps)
{
	swap(ps->b);
	add_op(ps, OP_SB);
}

void	ss(t_push_swap *ps)
{
	swap(ps->a);
	swap(ps->b);
	add_op(ps, OP_SS);
}

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