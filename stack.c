#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(sizeof(int) * size);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->top = -1;
	stack->size = size;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

void	push(t_stack *stack, int nb)
{
	if (stack->top < stack->size)
		stack->data[++stack->top] = nb;
}

int		pop(t_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->data[stack->top--]);
}

void	flood_stack(t_stack *stack, int *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push(stack, data[i]);
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("%d\n", stack->data[i]);
		i--;
	}
}