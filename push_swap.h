#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_operation;

typedef enum e_metric
{
	ME_END,
	ME_PS,
	ME_OPS,
	ME_OP_COUNT,
	ME_OP_OCCS
}	t_metric;

typedef struct s_elem
{
	int				value;
	struct s_elem	*prev;
	struct s_elem	*next;
}	t_elem;

typedef struct s_stack
{
	t_elem	*top;
	t_elem	*min;
	t_elem	*max;
	int	size;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;

	int		*ops;
	int		op_count;
	int		op_capacity;
}	t_push_swap;

// Elem Functions
t_elem	*create_elem(int value);
void	free_elem(t_elem *elem);
void	link_elem(t_elem *elem1, t_elem *elem2);
void	unlink_elem(t_elem *elem);

// Stack Functions
t_stack	*create_stack();
void	free_stack(t_stack *stack);
void	flood_stack(t_stack *stack, int *data, int size);
t_elem	*pop(t_stack *stack);
void	push(t_stack *stack, t_elem *elem);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// Operations Functions
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

// Metrics Functions
void	print_ps(t_push_swap *ps);
void	breakpoint(t_push_swap *ps, ...);

#endif