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
