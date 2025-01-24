#include "push_swap.h"

void	add_op(t_push_swap *ps, t_operation op)
{
	if (!ps->ops || ps->op_count >= ps->op_capacity - 1)
	{
		ps->op_capacity *= 2;
		ps->ops = (int *)ft_realloc(ps->ops, ps->op_capacity / 2, ps->op_capacity * sizeof(int));
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
