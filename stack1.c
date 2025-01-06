#include "push_swap.h"

// Swaps the top two elements of the stack
void	swap(t_stack *stack)
{
	t_elem	*elem1;
	t_elem	*elem2;

	if (!stack->top || !stack->top->prev)
		return ;
	elem1 = pop(stack);
	elem2 = pop(stack);
	push(stack, elem1);
	push(stack, elem2);
}

// Rotates the stack
void	rotate(t_stack *stack)
{
	if (!stack->top || !stack->top->prev)
		return ;
	stack->top = stack->top->prev;
}

// Reverses the rotation of the stack
void	reverse_rotate(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	stack->top = stack->top->next;
}

// Finds the minimum element of the stack
t_elem	*find_min_elem(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*min;

	elem = stack->top;
	min = elem;
	while (elem && elem->prev)
	{
		if (elem->value < min->value)
			min = elem;
		elem = elem->prev;
		if (min->value == elem->value)
			break ;
	}
	return (min);
}

// Finds the maximum element of the stack
t_elem	*find_max_elem(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*max;

	elem = stack->top;
	max = elem;
	while (elem && elem->prev)
	{
		if (elem->value > max->value)
			max = elem;
		elem = elem->prev;
		if (max->value == elem->value)
			break ;
	}
	return (max);
}
