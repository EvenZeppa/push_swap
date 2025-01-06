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
