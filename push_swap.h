#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include "libft.h"

typedef enum e_metrics
{
	ME_END,
	ME_PS,
	ME_SORTED,
	ME_CMP,
	ME_OPS,
	ME_OP_OCCS,
	ME_OP_COUNT
}	t_metrics;

typedef enum e_to_stack
{
	TO_A,
	TO_B
}	t_to_stack;

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
	int				size;
	int				*sorted;
	int				*cmp;
	t_operations	ops;
}	t_push_swap;

// Push_swap functions
void	init_push_swap(t_push_swap *ps, int *stack, int size);
void	free_push_swap(t_push_swap *ps);
void	update_cmp(t_push_swap *ps);
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

// Int tab utils functions
void	rev_int_tab(int *tab, int size);
int		*cmp_int_tab(int *tab1, int *tab2, int size);
void	ft_qsort_int(int **tab, int size);
void	print_int_tab(int *tab, int size);
int		is_int_tab_zero(int *tab, int size);

// Metrics functions
void	breakpoint(t_push_swap *ps, ...);

// Solver functions
// void	qsort_ps_sup(t_push_swap *ps, t_to_stack to_stack, int pivot, int in_stack_size);
// void	qsort_ps_inf(t_push_swap *ps, t_to_stack to_stack, int pivot, int in_stack_size);	
void	qsort_ps_a(t_push_swap *ps, int pivot);
void	qsort_ps_b(t_push_swap *ps, int pivot);

#endif
