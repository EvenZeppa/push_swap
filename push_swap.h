#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

// Structure for a stack
typedef struct	s_stack
{
	int	*data;
	int	top;
	int	size;
}	t_stack;

// Structure for operations
typedef struct	s_operations
{
	char	**ops;
	int		count;
	int		capacity;
}	t_operations;

// Structure for push_swap
typedef struct	s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	int				*sorted;
	t_operations	ops;
}	t_push_swap;

// Push_swap functions
void	print_ps(t_push_swap *ps);

// Stack functions
t_stack	*create_stack(int size);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, int nb);
int		pop(t_stack *stack);
void	flood_stack(t_stack *stack, int *data, int size);
void	print_stack(t_stack *stack);

// Operations functions
void	init_operations(t_operations *ops);
void	add_operation(t_operations *ops, char *op);
void	pop_operation(t_operations *ops);
void	free_operations(t_operations *ops);
void	print_operations(t_operations *ops);
void	print_operation_recurence(t_operations *ops);


// Stack operations
void	sa(t_push_swap *ps);
void	sb(t_push_swap *ps);
void	ss(t_push_swap *ps);
void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);
void	ra(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	rr(t_push_swap *ps);
void	rra(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	rrr(t_push_swap *ps);

#endif
