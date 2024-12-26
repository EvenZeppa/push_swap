#include "push_swap.h"

// Creates a stack
t_stack	*create_stack()
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->min = NULL;
	stack->max = NULL;
	stack->size = 0;
	return (stack);
}

// Frees the memory allocated for the stack and its elements
void	free_stack(t_stack *stack)
{
	t_elem	*elem;
	t_elem	*next;

	elem = stack->top;
	while (elem)
	{
		next = elem->next;
		free_elem(elem);
		elem = next;
	}
	free(stack);
}

// Fills the stack with the given data
void	flood_stack(t_stack *stack, int *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push(stack, create_elem(data[i]));
		i++;
	}
}

// Pops an element from the stack
t_elem	*pop(t_stack *stack)
{
	t_elem	*elem;

	if (!stack->top)
		return (NULL);
	elem = stack->top;
	stack->top = elem->prev;
	unlink_elem(elem);

	if (elem == stack->min)
		stack->min = find_min_elem(stack);
	if (elem == stack->max)
		stack->max = find_max_elem(stack);

	stack->size--;
	return (elem);
}

// Pushes an element onto the stack
void	push(t_stack *stack, t_elem *elem)
{
	if (!stack || !elem)
		return ;
	if (!stack->top)
		stack->top = elem;
	else
	{
		link_elem(stack->top, elem);
		stack->top = elem;
	}

	if (!stack->min || elem->value < stack->min->value)
		stack->min = elem;
	if (!stack->max || elem->value > stack->max->value)
		stack->max = elem;

	stack->size++;
}

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

t_elem	*find_prev_elem(t_stack *stack, int value)
{
	t_elem	*elem;
	t_elem	*prev;

	if (!stack->top)
		return (NULL);
	elem = stack->top;
	prev = NULL;
	while (elem)
	{
		if ((!prev && elem->value < value) || (prev && prev->value < elem->value && elem->value < value))
			prev = elem;
		elem = elem->prev;
		if (prev && prev->value == elem->value)
			break ;
	}
	return (prev);
}

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
		if ((!next && elem->value > value) || (next && next->value > elem->value && elem->value > value))
			next = elem;
		elem = elem->prev;
		if (next && next->value == elem->value)
			break ;
	}
	return (next);
}

t_elem	*find_prev_by_index(t_stack *stack, int index)
{
	t_elem	*elem;
	int		i;

	elem = stack->top;
	i = 0;
	while (elem && i <= index)
	{
		if (i == index)
			return (elem);
		elem = elem->prev;
		i++;
	}
	return (elem);
}

t_elem	*find_next_by_index(t_stack *stack, int index)
{
	t_elem	*elem;
	int		i;

	elem = stack->top;
	i = 0;
	while (elem && i <= index)
	{
		if (i == index)
			return (elem);
		elem = elem->next;
		i++;
	}
	return (elem);
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

// // Compares the min element value of the stack with the given value
// int	min_stack_cmp(t_stack *stack, int value)
// {
// 	return (value == stack->min->value);
// }

// // Compares the max element value of the stack with the given value
// int	max_stack_cmp(t_stack *stack, int value)
// {
// 	return (value == stack->max->value);
// }

// // Iterates to prev through the stack to find the index of the first element that satisfies the given comparison function
// int	iterate_to_prev_cmp(t_stack *stack, int (*cmp)(t_stack*, int))
// {
// 	t_elem	*elem;
// 	int		i;

// 	elem = stack->top;
// 	i = 0;
// 	while (elem)
// 	{
// 		if (cmp(stack, elem->value))
// 			return (i);
// 		elem = elem->prev;
// 		i++;
// 	}
// 	return (-1);
// }

// // Iterates to next through the stack to find the index of the first element that satisfies the given comparison function
// int	iterate_to_next_cmp(t_stack *stack, int (*cmp)(t_stack*, int))
// {
// 	t_elem	*elem;
// 	int		i;

// 	elem = stack->top;
// 	i = 0;
// 	while (elem)
// 	{
// 		if (cmp(stack, elem->value))
// 			return (i);
// 		elem = elem->next;
// 		i++;
// 	}
// 	return (-1);
// }

// // Iterates through the stack to find the first element that satisfies the given comparison function
// t_elem	*get_by_cmp(t_stack *stack, int (*cmp)(t_stack*, int))
// {
// 	t_elem *elem;

// 	elem = stack->top;
// 	while (elem)
// 	{
// 		if (cmp(stack, elem->value))
// 			return (elem);
// 		elem = elem->prev;
// 	}
// 	return (NULL);
// }
