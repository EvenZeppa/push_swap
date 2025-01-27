/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 16:43:51 by ezeppa            #+#    #+#             */
/*   Updated: 2025-01-27 16:43:51 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a stack
t_stack	*create_stack(void)
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
	while (--size >= 0)
		push(stack, create_elem(data[size]));
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
