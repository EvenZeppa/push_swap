#include "push_swap.h"

t_elem	*find_next_elem(t_stack *stack, int value)
{
	t_elem	*elem;
	t_elem	*next;

	if (!stack->top)
		return (NULL);
	elem = stack->top;
	next = NULL;
	while (elem)
	{
		if ((!next && elem->value > value)
			|| (next && next->value > elem->value && elem->value > value))
			next = elem;
		elem = elem->prev;
		if (next && next->value == elem->value)
			break ;
	}
	return (next);
}

int	itterate_prev_to_elem(t_stack *stack, t_elem *elem)
{
	t_elem	*curr;
	int		i;

	curr = stack->top;
	i = 0;
	while (curr)
	{
		if (curr == elem)
			return (i);
		curr = curr->prev;
		i++;
	}
	return (-1);
}

int	itterate_next_to_elem(t_stack *stack, t_elem *elem)
{
	t_elem	*curr;
	int		i;

	curr = stack->top;
	i = 0;
	while (curr)
	{
		if (curr == elem)
			return (i);
		curr = curr->next;
		i++;
	}
	return (-1);
}
