#include "push_swap.h"

// Swaps the top two elements of stack A
void	sa(t_push_swap *ps)
{
	int	tmp;

	if (ps->a->top > 0)
	{
		tmp = ps->a->data[ps->a->top];
		ps->a->data[ps->a->top] = ps->a->data[ps->a->top - 1];
		ps->a->data[ps->a->top - 1] = tmp;
		add_operation(&ps->ops, "sa");
	}
}

// Swaps the top two elements of stack B
void	sb(t_push_swap *ps)
{
	int	tmp;

	if (ps->b->top > 0)
	{
		tmp = ps->b->data[ps->b->top];
		ps->b->data[ps->b->top] = ps->b->data[ps->b->top - 1];
		ps->b->data[ps->b->top - 1] = tmp;
		add_operation(&ps->ops, "sb");
	}
}

// Swaps the top two elements of both stacks A and B
void	ss(t_push_swap *ps)
{
	sa(ps);
	sb(ps);
	pop_operation(&ps->ops);
	pop_operation(&ps->ops);
	add_operation(&ps->ops, "ss");
}

// Pushes the top element of stack B onto stack A
void	pa(t_push_swap *ps)
{
	if (ps->b->top >= 0)
	{
		push(ps->a, pop(ps->b));
		add_operation(&ps->ops, "pa");
	}
}

// Pushes the top element of stack A onto stack B
void	pb(t_push_swap *ps)
{
	if (ps->a->top >= 0)
	{
		push(ps->b, pop(ps->a));
		add_operation(&ps->ops, "pb");
	}
}

// Rotates stack A upwards
void	ra(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->a->top > 0)
	{
		tmp = ps->a->data[ps->a->top];
		i = ps->a->top;
		while (i > 0)
		{
			ps->a->data[i] = ps->a->data[i - 1];
			i--;
		}
		ps->a->data[i] = tmp;
		add_operation(&ps->ops, "ra");
	}
}

// Rotates stack B upwards
void	rb(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->b->top > 0)
	{
		tmp = ps->b->data[ps->b->top];
		i = ps->b->top;
		while (i > 0)
		{
			ps->b->data[i] = ps->b->data[i - 1];
			i--;
		}
		ps->b->data[i] = tmp;
		add_operation(&ps->ops, "rb");
	}
}

// Rotates both stacks A and B upwards
void	rr(t_push_swap *ps)
{
	ra(ps);
	rb(ps);
	pop_operation(&ps->ops);
	pop_operation(&ps->ops);
	add_operation(&ps->ops, "rr");
}

// Rotates stack A downwards
void	rra(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->a->top > 0)
	{
		tmp = ps->a->data[0];
		i = 0;
		while (i < ps->a->top)
		{
			ps->a->data[i] = ps->a->data[i + 1];
			i++;
		}
		ps->a->data[i] = tmp;
		add_operation(&ps->ops, "rra");
	}
}

// Rotates stack B downwards
void	rrb(t_push_swap *ps)
{
	int	tmp;
	int	i;

	if (ps->b->top > 0)
	{
		tmp = ps->b->data[0];
		i = 0;
		while (i < ps->b->top)
		{
			ps->b->data[i] = ps->b->data[i + 1];
			i++;
		}
		ps->b->data[i] = tmp;
		add_operation(&ps->ops, "rrb");
	}
}

// Rotates both stacks A and B downwards
void	rrr(t_push_swap *ps)
{
	rra(ps);
	rrb(ps);
	pop_operation(&ps->ops);
	pop_operation(&ps->ops);
	add_operation(&ps->ops, "rrr");
}